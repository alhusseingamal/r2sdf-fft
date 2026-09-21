`include "definitions.vh"

module sdf_stage #(parameter N = 8, parameter W = 16, parameter F = 14, parameter STAGE_INDEX = 0) (
    input clk, input reset_n, input en,

    input signed [W-1:0] in_real, 
    input signed [W-1:0] in_imag, 
    
    output reg valid_out, 
    output reg signed [W-1:0] out_real, 
    output reg signed [W-1:0] out_imag
);

localparam DEPTH = (N  >> (STAGE_INDEX+1));  // note: stages are indexed starting at 0

localparam signed [W-1:0] FP_ONE = (16'sd1 <<< F);

// Must match complex_multiplier's internal LATENCY (see complex_multiplier.v)
localparam MUL_LATENCY = 5;

reg [$clog2(DEPTH):0] counter;

// Buffer signals
wire signed [W-1:0] buffer_out_real, buffer_out_imag;

// Stage signals
wire signed [W-1:0] flush_real_s, flush_imag_s;
wire signed [W-1:0] fill_real_s, fill_imag_s;
wire select_counter_msb;    // if MSB of counter is 1, we are in Compute Mode, else we are in Fill/Flush Mode

/* verilator lint_off WIDTHEXPAND */
wire [$clog2(N/2)-1:0] rom_addr = (counter % DEPTH) << STAGE_INDEX;
/* verilator lint_on WIDTHEXPAND */


// Twiddle ROM
wire signed [W-1:0] twiddle_real_s, twiddle_imag_s;
twiddle_rom #(.W(W), .N(N)) 
stage_twiddles (
    .addr(rom_addr),
    .twiddle_real(twiddle_real_s),
    .twiddle_imag(twiddle_imag_s)
);

// Buffer Unit
circular_buffer #(.W(W), .DEPTH(DEPTH))
queue(
    .clk(clk), .reset_n(reset_n), .en(en), 
    .in_real(fill_real_s), .in_imag(fill_imag_s), 
    .out_real(buffer_out_real), .out_imag(buffer_out_imag)
);


// Butterfly Unit
wire signed [W-1:0] a_bf_real_s, a_bf_imag_s;
wire signed [W-1:0] b_bf_real_s, b_bf_imag_s;
butterfly #(.W(W), .F(F))
bf(
    .a_real(buffer_out_real), .a_imag(buffer_out_imag), 
    .b_real(in_real), .b_imag(in_imag), 

    .aout_real(a_bf_real_s), .aout_imag(a_bf_imag_s), 
    .bout_real(b_bf_real_s), .bout_imag(b_bf_imag_s)
);


// post-butterfly MUXes
assign select_counter_msb = counter[$clog2(DEPTH)];

assign flush_real_s = (select_counter_msb == 1'b1 ? a_bf_real_s : buffer_out_real);
assign flush_imag_s = (select_counter_msb == 1'b1 ? a_bf_imag_s : buffer_out_imag);

assign fill_real_s = (select_counter_msb == 1'b1 ? b_bf_real_s : in_real);
assign fill_imag_s = (select_counter_msb == 1'b1 ? b_bf_imag_s : in_imag);


wire signed [W-1:0] mul_out_real, mul_out_imag;
wire signed [W-1:0] mul_twiddle_real_in, mul_twiddle_imag_in;

assign mul_twiddle_real_in = (select_counter_msb == 1'b1 ? FP_ONE : twiddle_real_s);
assign mul_twiddle_imag_in = (select_counter_msb == 1'b1 ? 0 : twiddle_imag_s);

complex_multiplier  #(.W(W), .F(F)) mult(
    .clk(clk), .reset_n(reset_n), .en(en),
    .a_real(flush_real_s), .a_imag(flush_imag_s), 
    .b_real(mul_twiddle_real_in), .b_imag(mul_twiddle_imag_in), 
    .out_real(mul_out_real), .out_imag(mul_out_imag)
);

// --- Valid alignment for the pipelined multiplier ---
// mul_out_real/mul_out_imag now reflect flush_real_s/flush_imag_s from
// MUL_LATENCY cycles ago, not the current cycle. counter/rom_addr/the
// buffer still advance every enabled cycle unchanged -- they govern
// *input* consumption, which the multiplier's latency doesn't affect.
// valid_out, however, must wait for the multiplier's pipeline to actually
// fill. en_dly tracks "en fired N cycles ago" using the exact same
// enable-gating as complex_multiplier's internal registers, so it can't
// drift out of lockstep with the data even if en ever pauses mid-stream.
reg [MUL_LATENCY-1:0] en_dly;
always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        en_dly <= {MUL_LATENCY{1'b0}};
    end else if (en == 1'b1) begin
        en_dly <= (en_dly << 1) | 1'b1;
    end
end
wire mul_valid = en_dly[MUL_LATENCY-1];

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        counter <= 0;
        out_real <= 0;
        out_imag <= 0;
        valid_out <= 1'b0;
    end else if (en == 1'b1) begin
        counter <= counter + 1'b1;
        out_real <= mul_out_real;
        out_imag <= mul_out_imag;
        valid_out <= mul_valid;
    end else begin
        valid_out <= 1'b0;
    end
end

endmodule