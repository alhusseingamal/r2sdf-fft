module top_level 
#(parameter N = 8, parameter W = 16, parameter F = 8) 
(
    input clk, 
    input reset_n, 
    input en, 

    input reg signed [W-1:0] in_real,
    input reg signed [W-1:0] in_imag,
    
    output valid_out,
    output signed [W-1:0] out_real,
    output signed [W-1:0] out_imag
);

localparam NUM_STAGES = $clog2(N);

// The dimensions [NUM_STAGES:0] go BEFORE the variable name now!
wire signed [(NUM_STAGES+1)*W-1:0] stage_real;
wire signed [(NUM_STAGES+1)*W-1:0] stage_imag;
wire        [NUM_STAGES:0]        stage_valid;

// While Stage indexing used in documentation is such that 1st stage is stage 0
// Here "stage" 0 is not an actual stage, but rather the inputs
// I choose to do that for a more compact and nicer code (especially the generate block)
// The other solution would be to treat the input separately, such that 1st stage is stage 0
// But then the inputs to 1st stage (stage 0) will also have to be written independent of the other stages
// In short, the code will get bloated

assign stage_real[0 +: W] = in_real;
assign stage_imag[0 +: W] = in_imag;
assign stage_valid[0] = en;

genvar i;
generate
    for (i = 0; i < NUM_STAGES; i = i+1) begin : stage_gen
        sdf_stage #(.N(N), .W(W), .F(F), .STAGE_INDEX(i)) stage_inst(
            .clk(clk), .reset_n(reset_n), .en(stage_valid[i]), 
            .in_real(stage_real[i*W +: W]), .in_imag(stage_imag[i*W +: W]), 
            .valid_out(stage_valid[i+1]), 
            .out_real(stage_real[(i+1)*W +: W]), .out_imag(stage_imag[(i+1)*W +: W])
        );
    end
endgenerate

assign out_real = stage_real[NUM_STAGES*W +: W];
assign out_imag  = stage_imag[NUM_STAGES*W +: W];
assign valid_out = stage_valid[NUM_STAGES];

endmodule
