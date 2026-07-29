import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))
import math
import numpy as np
from config import *
from model.sdf_stage import SDFStage
from model.butterfly import *
from utils.plotting import *
from utils.fixed_point_helper import *
from config import *

def bit_reverse(val, num_bits):
    return int('{:0{width}b}'.format(val, width=num_bits)[::-1], 2)

def main():
    print("--- Starting Fixed-Point FFT Bit-True Simulation ---")
    
    print("---------------------------- Input signal ----------------------------")
    signal = []
    with open(INPUT_STREAM_FILE) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            
            raw = int(line, 16)                  # parse hex
            if raw & 0x8000:                     # sign bit set?
                raw -= 0x10000                   # convert to signed
            signal.append(raw / 256.0)
    
    # assert (M == len(signal))
    actual_M = len(signal)
    if actual_M % N_POINTS != 0:
        target_len = math.ceil(actual_M / N_POINTS) * N_POINTS
        padding_needed = target_len - actual_M
        signal.extend([0.0] * padding_needed)
        print(f"Notice: Padded {actual_M} samples with {padding_needed} zeros to reach hardware frame boundary ({target_len}).")
    print(signal)
    M = len(signal)

    print("------------------------ Golden Output signal -------------------------")
    # Golden Reference (Floating Point)
    golden_fft = np.zeros(M, dtype=np.complex64)

    with open(GOLDEN_OUTPUT_FILE, "r") as f:
        lines = f.readlines()

    # Expecting exactly M lines, each containing: real imag
    for i, line in enumerate(lines):
        r, im = map(float, line.strip().split())
        golden_fft[i] = np.complex64(r + 1j * im)
    
    print(golden_fft)

    # --------- Model Starts here ---------
    # Twiddle Factor Pre-computation (Read from Hex)
    TWIDDLE_ROM = []
    
    with open(TWIDDLE_FACTORS_FILE, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            
            # Separate the 8-character string into real and imaginary parts (4 chars each)
            real_hex = line[0:4]
            imag_hex = line[4:8]
            
            # Convert 16-bit hex strings to signed integers (2's complement)
            real_int = int(real_hex, 16)
            if real_int >= 0x8000:
                real_int -= 0x10000
                
            imag_int = int(imag_hex, 16)
            if imag_int >= 0x8000:
                imag_int -= 0x10000

            # Construct the ComplexFxp object (Modify the instantiation below based on your library's raw init)
            twiddle_fxp = ComplexFxp(
                real=to_fxp(real_int / (2 ** FRAC_LEN)),
                imag=to_fxp(imag_int / (2 ** FRAC_LEN))
            )
            TWIDDLE_ROM.append(twiddle_fxp)

    # Initialize Hardware Pipeline
    stages = [SDFStage(N_POINTS, i) for i in range(NUM_STAGES)]
    



    
    print("----------------------- Output signal --------------------------")
    # Run the Simulation (Clock-by-Clock)
    fxp_fft_output = []
    # Loop through input signal array
    # For every sample, pass it through stage 0, take stage 0's output 
    # Every sample is passed through stage 0, output of stage 0 is fed to stage 1, and so on...
    # M - 1 extra cycles are needed to flush the final results out.
    
    for clk in range(M + N_POINTS-1):
        if clk < M:
            current_val = ComplexFxp( real=to_fxp(signal[clk]), imag=0 )
        else:
            current_val = ComplexFxp(0, 0)
        
        for j in range(NUM_STAGES):
            local_state = stages[j].counter
            delay_len = stages[j].delay_len

            base_count = local_state % delay_len
            k = base_count * (2**j)
            twiddle = TWIDDLE_ROM[k]
            current_val = stages[j].process_sample(current_val, twiddle)
        
        if clk >= N_POINTS-1:
            fxp_fft_output.append(current_val)
    
    print(fxp_fft_output)




    # ----------- Ordering the output signal -----------
    print("----------------------- Ordered Output signal --------------------------")
    fxp_ordered_fft_output = [None] * len(fxp_fft_output)
    for i in range(len(fxp_fft_output)):
        # 1. Find which N-point frame this sample belongs to
        frame_offset = (i // N_POINTS) * N_POINTS
        
        # 2. Find the local index within the current frame
        local_idx = i % N_POINTS
        
        # 3. Bit-reverse the local index
        rev_local_idx = bit_reverse(local_idx, num_bits=NUM_BITS)
        
        # 4. Map back to the global array
        global_rev_idx = frame_offset + rev_local_idx
        fxp_ordered_fft_output[global_rev_idx] = fxp_fft_output[i]

    print(fxp_ordered_fft_output)
    



    # ----------- SQNR Calculation -----------
    # First, we convert the custom Complex Number representation into np.complex64 representation
    fxp_ordered_fft_output_float = np.array([complex(from_fxp(x.real), from_fxp(x.imag)) for x in fxp_ordered_fft_output], dtype=np.complex64)
    
    quantization_noise = golden_fft - fxp_ordered_fft_output_float
    
    # Calculate SQNR in dB using the 10 * log10(Signal_Power / Noise_Power) formula.
    signal_power = np.sum(np.abs(golden_fft)**2)
    noise_power  = np.sum(np.abs(quantization_noise)**2)
    SQNR_dB = 10 * np.log10(signal_power / noise_power)
    
    print(f"SQNR = {SQNR_dB:.2f} dB")
    
    # Plot Results
    # Call your plotting functions to visually verify the spectrum.
    # plot_time_domain(t, signal)
    # plot_frequency_domain(golden_fft, title="Golden FFT (Floating Point)")
    # plot_frequency_domain(fxp_ordered_fft_output_float, title="Fixed-Point FFT Output")
    # plot_fft_comparison(golden_fft, fxp_ordered_fft_output_float, title="Golden vs Fixed-Point FFT")
    print("Simulation Complete.")

if __name__ == "__main__":
    main()