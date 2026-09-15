import matplotlib.pyplot as plt
import numpy as np

# ------------------------------------------------------------
# 1. TIME DOMAIN PLOT
# ------------------------------------------------------------
def plot_time_domain(t, signal):
    """
    Simple time-domain plot of the input signal.
    """
    plt.figure(figsize=(12, 4))
    plt.plot(t, signal, linewidth=1.5)
    plt.xlabel("Time (s)")
    plt.ylabel("Amplitude")
    plt.title("Input Signal (Time Domain)")
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()

# ------------------------------------------------------------
# 2. FREQUENCY DOMAIN PLOT (single FFT)
# ------------------------------------------------------------
def plot_frequency_domain(fft_data, fs=1.0, title="FFT Magnitude"):
    """
    Plots the magnitude spectrum (in dB) of a single FFT result.
    Only positive frequencies are shown.
    """
    N = len(fft_data)
    freqs = np.fft.fftfreq(N, d=1/fs)
    pos = freqs >= 0

    mag_db = 20 * np.log10(np.abs(fft_data[pos]) + 1e-12)

    plt.figure(figsize=(12, 6))
    plt.plot(freqs[pos], mag_db, linewidth=2)
    plt.xlabel("Normalized Frequency (cycles/sample)")
    plt.ylabel("Magnitude (dB)")
    plt.title(title)
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()

# ------------------------------------------------------------
# 3. COMPARISON PLOT (golden vs fixed)
# ------------------------------------------------------------
def plot_fft_comparison(golden_fft, fixed_fft, fs=1.0, title="FFT Comparison"):
    """
    Plots both FFTs in dB on the same axes for direct comparison.
    """
    N = len(golden_fft)
    freqs = np.fft.fftfreq(N, d=1/fs)
    pos = freqs >= 0

    golden_mag = 20 * np.log10(np.abs(golden_fft[pos]) + 1e-12)
    fixed_mag  = 20 * np.log10(np.abs(fixed_fft[pos])  + 1e-12)

    plt.figure(figsize=(12, 6))
    plt.plot(freqs[pos], golden_mag, label="Golden FFT", linewidth=2)
    plt.plot(freqs[pos], fixed_mag, label="Fixed-Point FFT", linewidth=2)

    plt.xlabel("Normalized Frequency (cycles/sample)")
    plt.ylabel("Magnitude (dB)")
    plt.title(title)
    plt.legend()
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()

# ------------------------------------------------------------
# 4. OVERLAY SPECTRUM
# ------------------------------------------------------------
def plot_spectrum(golden_fft, fixed_fft, fs=1.0, title="FFT Spectrum"):
    """
    Overlays the floating-point and fixed-point FFT spectrums.
    Uses magnitude in dB and plots only the positive half.
    """
    N = len(golden_fft)
    freqs = np.fft.fftfreq(N, d=1/fs)
    pos = freqs >= 0

    golden_mag = 20 * np.log10(np.abs(golden_fft[pos]) + 1e-12)
    fixed_mag  = 20 * np.log10(np.abs(fixed_fft[pos])  + 1e-12)

    plt.figure(figsize=(12, 6))
    plt.plot(freqs[pos], golden_mag, label='Golden (Float)', linewidth=2, alpha=0.8)
    plt.plot(freqs[pos], fixed_mag,  label='Fixed-Point', linewidth=2, alpha=0.8)

    plt.xlabel('Normalized Frequency (cycles/sample)')
    plt.ylabel('Magnitude (dB)')
    plt.title(title)
    plt.legend()
    plt.grid(True, which='both', alpha=0.3)
    plt.tight_layout()
    plt.show()

# ------------------------------------------------------------
# 5. SQNR SWEEP
# ------------------------------------------------------------
def plot_sqnr_sweep(bit_widths, sqnr_values):
    """
    Plots SQNR vs. Fractional Bit-Width to find the optimal hardware size.
    """
    plt.figure(figsize=(10, 6))
    plt.plot(bit_widths, sqnr_values, marker='o', linewidth=2, markersize=8)

    plt.xlabel('Fractional Bit-Width')
    plt.ylabel('SQNR (dB)')
    plt.title('Signal-to-Quantization-Noise Ratio vs. Bit-Width')
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.show()
