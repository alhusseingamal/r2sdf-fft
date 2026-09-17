module top_level 
#(parameter N = 8, parameter W = 16, parameter F = 8) 
(
    input clk, 
    input reset_n, 
    input en, 

    input signed [W-1:0] in_real,
    input signed [W-1:0] in_imag,
    
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

/*

// The following were an attempt to remove stages of depth d=2 and d=1 (aka last two stages) to eliminate their multipliers and reduce area used
// From FFT theory, we know that those two stages don't involve any actual multiplications:
//  - d=2: swap real and imaginary values, and then negate imaginary part
//  - d=1: multiplication by 1
// Even though this decreased total number of wires, this, a bit surprisingly, increased total number of cells used (both for ASIC and FPGA flows)
// Potential Explanation: Yosys already discovers the fact that those two stages are trivial and heavily optimizes them through constant propagation
// By making them explicit, we limit yosys optimizations and inadvertently increase the total number of cells
// Note: Of course, there are not effect on speed, since those two stages are not in the critical path

// To use them instead of the generic sdf_stage, simply alter the loop counter in the sdf_stage generate loop to run only up to NUM_STAGEs-2

sdf_stage_d2 #(.N(N), .W(W), .F(F), .STAGE_INDEX(NUM_STAGES-2)) stage_d2(
    .clk(clk), .reset_n(reset_n), .en(stage_valid[NUM_STAGES-2]), 
    .in_real(stage_real[(NUM_STAGES-2)*W +: W]), .in_imag(stage_imag[(NUM_STAGES-2)*W +: W]), 
    .valid_out(stage_valid[(NUM_STAGES-2)+1]), 
    .out_real(stage_real[((NUM_STAGES-2)+1)*W +: W]), .out_imag(stage_imag[((NUM_STAGES-2)+1)*W +: W])
);

sdf_stage_d1 #(.N(N), .W(W), .F(F), .STAGE_INDEX(NUM_STAGES-1)) stage_d1(
    .clk(clk), .reset_n(reset_n), .en(stage_valid[NUM_STAGES-1]), 
    .in_real(stage_real[(NUM_STAGES-1)*W +: W]), .in_imag(stage_imag[(NUM_STAGES-1)*W +: W]), 
    .valid_out(stage_valid[(NUM_STAGES-1)+1]), 
    .out_real(stage_real[((NUM_STAGES-1)+1)*W +: W]), .out_imag(stage_imag[((NUM_STAGES-1)+1)*W +: W])
);
*/

assign out_real = stage_real[NUM_STAGES*W +: W];
assign out_imag  = stage_imag[NUM_STAGES*W +: W];
assign valid_out = stage_valid[NUM_STAGES];

endmodule
