`timescale 1ns / 1ps
module butterfly #(parameter W = 16, parameter F = 8) (
input signed [W-1:0] a_real, a_imag, 
input signed [W-1:0] b_real, b_imag, 
input signed [W-1:0] twiddle_real, twiddle_imag, 

output wire signed [W-1:0] aout_real, aout_imag, 
output wire signed [W-1:0] bout_real, bout_imag
);

wire signed [W-1:0] diff_real, diff_imag;

// Aout = a+b
complex_adder #(.W(W)) add(
    .a_real(a_real), .a_imag(a_imag), 
    .b_real(b_real), .b_imag(b_imag), 
    .out_real(aout_real), .out_imag(aout_imag)
);

// Bout = (a-b)*twiddle
complex_subtractor  #(.W(W)) sub(
    .a_real(a_real), .a_imag(a_imag), 
    .b_real(b_real), .b_imag(b_imag), 
    .out_real(diff_real), .out_imag(diff_imag)
);

complex_multiplier  #(.W(W), .F(F)) mult(
    .a_real(diff_real), .a_imag(diff_imag), 
    .b_real(twiddle_real), .b_imag(twiddle_imag), 
    .out_real(bout_real), .out_imag(bout_imag)
);

endmodule
