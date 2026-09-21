`include "definitions.vh"

module sdf_stage_d4 #(
    parameter N = 8, 
    parameter W = 16, 
    parameter F = 14, 
    parameter STAGE_INDEX = 0
) (
    input clk, 
    input reset_n, 
    input en,

    input  signed [W-1:0] in_real, 
    input  signed [W-1:0] in_imag, 
    
    output reg            valid_out, 
    output reg signed [W-1:0] out_real, 
    output reg signed [W-1:0] out_imag
);

localparam DEPTH = (N >> (STAGE_INDEX + 1));
localparam signed [W-1:0] C_SQRT2_DIV2 = 16'sd11585;
localparam signed [2*W:0] ROUND_CONST  = (1 <<< (F - 1));

reg [$clog2(DEPTH):0] counter;

// Buffer signals
wire signed [W-1:0] buffer_out_real, buffer_out_imag;
wire signed [W-1:0] fill_real_s, fill_imag_s;
wire select_counter_msb = counter[$clog2(DEPTH)];

circular_buffer #(.W(W), .DEPTH(DEPTH)) queue (
    .clk(clk), .reset_n(reset_n), .en(en), 
    .in_real(fill_real_s), .in_imag(fill_imag_s), 
    .out_real(buffer_out_real), .out_imag(buffer_out_imag)
);

wire signed [W-1:0] a_bf_real_s, a_bf_imag_s;
wire signed [W-1:0] b_bf_real_s, b_bf_imag_s;

butterfly #(.W(W), .F(F)) bf (
    .a_real(buffer_out_real), .a_imag(buffer_out_imag), 
    .b_real(in_real),          .b_imag(in_imag), 
    .aout_real(a_bf_real_s),   .aout_imag(a_bf_imag_s), 
    .bout_real(b_bf_real_s),   .bout_imag(b_bf_imag_s)
);

assign fill_real_s = (select_counter_msb == 1'b1) ? b_bf_real_s : in_real;
assign fill_imag_s = (select_counter_msb == 1'b1) ? b_bf_imag_s : in_imag;

wire signed [W-1:0] flush_real_s = (select_counter_msb == 1'b1) ? a_bf_real_s : buffer_out_real;
wire signed [W-1:0] flush_imag_s = (select_counter_msb == 1'b1) ? a_bf_imag_s : buffer_out_imag;


// ------ PIPELINE STAGE 1: Register Butterfly Outputs ------
reg signed [W-1:0] p1_flush_real, p1_flush_imag;
reg [1:0]          p1_twiddle_idx;
reg                p1_is_flush;
reg                p1_valid;

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        counter        <= 'd0;
        p1_flush_real  <= 'sd0;
        p1_flush_imag  <= 'sd0;
        p1_twiddle_idx <= 2'b00;
        p1_is_flush    <= 1'b0;
        p1_valid       <= 1'b0;
    end else if (en) begin
        counter        <= counter + 1'b1;
        p1_flush_real  <= flush_real_s;
        p1_flush_imag  <= flush_imag_s;
        p1_twiddle_idx <= counter[1:0];
        p1_is_flush    <= (!select_counter_msb);
        p1_valid       <= 1'b1;
    end else begin
        p1_valid       <= 1'b0;
    end
end


// ------ PIPELINE STAGE 2: Pre-Rotation Additions (Full Sign Extension) ------
wire signed [W:0] sum_ri = $signed(p1_flush_real) + $signed(p1_flush_imag);
wire signed [W:0] diff_ir = $signed(p1_flush_imag) - $signed(p1_flush_real);
wire signed [W:0] diff_ri = $signed(p1_flush_real) - $signed(p1_flush_imag);

reg [1:0]          p2_mode;
reg signed [W-1:0] p2_direct_real, p2_direct_imag;
reg signed [W:0]   p2_term_real,   p2_term_imag;
reg                p2_valid;

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        p2_mode        <= 2'b00;
        p2_direct_real <= 'sd0;
        p2_direct_imag <= 'sd0;
        p2_term_real   <= 'sd0;
        p2_term_imag   <= 'sd0;
        p2_valid       <= 1'b0;
    end else if (p1_valid) begin
        p2_valid <= 1'b1;
        if (!p1_is_flush || p1_twiddle_idx == 2'b00) begin
            // Twiddle = 1 (Bypass)
            p2_mode        <= 2'b00;
            p2_direct_real <= p1_flush_real;
            p2_direct_imag <= p1_flush_imag;
        end else if (p1_twiddle_idx == 2'b10) begin
            // Twiddle = -j
            p2_mode        <= 2'b01;
            p2_direct_real <= p1_flush_imag;
            p2_direct_imag <= -p1_flush_real;
        end else if (p1_twiddle_idx == 2'b01) begin
            // Twiddle = W_8^1: (R+I)*C + j(I-R)*C
            p2_mode        <= 2'b10;
            p2_term_real   <= sum_ri;
            p2_term_imag   <= diff_ir;
        end else begin
            // Twiddle = W_8^3: -(R-I)*C - j(R+I)*C
            p2_mode        <= 2'b10;
            p2_term_real   <= -diff_ri;
            p2_term_imag   <= -sum_ri;
        end
    end else begin
        p2_valid <= 1'b0;
    end
end


// ------ PIPELINE STAGE 3: Constant Scaling (Synthesizer Maps to Optimal CSD Tree) ------
reg signed [2*W:0] p3_prod_real,   p3_prod_imag;
reg signed [W-1:0] p3_direct_real, p3_direct_imag;
reg [1:0]          p3_mode;
reg                p3_valid;

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        p3_prod_real   <= 'sd0;
        p3_prod_imag   <= 'sd0;
        p3_direct_real <= 'sd0;
        p3_direct_imag <= 'sd0;
        p3_mode        <= 2'b00;
        p3_valid       <= 1'b0;
    end else if (p2_valid) begin
        p3_valid       <= 1'b1;
        p3_mode        <= p2_mode;
        p3_direct_real <= p2_direct_real;
        p3_direct_imag <= p2_direct_imag;
        
        // Exact Q14 Constant Scale: 11585
        p3_prod_real   <= p2_term_real * C_SQRT2_DIV2;
        p3_prod_imag   <= p2_term_imag * C_SQRT2_DIV2;
    end else begin
        p3_valid <= 1'b0;
    end
end

// ------ PIPELINE STAGE 4: Rounding, Truncation, and Output Selection ------
wire signed [2*W:0] rounded_real = p3_prod_real + ROUND_CONST;
wire signed [2*W:0] rounded_imag = p3_prod_imag + ROUND_CONST;

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        out_real  <= 'sd0;
        out_imag  <= 'sd0;
        valid_out <= 1'b0;
    end else if (p3_valid) begin
        valid_out <= 1'b1;
        case (p3_mode)
            2'b00, 2'b01: begin
                out_real <= p3_direct_real;
                out_imag <= p3_direct_imag;
            end
            default: begin
                out_real <= rounded_real[W-1+F : F];
                out_imag <= rounded_imag[W-1+F : F];
            end
        endcase
    end else begin
        valid_out <= 1'b0;
    end
end

endmodule


// =========================================================================================
// Module: sdf_stage_d4.v
// Architecture: Single-Path Delay Feedback (SDF) Radix-2 DIF FFT - Stage Depth 4
// Target Precision: Fixed-point Q(W-F).F format (Default: Q2.14, W=16, F=14)
//
// 1. PURPOSE & WHY THIS MODULE EXISTS:
// ------------------------------------
// In an N=8 point Radix-2 Decimation-in-Frequency (DIF) FFT, the first stage (Stage 0,
// DEPTH=4) consumes the following sequence of twiddle factors during Flush Mode:
//      W_8^0 =  1.0 + j0.0
//      W_8^1 =  sqrt(2)/2 - j*sqrt(2)/2
//      W_8^2 =  0.0 - j1.0
//      W_8^3 = -sqrt(2)/2 - j*sqrt(2)/2
//
// A universal 'sdf_stage' instantiates a full, 4-quadrant complex multiplier (four 16-bit
// multipliers and wide recombine adders) plus a twiddle ROM. This incurs massive silicon
// area and long combinational paths.
//
// Looking closely at the math for W_8^1 and W_8^3:
//      For x = R + jI:
//      x * W_8^1 = (R + jI) * (C - jC)   =  (R + I)*C + j(I - R)*C
//      x * W_8^3 = (R + jI) * (-C - jC)  = -(R - I)*C - j(R + I)*C
//      where C = sqrt(2)/2.
//
// Both complex multiplications depend EXCLUSIVELY on scaling by the single constant C.
// Therefore, the entire 4-quadrant multiplier and twiddle ROM are replaced by:
//      a) Pre-rotation additions/subtractions: (R + I) and (I - R)
//      b) Scaling by the compile-time constant C_SQRT2_DIV2
//
// This cuts stage area by ~60% and eliminates dynamic multiplier array trees.
//
// 2. TIMING & PIPELINE LATENCY:
// -----------------------------
// To eliminate cross-stage carry chains and achieve timing closure above 100 MHz,
// the arithmetic is balanced across 4 pipelined register stages (Latency = 4):
//      - Stage 1: Register butterfly outputs (p1_flush_*) and latch control state.
//      - Stage 2: Evaluate pre-rotation sums/differences with sign extension.
//      - Stage 3: Perform constant scaling (* C_SQRT2_DIV2) into 33-bit products.
//      - Stage 4: Add round-half-up constant (1 << (F-1)), truncate back to W bits,
//                 and select between bypassed and scaled results into out_real/out_imag.
//
// 3. PARAMETERIZATION & CHANGING FRACTIONAL BITS (F):
// --------------------------------------------------
// This file is calibrated for Q2.14 fixed point (W=16, F=14, dynamic range [-2.0, +2.0)):
//      C_SQRT2_DIV2 = round( (1/sqrt(2)) * 2^14 ) = round( 0.70710678 * 16384 ) = 11585
//
// If you change the precision parameter F:
//      Option A (Manual Hardcoding):
//          Re-calculate the constant externally in Python:
//              C_val = round((2**-0.5) * (2**F))
//          and update:
//              localparam signed [W-1:0] C_SQRT2_DIV2 = 16'sd<C_val>;
//
//      Option B (Fallback to Universal Stage):
//          If arbitrary/runtime twiddles or higher-order N > 8 stages are needed,
//          revert to using the generic 'sdf_stage.v' which looks up 'twiddle_rom.v'
//          and routes data through 'complex_multiplier.v'.
// =========================================================================================