`include "definitions.vh"

module sdf_stage_d1 #(parameter N = 8, parameter W = 16, parameter F = 14, parameter STAGE_INDEX = 0) (
    input clk, input reset_n, input en,

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

// ------------------ Multiplier ------------------
// Nothing to do; it is an identity mapping for the last stage (depth=1)

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
