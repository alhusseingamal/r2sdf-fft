`include "definitions.vh"

module sdf_stage_d2 #(parameter N = 8, parameter W = 16, parameter F = 8, parameter STAGE_INDEX = 0) (
    input clk, 
    input reset_n, 
    input en, 

    input signed [W-1:0] in_real, 
    input signed [W-1:0] in_imag, 
    
    output reg valid_out, 
    output reg signed [W-1:0] out_real, 
    output reg signed [W-1:0] out_imag
);

localparam DEPTH = (N  >> (STAGE_INDEX+1));  // note: stages are indexed starting at 0

reg [$clog2(DEPTH):0] counter;

// Buffer signals
wire signed [W-1:0] buffer_out_real, buffer_out_imag;

// Stage signals
wire signed [W-1:0] flush_real_s, flush_imag_s;
wire signed [W-1:0] fill_real_s, fill_imag_s;
wire select_counter_msb;    // if MSB of counter is 1, we are in Compute Mode, else we are in Fill/Flush Mode

// Butterfly signals
wire signed [W-1:0] a_bf_real_s, a_bf_imag_s;
wire signed [W-1:0] b_bf_real_s, b_bf_imag_s;

circular_buffer #(.W(W), .DEPTH(DEPTH))
queue(
.clk(clk), .reset_n(reset_n), .en(en), 
.in_real(fill_real_s), .in_imag(fill_imag_s), 
.out_real(buffer_out_real), .out_imag(buffer_out_imag)
);

// Aout = a+b
complex_adder #(.W(W)) add(
    .a_real(buffer_out_real), .a_imag(buffer_out_imag), 
    .b_real(in_real), .b_imag(in_imag), 
    .out_real(a_bf_real_s), .out_imag(a_bf_imag_s)
);

// Bout = (a-b)*twiddle
wire signed [W-1:0] diff_real, diff_imag;
complex_subtractor  #(.W(W)) sub(
    .a_real(buffer_out_real), .a_imag(buffer_out_imag), 
    .b_real(in_real), .b_imag(in_imag), 
    .out_real(diff_real), .out_imag(diff_imag)
);

// Swap real and imaginary parts, then negate
wire twiddle_sel = counter[0];
assign b_bf_real_s = (twiddle_sel == 1'b0) ? diff_real : diff_imag;
assign b_bf_imag_s = (twiddle_sel == 1'b0) ? diff_imag : -diff_real;

assign select_counter_msb = counter[$clog2(DEPTH)];

assign flush_real_s = (select_counter_msb == 1'b1 ? a_bf_real_s : buffer_out_real);
assign flush_imag_s = (select_counter_msb == 1'b1 ? a_bf_imag_s : buffer_out_imag);

assign fill_real_s = (select_counter_msb == 1'b1 ? b_bf_real_s : in_real);
assign fill_imag_s = (select_counter_msb == 1'b1 ? b_bf_imag_s : in_imag);

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        counter <= 0;
        out_real <= 0;
        out_imag <= 0;
        valid_out <= 1'b0;
    end else if (en == 1'b1) begin
        counter <= counter + 1'b1;
        out_real <= flush_real_s;
        out_imag <= flush_imag_s;
        valid_out <= 1'b1;
    end else begin
        valid_out <= 1'b0;
    end
end

endmodule
