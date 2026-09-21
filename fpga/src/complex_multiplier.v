module complex_multiplier #(parameter W = 16, parameter F = 14) (
    input clk, input reset_n, input en,
    input signed [W-1:0] a_real, a_imag,
    input signed [W-1:0] b_real, b_imag,
    output reg signed [W-1:0] out_real, out_imag
);

// Pipelined over LATENCY=5 clock cycles.
//
//   Stage 0: register the inputs (added for FPGA BRAM read latency).
//   Stage 1: split a AND b into hi/lo halves, compute + register the four
//            RAW cross-terms per product (hh, hl, lh, ll) with NOTHING
//            chained after the multiplies -- this stage is just the
//            narrow multiplies themselves.
//   Stage 2: add the mid term (mid = hl + lh), register it; hh and ll are
//            just re-registered here (pure delay-match, no logic) so all
//            three terms line up in time for stage 3.
//   Stage 3: recombine hh, mid, ll into the full 2W-bit product --
//            (hh <<< 2H) + (mid <<< H) + ll -- exact, no precision loss --
//            and register.
//   Stage 4: add/subtract, round, truncate -- registered into
//            out_real/out_imag.
//
// Earlier version of this file pre-combined mid = hl+lh INSIDE stage 1,
// right after the multiplies, to save a register. On iCE40 (no hard
// multiplier inferred -- LUT4/carry-chain fabric) that was the wrong
// trade: it chained a full addition in series after the multiply, in the
// same un-registered stretch of logic, which cost more delay than the
// narrower multiply saved (measured regression: ~80MHz -> ~70MHz, 14 ->
// 16 logic levels). This version keeps stage 1 to just the multiplies and
// moves every addition to its own stage instead -- more registers, but no
// stage does "multiply then add" in series anymore.
//
// This is an engineered estimate, not a verified number -- re-run
// icetime/nextpnr timing after this change. If stage 3 (two chained
// 32-bit adds) turns out to be the new bottleneck, it can be split into
// two stages the same way (LATENCY -> 6).
//
// Before sinking more rounds into hand-balancing this: if your iCE40 part
// has hardened DSP (SB_MAC16 -- iCE40 UltraPlus/UP5K parts have 8 of
// them), check whether `synth_ice40 -dsp` gets Yosys to infer them for
// these multiplies. That would likely make this whole exercise moot.
//
// Anything instantiating this module must delay its own valid/enable
// indicator by LATENCY cycles relative to when a_real/a_imag/b_real/b_imag
// are presented.
//
// Re-check against the bit-true Python reference model before relying on
// it.
localparam LATENCY = 5;

localparam H    = W/2;              // split point (assumes W even)
localparam HHW  = 2*(W-H);          // width of the hi*hi term
localparam HLW  = (W-H)+(H+1);      // width of hi*lo_s (or lo_s*hi) term
localparam MIDW = HLW + 1;          // width of (hi*lo_s + lo_s*hi)
localparam LLW  = 2*(H+1);          // width of lo_s*lo_s term (always >=0)
localparam PW   = 2*W;              // full product width (unchanged)

// ---- Stage 0: register inputs ----
reg signed [W-1:0] a_real_reg, a_imag_reg;
reg signed [W-1:0] b_real_reg, b_imag_reg;

always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        a_real_reg <= 'd0; a_imag_reg <= 'd0;
        b_real_reg <= 'd0; b_imag_reg <= 'd0;
    end else if (en) begin
        a_real_reg <= a_real; a_imag_reg <= a_imag;
        b_real_reg <= b_real; b_imag_reg <= b_imag;
    end
end

