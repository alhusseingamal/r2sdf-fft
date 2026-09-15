import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

import numpy as np
from utils.my_fxp import to_fxp
from config import *

def fxp_to_hex(fxp_val):
    """
    Converts an Fxp value to a hexadecimal string (16-bit, 2's complement).
    """
    # Get the raw integer representation
    raw_int = int(fxp_val.val)
    # Mask to 16 bits and convert to hex
    hex_val = hex((raw_int & 0xFFFF))[2:].upper().zfill(4)
    return hex_val

def generate_twiddles():
    """
    Generate twiddle factors (complex exponentials) for FFT.
    W_N^k = exp(-2j * pi * k / N) for k = 0, 1, ..., N-1
    """
    twiddles = []
    for k in range(NUM_TWIDDLES):
        # Calculate twiddle factor
        angle = -2 * np.pi * k / N_POINTS
        w = np.exp(1j * angle)
        
        # Convert to Fxp format
        w_real = to_fxp(w.real)
        w_imag = to_fxp(w.imag)
        
        twiddles.append((w_real, w_imag))
    
    return twiddles

def generate_input_stimulus():
    """
    Generate test signal for FFT verification.
    Creates a simple sum-of-sines signal for testing.
    """
    signal = []
    for n in range(M):
        val =  dc_offset + amp1 * np.sin(2 * np.pi * n * f1 / M) + amp2 * np.sin(2 * np.pi * n * f2 / M) + noise_amplitude * np.random.uniform(0,1)
        signal.append(to_fxp(val))
    
    return signal

def compute_golden_output(input_signal):
    """
    Compute frame-by-frame N-point golden FFT output.
    """
    signal_float = np.array([float(s) for s in input_signal])
    golden = np.zeros(len(signal_float), dtype=np.complex64)
    
    # Process each N_POINTS frame independently to match the hardware pipeline
    for i in range(0, len(signal_float), N_POINTS):
        golden[i : i + N_POINTS] = np.fft.fft(signal_float[i : i + N_POINTS])
        
    return golden

def write_hex_file(filename, data_pairs):
    """
    Write hex data to file. For complex numbers, write as real,imag pairs on same line.
    """
    with open(filename, 'w') as f:
        for data_pair in data_pairs:
            if isinstance(data_pair, tuple):
                # Complex: write real and imag as two hex values
                real_hex = fxp_to_hex(data_pair[0])
                imag_hex = fxp_to_hex(data_pair[1])
                f.write(f"{real_hex}{imag_hex}\n")
            else:
                # Real: write single hex value
                hex_val = fxp_to_hex(data_pair)
                f.write(f"{hex_val}\n")

def generate_hex_files():
    """
    Generates the .hex files required for Verilog RTL Verification.
    """
    # Create data directories if they don't exist
    Path("../data/stimulus").mkdir(parents=True, exist_ok=True)
    Path("../data/golden").mkdir(parents=True, exist_ok=True)
    
    # Generate Twiddle Factors
    print("Generating twiddle factors...")
    twiddles = generate_twiddles()
    write_hex_file(TWIDDLE_FACTORS_FILE, twiddles)
    print(f"  Wrote {len(twiddles)} twiddle factors to {TWIDDLE_FACTORS_FILE}")
    
    # Generate Input Stimulus
    print("Generating input stimulus...")
    input_signal = generate_input_stimulus()
    write_hex_file(INPUT_STREAM_FILE, input_signal)
    print(f"  Wrote {len(input_signal)} input samples to {INPUT_STREAM_FILE}")
    
    # Generate Golden Output
    print("Computing golden FFT output...")
    golden_output = compute_golden_output(input_signal)
    with open(GOLDEN_OUTPUT_FILE, "w") as f:
        for val in golden_output:
            # This formats it as: "1.246093 0.000000"
            f.write(f"{val.real:.6f} {val.imag:.6f}\n")
    print(f"  Wrote {len(golden_output)} FFT outputs to {GOLDEN_OUTPUT_FILE}")

    
    
    print("Test vectors generated successfully.")

if __name__ == "__main__":
    generate_hex_files()