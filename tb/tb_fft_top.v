`timescale 1ns / 1ps
`include "definitions.vh"

module tb_fft_top;

// Parameters & Signals
localparam N = `N;
localparam W = `DATA_WIDTH;
localparam F = `FRACTIONAL_BITS;

localparam CLK_PERIOD = 20;

localparam MUL_LATENCY   = 2;
localparam STAGE_LATENCY = 1 + MUL_LATENCY;
localparam NUM_STAGES    = $clog2(N);
localparam P_TOTAL       = NUM_STAGES * STAGE_LATENCY;

reg clk;
reg reset_n;

reg valid_in;
reg signed [W-1:0] in_real, in_imag;

wire valid_out;
wire signed [W-1:0] out_real, out_imag;

// DUT
top_level #(.N(N), .W(W), .F(F)) dut (
    .clk(clk), .reset_n(reset_n), .en(valid_in),
    .in_real(in_real), .in_imag(in_imag),
    .valid_out(valid_out), .out_real(out_real), .out_imag(out_imag)
);

// Clock Generation
initial begin
    clk = 0;
    forever #(CLK_PERIOD/2) clk = ~clk;
end

// Helper Function: Bit Reversal for Output Matching
function integer bit_reverse;
    input integer val;
    input integer num_bits;
    integer b, rev;
    begin
        rev = 0;
        for (b = 0; b < num_bits; b = b + 1) begin
            rev = (rev << 1) | ((val >> b) & 1'b1);
        end
        bit_reverse = rev;
    end
endfunction

// Stimulus & Verification Variables
integer i;
integer reset_done;
localparam M = `M; // Length of input stream

reg signed [W-1:0] input_mem [0:M-1];
real golden_real [0:M-1];
real golden_imag [0:M-1];

integer fd;

// -------------------------------------------------------------------------
// SQNR Monitor Variables
// -------------------------------------------------------------------------
integer cycle_count;
integer sqnr_total_outputs;
integer sqnr_valid_count;
integer frame_offset, local_bin_idx, golden_idx;

real expected_real, expected_imag, hw_real_float, hw_imag_float;
real err_r, err_i;
real sig_pwr;
real noise_pwr;
real sqnr_val_db;

initial begin
    cycle_count        = 1;
    sqnr_total_outputs = 0;
    sqnr_valid_count   = 0;
    sig_pwr            = 0.0;
    noise_pwr          = 0.0;
end

// Track elapsed clock cycles
always @(posedge clk) begin
    if (reset_done == 1) begin
        cycle_count <= cycle_count + 1;
    end
end

// -------------------------------------------------------------------------
// Stimulus Driver
// -------------------------------------------------------------------------
initial begin
    // Read input stream and golden data
    $readmemh(`INPUT_STREAM_FILE, input_mem);

    fd = $fopen(`GOLDEN_OUTPUT_FILE, "r");
    if (fd == 0) begin
        $display("ERROR: Could not open golden output file!");
        $finish;
    end
    for (i = 0; i < M; i = i + 1) begin
        $fscanf(fd, "%f %f\n", golden_real[i], golden_imag[i]);
    end
    $fclose(fd);
    
    // Initialize signals
    reset_n    = 0;
    reset_done = 0;
    valid_in   = 0;
    in_real    = 0;
    in_imag    = 0;

    // VCD Dump
    $dumpfile("dump.vcd");
    $dumpvars(0, tb_fft_top);

    // Reset Sequence
    #(CLK_PERIOD * 1.25);
    reset_n    = 1;
    reset_done = 1;
    $display("--- Starting N=%0d FFT Injection (M=%0d samples) ---", N, M);

    // PHASE 1: Inject M Data Samples
    for (i = 0; i < M; i = i + 1) begin
        @(posedge clk);
        valid_in = 1'b1;
        in_real  = input_mem[i];
        in_imag  = 'd0;
    end

    // PHASE 2: Flush the Pipeline with Zeros
    for (i = 0; i < (N + P_TOTAL + 64); i = i + 1) begin
        @(posedge clk);
        valid_in = 1'b1;
        in_real  = 'd0;
        in_imag  = 'd0;
    end

    // PHASE 3: Drop valid_in
    @(posedge clk);
    valid_in = 1'b0;

    // Allow any remaining clocked events to finish
    repeat (20) @(posedge clk);

    if (sqnr_valid_count < M) begin
        $display("\n========================================================");
        $display("WARNING: Pipeline ended before reaching M samples!");
        $display("Processed %0d / %0d samples.", sqnr_valid_count, M);
        $display("========================================================\n");
    end

    $display("--- Simulation Complete ---");
    $finish;
end

// -------------------------------------------------------------------------
// Output & SQNR Monitor with Golden Comparison
// -------------------------------------------------------------------------
/* verilator lint_off BLKSEQ */
always @(posedge clk) begin
    if (reset_done == 1 && valid_out == 1) begin
        // 1. Convert HW Output
        hw_real_float = ($itor(out_real) / (2.0 ** F)) * N;
        hw_imag_float = ($itor(out_imag) / (2.0 ** F)) * N;

        if (sqnr_total_outputs >= N-1 && sqnr_valid_count < M) begin
            // 2. Handle Continuous Streaming Bit-Reversal
            frame_offset  = (sqnr_valid_count / N) * N; 
            local_bin_idx = bit_reverse(sqnr_valid_count % N, $clog2(N));
            golden_idx    = frame_offset + local_bin_idx;

            // 3. Fetch Golden Reference
            expected_real = golden_real[golden_idx];
            expected_imag = golden_imag[golden_idx];

            // 4. Side-by-Side Formatted Printout
            $display("Time %0t | Cycle %0d | y[%0d]: HW = (%9.5f, %9.5f) | Golden = (%9.5f, %9.5f)", 
                     $time, cycle_count, sqnr_valid_count, hw_real_float, hw_imag_float, expected_real, expected_imag);

            // 5. Power Accumulation
            err_r = expected_real - hw_real_float;
            err_i = expected_imag - hw_imag_float;

            sig_pwr   = sig_pwr   + (expected_real**2 + expected_imag**2);
            noise_pwr = noise_pwr + (err_r**2 + err_i**2);

            // 6. Check Termination on the Final Sample
            if (sqnr_valid_count == M - 1) begin
                if (noise_pwr > 0.0) begin
                    sqnr_val_db = 10.0 * $log10(sig_pwr / noise_pwr);$display("\n========================================");
                    $display("FINAL SQNR OVER %0d SAMPLES: %f dB", M, sqnr_val_db);
                    $display("========================================\n");
                end else begin
                    $display("\n========================================");
                    $display("FINAL SQNR OVER %0d SAMPLES: INFINITY", M);
                    $display("========================================\n");
                end
                $finish;
            end

            sqnr_valid_count <= sqnr_valid_count + 1;
        end else begin
            $display("Time %0t | Cycle %0d | Flush Output: HW = (%9.5f, %9.5f)", 
                     $time, cycle_count, hw_real_float, hw_imag_float);
        end

        sqnr_total_outputs <= sqnr_total_outputs + 1;
    end
end
/* verilator lint_on BLKSEQ */

endmodule