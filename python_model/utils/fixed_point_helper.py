import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

from config import *
from fxpmath import Fxp

def to_fxp(val):
    """
    Casts a Python float, int, or complex number into our hardware Fxp format.
    For complex numbers, returns a tuple (real_Fxp, imag_Fxp).
    """
    # Handle complex numbers by splitting into real and imaginary parts
    if isinstance(val, complex):
        real_fxp = Fxp(val.real, signed=SIGNED, n_word=WORD_LEN, n_frac=FRAC_LEN, overflow="saturate", rounding='trunc')
        imag_fxp = Fxp(val.imag, signed=SIGNED, n_word=WORD_LEN, n_frac=FRAC_LEN, overflow="saturate", rounding='trunc')
        return (real_fxp, imag_fxp)
    
    # Handle Fxp objects
    if isinstance(val, Fxp):
        return Fxp(val.get_val(), signed=SIGNED, n_word=WORD_LEN, n_frac=FRAC_LEN, overflow="saturate", rounding='trunc')
    
    # Handle real numbers (float, int)
    return Fxp(val, signed=SIGNED, n_word=WORD_LEN, n_frac=FRAC_LEN, overflow="saturate", rounding='trunc')

def from_fxp(val):
    return float(val)
        

def sign_extend(val, bits):
    """
    Mimics a Verilog wire slice. Masks the integer to the exact bit width, 
    then sign-extends it back to Python's infinite precision.
    """
    mask = (1 << bits) - 1
    val_masked = val & mask
    sign_bit = 1 << (bits - 1)
    return (val_masked & (sign_bit - 1)) - (val_masked & sign_bit)

def fxp_add(a, b):
    """Bit-true scalar addition matching complex_adder.v"""
    fa = to_fxp(a)
    fb = to_fxp(b)

    # Verilog: sum_real = a_real + b_real + 1; (W+1 bit wire)
    sum_val = fa.val + fb.val + 1
    sum_masked = sum_val & ((1 << (WORD_LEN + 1)) - 1)

    # Verilog: out_real = sum_real[W:1];
    shifted = sum_masked >> 1
    final_int = sign_extend(shifted, WORD_LEN)

    # Convert raw integer back to float for Fxp instantiation
    return to_fxp(final_int / (2**FRAC_LEN))

def fxp_sub(a, b):
    """Bit-true scalar subtraction matching complex_subtractor.v"""
    fa = to_fxp(a)
    fb = to_fxp(b)

    # Verilog: diff_real = a_real - b_real + 1; (W+1 bit wire)
    diff_val = fa.val - fb.val + 1
    diff_masked = diff_val & ((1 << (WORD_LEN + 1)) - 1)

    # Verilog: out_real = diff_real[W:1];
    shifted = diff_masked >> 1
    final_int = sign_extend(shifted, WORD_LEN)

    return to_fxp(final_int / (2**FRAC_LEN))

def complex_fxp_mult(a_real, a_imag, b_real, b_imag):
    """
    Bit-true complex multiplication matching complex_multiplier.v.
    Must be done holistically to preserve cross-term precision!
    """
    ar = to_fxp(a_real).val
    ai = to_fxp(a_imag).val
    br = to_fxp(b_real).val
    bi = to_fxp(b_imag).val

    # Verilog: p_rr = a_real * b_real; (2*W bits)
    p_rr = ar * br
    p_ii = ai * bi
    p_ri = ar * bi
    p_ir = ai * br

    # Verilog: sum_real = (p_rr - p_ii) + (1 << (F-1)); (2*W+1 bits)
    sum_r = (p_rr - p_ii) + (1 << (FRAC_LEN - 1))
    sum_i = (p_ri + p_ir) + (1 << (FRAC_LEN - 1))

    # Mask to 2*W+1 bits to mimic Verilog wire bounds
    sum_r_masked = sum_r & ((1 << (2 * WORD_LEN + 1)) - 1)
    sum_i_masked = sum_i & ((1 << (2 * WORD_LEN + 1)) - 1)

    # Verilog: out_real = sum_real[W-1+F:F];
    shifted_r = sum_r_masked >> FRAC_LEN
    shifted_i = sum_i_masked >> FRAC_LEN

    final_r = sign_extend(shifted_r, WORD_LEN)
    final_i = sign_extend(shifted_i, WORD_LEN)

    # Returns a tuple of (real_fxp, imag_fxp)
    return (
        to_fxp(final_r / (2**FRAC_LEN)), 
        to_fxp(final_i / (2**FRAC_LEN))
    )