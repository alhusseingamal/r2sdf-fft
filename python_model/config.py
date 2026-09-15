"""
Central configuration for hardware parameters.
"""

import math

# Fixed point parameters
# Hardware Bit-Widths (Q-Format: Q(WORD_LEN - FRAC_LEN).FRAC_LEN)
WORD_LEN = 16
FRAC_LEN =14
SIGNED = True

# FFT Configuration
N_POINTS = 8       # should always be a power of two
NUM_BITS = int(math.log2(N_POINTS))
NUM_STAGES = int(math.log2(N_POINTS))
NUM_TWIDDLES = N_POINTS // 2


# Input Stream
## Parameters for Input Stream Generation
M = 1024       # input stream length
f1 = 10
f2 = 15
amp1 = 0.7
amp2 = 0.3
dc_offset = 0.1
noise_amplitude = 0.1

## Directories of generated signals
TWIDDLE_FACTORS_FILE    = "../data/stimulus/twiddle.hex"
INPUT_STREAM_FILE       = "../data/stimulus/input_stream.hex"
GOLDEN_OUTPUT_FILE      = "../data/golden/expected_output.txt"