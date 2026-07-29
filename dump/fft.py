import numpy as np

def fft(x):
    x = np.asarray(x, dtype=complex)
    N = x.size
    if N == 1:
        return x
    
    half = N//2
    
    # butterfly outputs
    X_even = x[:half] + x[half:]
    X_odd  = (x[:half] - x[half:]) * np.exp(-2j * np.pi * np.arange(half) / N)

    
    Y_even = fft(X_even)
    Y_odd = fft(X_odd)

    return np.concatenate([Y_even, Y_odd])


def bit_reverse_indices(N):
    bits = int(np.log2(N))
    return np.array([int(f"{i:0{bits}b}"[::-1], 2) for i in range(N)])

def fft_dif_natural(x):
    return x[bit_reverse_indices(len(x))]

x = fft([1,2,3,4,4,3,2,1])
print(x)
print(fft_dif_natural(x))

