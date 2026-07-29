/* verilator lint_off UNUSEDSIGNAL */
module complex_subtractor #(parameter W = 16) (
    input signed [W-1:0] a_real, a_imag,
    input signed [W-1:0] b_real, b_imag,
    output wire signed [W-1:0] out_real, out_imag
);

wire signed [W:0] diff_real, diff_imag;

// apply round half-up scheme
assign diff_real = a_real - b_real + 1;
assign diff_imag = a_imag - b_imag + 1;

// shift right by 1 to discard the LSB and restore the output in W-length format
assign out_real = diff_real[W:1];
assign out_imag = diff_imag[W:1];

endmodule
