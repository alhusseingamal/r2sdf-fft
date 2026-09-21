module butterfly #(parameter W = 16, parameter F = 14) (
input signed [W-1:0] a_real, a_imag, 
input signed [W-1:0] b_real, b_imag, 

output wire signed [W-1:0] aout_real, aout_imag, 
output wire signed [W-1:0] bout_real, bout_imag
);

// Aout = a+b
complex_adder #(.W(W)) add(
    .a_real(a_real), .a_imag(a_imag), 
    .b_real(b_real), .b_imag(b_imag), 
    .out_real(aout_real), .out_imag(aout_imag)
);

// Bout = a-b
complex_subtractor  #(.W(W)) sub(
    .a_real(a_real), .a_imag(a_imag), 
    .b_real(b_real), .b_imag(b_imag), 
    .out_real(bout_real), .out_imag(bout_imag)
);

endmodule