// ---- Stage 1: split a AND b, compute the four RAW terms per product ----
wire signed [W-H-1:0] a_real_hi = a_real_reg[W-1:H];
wire        [H-1:0]   a_real_lo = a_real_reg[H-1:0];
wire signed [H:0]     a_real_lo_s = $signed({1'b0, a_real_lo});

wire signed [W-H-1:0] a_imag_hi = a_imag_reg[W-1:H];
wire        [H-1:0]   a_imag_lo = a_imag_reg[H-1:0];
wire signed [H:0]     a_imag_lo_s = $signed({1'b0, a_imag_lo});

wire signed [W-H-1:0] b_real_hi = b_real_reg[W-1:H];
wire        [H-1:0]   b_real_lo = b_real_reg[H-1:0];
wire signed [H:0]     b_real_lo_s = $signed({1'b0, b_real_lo});

wire signed [W-H-1:0] b_imag_hi = b_imag_reg[W-1:H];
wire        [H-1:0]   b_imag_lo = b_imag_reg[H-1:0];
wire signed [H:0]     b_imag_lo_s = $signed({1'b0, b_imag_lo});

// p_rr = a_real * b_real
wire signed [HHW-1:0] rr_hh = a_real_hi   * b_real_hi;
wire signed [HLW-1:0] rr_hl = a_real_hi   * b_real_lo_s;
wire signed [HLW-1:0] rr_lh = a_real_lo_s * b_real_hi;
wire signed [LLW-1:0] rr_ll = a_real_lo_s * b_real_lo_s;

// p_ii = a_imag * b_imag
wire signed [HHW-1:0] ii_hh = a_imag_hi   * b_imag_hi;
wire signed [HLW-1:0] ii_hl = a_imag_hi   * b_imag_lo_s;
wire signed [HLW-1:0] ii_lh = a_imag_lo_s * b_imag_hi;
wire signed [LLW-1:0] ii_ll = a_imag_lo_s * b_imag_lo_s;

// p_ri = a_real * b_imag
wire signed [HHW-1:0] ri_hh = a_real_hi   * b_imag_hi;
wire signed [HLW-1:0] ri_hl = a_real_hi   * b_imag_lo_s;
wire signed [HLW-1:0] ri_lh = a_real_lo_s * b_imag_hi;
wire signed [LLW-1:0] ri_ll = a_real_lo_s * b_imag_lo_s;

// p_ir = a_imag * b_real
wire signed [HHW-1:0] ir_hh = a_imag_hi   * b_real_hi;
wire signed [HLW-1:0] ir_hl = a_imag_hi   * b_real_lo_s;
wire signed [HLW-1:0] ir_lh = a_imag_lo_s * b_real_hi;
wire signed [LLW-1:0] ir_ll = a_imag_lo_s * b_real_lo_s;

reg signed [HHW-1:0] rr_hh_r, ii_hh_r, ri_hh_r, ir_hh_r;
reg signed [HLW-1:0] rr_hl_r, ii_hl_r, ri_hl_r, ir_hl_r;
reg signed [HLW-1:0] rr_lh_r, ii_lh_r, ri_lh_r, ir_lh_r;
reg signed [LLW-1:0] rr_ll_r, ii_ll_r, ri_ll_r, ir_ll_r;

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        rr_hh_r <= 0; ii_hh_r <= 0; ri_hh_r <= 0; ir_hh_r <= 0;
        rr_hl_r <= 0; ii_hl_r <= 0; ri_hl_r <= 0; ir_hl_r <= 0;
        rr_lh_r <= 0; ii_lh_r <= 0; ri_lh_r <= 0; ir_lh_r <= 0;
        rr_ll_r <= 0; ii_ll_r <= 0; ri_ll_r <= 0; ir_ll_r <= 0;
    end else if (en == 1'b1) begin
        rr_hh_r <= rr_hh; ii_hh_r <= ii_hh; ri_hh_r <= ri_hh; ir_hh_r <= ir_hh;
        rr_hl_r <= rr_hl; ii_hl_r <= ii_hl; ri_hl_r <= ri_hl; ir_hl_r <= ir_hl;
        rr_lh_r <= rr_lh; ii_lh_r <= ii_lh; ri_lh_r <= ri_lh; ir_lh_r <= ir_lh;
        rr_ll_r <= rr_ll; ii_ll_r <= ii_ll; ri_ll_r <= ri_ll; ir_ll_r <= ir_ll;
    end
end

// ---- Stage 2: mid = hl + lh (own stage); hh/ll are pure delay-match regs ----
wire signed [MIDW-1:0] rr_mid = rr_hl_r + rr_lh_r;
wire signed [MIDW-1:0] ii_mid = ii_hl_r + ii_lh_r;
wire signed [MIDW-1:0] ri_mid = ri_hl_r + ri_lh_r;
wire signed [MIDW-1:0] ir_mid = ir_hl_r + ir_lh_r;

reg signed [HHW-1:0]  rr_hh_r2, ii_hh_r2, ri_hh_r2, ir_hh_r2;
reg signed [MIDW-1:0] rr_mid_r, ii_mid_r, ri_mid_r, ir_mid_r;
reg signed [LLW-1:0]  rr_ll_r2, ii_ll_r2, ri_ll_r2, ir_ll_r2;

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        rr_hh_r2 <= 0; ii_hh_r2 <= 0; ri_hh_r2 <= 0; ir_hh_r2 <= 0;
        rr_mid_r <= 0; ii_mid_r <= 0; ri_mid_r <= 0; ir_mid_r <= 0;
        rr_ll_r2 <= 0; ii_ll_r2 <= 0; ri_ll_r2 <= 0; ir_ll_r2 <= 0;
    end else if (en == 1'b1) begin
        rr_hh_r2 <= rr_hh_r; ii_hh_r2 <= ii_hh_r; ri_hh_r2 <= ri_hh_r; ir_hh_r2 <= ir_hh_r;
        rr_mid_r <= rr_mid;  ii_mid_r <= ii_mid;  ri_mid_r <= ri_mid;  ir_mid_r <= ir_mid;
        rr_ll_r2 <= rr_ll_r; ii_ll_r2 <= ii_ll_r; ri_ll_r2 <= ri_ll_r; ir_ll_r2 <= ir_ll_r;
    end
end

// ---- Stage 3: recombine each product to full precision ----
wire signed [PW-1:0] rr_hh_ext  = $signed({{(PW-HHW){rr_hh_r2[HHW-1]}},   rr_hh_r2});
wire signed [PW-1:0] rr_mid_ext = $signed({{(PW-MIDW){rr_mid_r[MIDW-1]}}, rr_mid_r});
wire signed [PW-1:0] rr_ll_ext  = $signed({{(PW-LLW){rr_ll_r2[LLW-1]}},   rr_ll_r2});
wire signed [PW-1:0] p_rr = (rr_hh_ext <<< (2*H)) + (rr_mid_ext <<< H) + rr_ll_ext;

wire signed [PW-1:0] ii_hh_ext  = $signed({{(PW-HHW){ii_hh_r2[HHW-1]}},   ii_hh_r2});
wire signed [PW-1:0] ii_mid_ext = $signed({{(PW-MIDW){ii_mid_r[MIDW-1]}}, ii_mid_r});
wire signed [PW-1:0] ii_ll_ext  = $signed({{(PW-LLW){ii_ll_r2[LLW-1]}},   ii_ll_r2});
wire signed [PW-1:0] p_ii = (ii_hh_ext <<< (2*H)) + (ii_mid_ext <<< H) + ii_ll_ext;

wire signed [PW-1:0] ri_hh_ext  = $signed({{(PW-HHW){ri_hh_r2[HHW-1]}},   ri_hh_r2});
wire signed [PW-1:0] ri_mid_ext = $signed({{(PW-MIDW){ri_mid_r[MIDW-1]}}, ri_mid_r});
wire signed [PW-1:0] ri_ll_ext  = $signed({{(PW-LLW){ri_ll_r2[LLW-1]}},   ri_ll_r2});
wire signed [PW-1:0] p_ri = (ri_hh_ext <<< (2*H)) + (ri_mid_ext <<< H) + ri_ll_ext;

wire signed [PW-1:0] ir_hh_ext  = $signed({{(PW-HHW){ir_hh_r2[HHW-1]}},   ir_hh_r2});
wire signed [PW-1:0] ir_mid_ext = $signed({{(PW-MIDW){ir_mid_r[MIDW-1]}}, ir_mid_r});
wire signed [PW-1:0] ir_ll_ext  = $signed({{(PW-LLW){ir_ll_r2[LLW-1]}},   ir_ll_r2});
wire signed [PW-1:0] p_ir = (ir_hh_ext <<< (2*H)) + (ir_mid_ext <<< H) + ir_ll_ext;

reg signed [PW-1:0] p_rr_r, p_ii_r, p_ri_r, p_ir_r;

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        p_rr_r <= 0; p_ii_r <= 0; p_ri_r <= 0; p_ir_r <= 0;
    end else if (en == 1'b1) begin
        p_rr_r <= p_rr; p_ii_r <= p_ii; p_ri_r <= p_ri; p_ir_r <= p_ir;
    end
end

// ---- Stage 4: combine, round, truncate (unchanged from the original) ----
wire signed [PW:0] sum_real, sum_imag;

assign sum_real = (p_rr_r - p_ii_r) + (1 <<< (F-1));
assign sum_imag = (p_ri_r + p_ir_r) + (1 <<< (F-1));

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        out_real <= 0;
        out_imag <= 0;
    end else if (en == 1'b1) begin
        out_real <= sum_real[W-1+F:F];
        out_imag <= sum_imag[W-1+F:F];
    end
end

endmodule