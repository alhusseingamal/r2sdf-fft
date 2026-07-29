/* verilator lint_off UNUSEDSIGNAL */
module complex_multiplier #(parameter W = 16, parameter F = 8) (
    input signed [W-1:0] a_real, a_imag,
    input signed [W-1:0] b_real, b_imag,
    output wire signed [W-1:0] out_real, out_imag
);

wire signed [2*W-1:0] p_rr,p_ii,p_ri,p_ir;

assign p_rr = a_real * b_real;
assign p_ii = a_imag * b_imag;
assign p_ri = a_real * b_imag;
assign p_ir = a_imag * b_real;

wire signed [2*W:0] sum_real, sum_imag;

// apply round half-up scheme
assign sum_real = (p_rr - p_ii) + (1 << (F-1));
assign sum_imag = (p_ri + p_ir) + (1 << (F-1));
assign out_real = sum_real[W-1+F:F];
assign out_imag = sum_imag[W-1+F:F];

endmodule
