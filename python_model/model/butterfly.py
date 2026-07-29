from utils.fixed_point_helper import fxp_add, fxp_sub, complex_fxp_mult

class ComplexFxp:
    """Helper class to hold the Real and Imaginary fixed-point values."""
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag
    def __repr__(self):
        return f"({self.real} + {self.imag})"

def bit_true_butterfly(a, b, twiddle):
    """
    Simulates a Radix-2 Butterfly unit.
    A_out = a + b
    B_out = (a - b) * twiddle
    """
    # 1. Calculate A_out = a + b
    A_out_real = fxp_add(a.real, b.real)
    A_out_imag = fxp_add(a.imag, b.imag)

    # 2. Calculate the intermediate difference (a - b)
    diff_real = fxp_sub(a.real, b.real)
    diff_imag = fxp_sub(a.imag, b.imag)

    # 3. Calculate B_out = (a - b) * twiddle
    # MUST use the holistic complex multiplier to match the RTL truncation!
    B_out_real, B_out_imag = complex_fxp_mult(
        diff_real, diff_imag, 
        twiddle.real, twiddle.imag
    )

    # 4. Pack into objects
    A_out = ComplexFxp(A_out_real, A_out_imag)
    B_out = ComplexFxp(B_out_real, B_out_imag)

    return A_out, B_out