// FFT Global Definitions and Configuration Variables
`define N      8
`define DATA_WIDTH      16
`define TWIDDLE_WIDTH   16

// Fixed Point Parameters
`define FRACTIONAL_BITS 8

// Useful constants
`define PI              3.14159265358979

// Debug switch
`define ENABLE_DEBUG    0

// Input Stream
`define M 8
`define TWIDDLE_FACTORS_FILE "/mnt/data1/DV/projects/fft/data/stimulus/twiddle.hex"
`define INPUT_STREAM_FILE   "/mnt/data1/DV/projects/fft/data/stimulus/input_stream.hex"
`define GOLDEN_OUTPUT_FILE   "/mnt/data1/DV/projects/fft/data/golden/expected_output.txt"
