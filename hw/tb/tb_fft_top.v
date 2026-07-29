`timescale 1ns / 1ps
`include "definitions.vh"
module tb_fft_top;

// Parameters & Signals
localparam N = `N;
localparam W = `DATA_WIDTH;
localparam F = `FRACTIONAL_BITS;

localparam CLK_PERIOD = 20;

// 1.0 in Q8.8 fixed-point format is 256 (1 << 8)
localparam signed [W-1:0] ONE_FP = 16'd256; 

reg clk;
reg reset_n;

reg valid_in;
reg signed [W-1:0] in_real, in_imag;

wire valid_out;
wire signed [W-1:0] out_real, out_imag;

// DUT
top_level #(.N(N), .W(W),.F(F)) dut (
    .clk(clk), .reset_n(reset_n), .en(valid_in),
    .in_real(in_real), .in_imag(in_imag),
    .valid_out(valid_out), .out_real(out_real), .out_imag(out_imag)
);

// clock
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


// stimulus
integer i;
integer reset_done;
localparam M = `M;   // length of input stream

reg signed [W-1:0] input_mem [0:M-1];
real golden_real [0:M-1]; // Sized to M to hold continuous frames
real golden_imag [0:M-1];

integer fd;

initial begin
    
    // read input file
    $readmemh(`INPUT_STREAM_FILE, input_mem);

    fd = $fopen(`GOLDEN_OUTPUT_FILE, "r");
    if (fd == 0) $display("WARNING: Could not open golden output file!");
    for (i = 0; i < M; i = i + 1) begin
        $fscanf(fd, "%f %f\n", golden_real[i], golden_imag[i]);
    end
    $fclose(fd);
    
    // Initialize signals
    reset_n = 0;
    reset_done = 0;
    valid_in = 0;
    in_real = 0;
    in_imag = 0;

    // VCD Dump for GTKWave
    $dumpfile("fft_n8.vcd");
    $dumpvars(0, tb_fft_top);

    // Consume Reset cycles
    #(CLK_PERIOD*1.25)
    reset_n = 1;
    reset_done = 1;
    $display("--- Starting N=8 FFT Injection ---");

    // PHASE 1: Inject M Data Samples (Delta Impulse)
    for (i = 0; i < M; i = i + 1) begin
        @(posedge clk);
        valid_in = 1;
        in_real = input_mem[i];
        in_imag = 0;
    end

    // PHASE 2: Flush the Pipeline
    // We must keep valid_in HIGH, but feed it zeros, for at least N-1 cycles.
    // I use N+2 here just to see the pipeline safely return to zero afterwards.
    for (i = 0; i < N + 2; i = i + 1) begin
        @(posedge clk);
        valid_in = 1;
        in_real = 0;
        in_imag = 0;
    end

    // PHASE 3: Stop Streaming
    @(posedge clk);
    valid_in = 0;
    
    // Wait a bit to prove the pipeline correctly stalls when valid_in = 0
    $display("--- Simulation Complete ---");
    $finish;
end

// -------------------------------------------------------------------------
// 5. Output Monitor
// -------------------------------------------------------------------------
// This block automatically fires whenever the DUT produces a valid output.
integer cycle_count, total_output_count, valid_output_count;
initial begin
    cycle_count = 1;
    total_output_count = 0;
    valid_output_count = 0;
end

/* verilator lint_off BLKSEQ */
always @(posedge clk) begin
    if (reset_done == 1) begin  // Only start after reset is done.
        if (valid_out == 1) begin
            // Convert fixed-point back to floating-point for easy reading
            real real_float, imag_float;
            real_float = $itor(out_real) / (2.0 ** F);
            imag_float = $itor(out_imag) / (2.0 ** F);

            // For fast comparison (at least that is the purpose now), we restore original magnitude
            // because signal has been scaled by a factor of N by passing through all stages ( /2 in each of the log2(N) stages)
            real_float = real_float * N;
            imag_float = imag_float * N;
            
            if (total_output_count >= N-1) begin
                $display("Time %0t | Cycle %0d | y[%0d]: Real = %f, Imag = %f", $time, cycle_count, valid_output_count, real_float, imag_float);
                valid_output_count <= valid_output_count + 1;    
            end else begin
                $display("Time %0t | Cycle %0d | Flush Output: Real = %f, Imag = %f", $time, cycle_count, real_float, imag_float);
            end
            total_output_count <= total_output_count + 1;
        end
        cycle_count <= cycle_count + 1;
    end
end
/* verilator lint_on BLKSEQ */



// -------------------------------------------------------------------------
// 6. Independent SQNR Monitor Variables
// -------------------------------------------------------------------------
integer sqnr_total_outputs;
integer sqnr_valid_count;
integer frame_offset, local_bin_idx, golden_idx;

real expected_real, expected_imag, hw_real_float, hw_imag_float;
real err_r, err_i;
real sig_pwr;
real noise_pwr;
real sqnr_val_db;

initial begin
    sqnr_total_outputs = 0;
    sqnr_valid_count = 0;
    sig_pwr = 0.0;
    noise_pwr = 0.0;
end

/* verilator lint_off BLKSEQ */
always @(posedge clk) begin
    if (reset_done == 1 && valid_out == 1) begin
        
        if (sqnr_total_outputs >= N-1 && sqnr_valid_count < M) begin
            // 1. Convert HW Output
            hw_real_float = $itor(out_real) / (2.0 ** F) * N;
            hw_imag_float = $itor(out_imag) / (2.0 ** F) * N;

            // 2. Handle Continuous Streaming Bit-Reversal
            frame_offset  = (sqnr_valid_count / N) * N; 
            local_bin_idx = bit_reverse(sqnr_valid_count % N, $clog2(N));
            golden_idx    = frame_offset + local_bin_idx;

            // 3. Fetch Golden
            expected_real = golden_real[golden_idx];
            expected_imag = golden_imag[golden_idx];
            $display("\ngolden_real = %f, golden_imag = %f", expected_real, expected_imag);
            

            // 4. Power Accumulation (Blocking math is required here!)
            err_r = expected_real - hw_real_float;
            err_i = expected_imag - hw_imag_float;

            sig_pwr   = sig_pwr   + (expected_real**2 + expected_imag**2);
            noise_pwr = noise_pwr + (err_r**2 + err_i**2);

            // Counter uses non-blocking
            sqnr_valid_count <= sqnr_valid_count + 1;

            // 5. Final Print
            if (sqnr_valid_count == M - 1) begin // Check M-1 because non-blocking hasn't updated yet
                if (noise_pwr > 0.0) begin
                    sqnr_val_db = 10.0 * $log10(sig_pwr / noise_pwr);
                    $display("\n========================================");
                    $display("FINAL SQNR OVER %0d SAMPLES: %f dB", M, sqnr_val_db);
                    $display("========================================\n");
                end else begin
                    $display("\n========================================");
                    $display("FINAL SQNR OVER %0d SAMPLES: INFINITY", M);
                    $display("========================================\n");
                end
            end
        end
        sqnr_total_outputs <= sqnr_total_outputs + 1;
    end
end
/* verilator lint_on BLKSEQ */

endmodule

/*
    For N=8 (P_total=3), M=16
    valid_out first appears at 1 + P_total = 1 + 3 = 4
    C_first = 1 + (N-1) + P_total = 1 + (8-1)+ 3 = 11
    C_last = C_first + (M-1) = 11 + (16-1) = 26
    As we can observe, there are (11-4 = 7) outputs flushed between the appearance of valid_out and C_first
        this agrees with our derivation that N-1 ouputs are flushed (N-1=8-1 = 7)

*/