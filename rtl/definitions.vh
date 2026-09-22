// FFT Global Definitions and Configuration Variables
`define N      8
`define DATA_WIDTH      16
`define TWIDDLE_WIDTH   16

// Fixed Point Parameters
`define FRACTIONAL_BITS 14

// Useful constants
`define PI              3.14159265358979

// Debug switch
`define ENABLE_DEBUG    0

// Input Stream
`define M 1024
`define TWIDDLE_FACTORS_FILE "../data/stimulus/twiddle.hex"
`define INPUT_STREAM_FILE   "../data/stimulus/input_stream.hex"
`define GOLDEN_OUTPUT_FILE   "../data/golden/expected_output.txt"
