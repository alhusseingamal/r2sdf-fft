import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

from config import WORD_LEN, FRAC_LEN

def mask_and_sign_extend(raw, len):
    mask = (1 << len) - 1                                   # mask of 'len' bits
    masked_raw = raw & mask                                 # value represented by first 'len' bits of raw
    sign_bit_mask = (1 << (len-1))                          # mask with a 1 at sign-bit(MSB) and 0 elsewhere
    sign = masked_raw & sign_bit_mask                       # sign value: 0 or 1 followed by (len-1) 0s
    if sign:
        signed_value = masked_raw - (1 << len)              # if sign bit is 1, subtract (2^n) to wrap around and get the -ve value
    else:
        signed_value = masked_raw                           # else, leave as is
    
    ## The previous if condition could actually be replaced by this fancy one-liner bitmasking trick
    ## It is not intuitive but is easily derived from 2's complement math
    # signed_value = (masked_raw & (sign_bit_mask-1)) - (masked_raw & sign_bit_mask)

    return signed_value

class Fxp:
    __slots__ = ('val', 'w', 'f', 'already_scaled')

    def __init__(self, val=None, n_word=WORD_LEN, n_frac=FRAC_LEN, already_scaled=False):
        self.w = n_word
        self.f = n_frac
        self.already_scaled = already_scaled
        self.val = val
        if (val is not None) and (already_scaled == False):
            raw = int(round(val * (1 << self.f)))
            self.val = mask_and_sign_extend(raw, self.w)

    def __float__(self):
        return self.val / float(1 << self.f)

    def __repr__(self):
        return f"{float(self):.6f}"


def to_fxp(val, w=WORD_LEN, f=FRAC_LEN):
    if isinstance(val, complex):
        return (Fxp(val.real, n_word=w, n_frac=f), Fxp(val.imag, n_word=w, n_frac=f))
    if isinstance(val, Fxp):
        return val
    return Fxp(val, n_word=w, n_frac=f)


def from_fxp(obj):
    return float(obj)

def fxp_add(a, b):
    fa = to_fxp(a)
    fb = to_fxp(b)

    sum_val = fa.val + fb.val + 1
    sum_masked = sum_val & ((1 << (WORD_LEN + 1)) - 1)

    shifted = sum_masked >> 1
    final_int = mask_and_sign_extend(shifted, WORD_LEN)

    res = Fxp(val=final_int, n_word=WORD_LEN, n_frac=FRAC_LEN, already_scaled=True)
    return res

def fxp_sub(a, b):
    fa = to_fxp(a)
    fb = to_fxp(b)

    diff_val = fa.val - fb.val + 1
    diff_masked = diff_val & ((1 << (WORD_LEN + 1)) - 1)

    shifted = diff_masked >> 1
    final_int = mask_and_sign_extend(shifted, WORD_LEN)

    res = Fxp(val=final_int, n_word=WORD_LEN, n_frac=FRAC_LEN, already_scaled=True)
    return res

def complex_fxp_mult(a_real, a_imag, b_real, b_imag):

    ar = to_fxp(a_real).val
    ai = to_fxp(a_imag).val
    br = to_fxp(b_real).val
    bi = to_fxp(b_imag).val

    # 2*W bit signed products
    p_rr = ar * br
    p_ii = ai * bi
    p_ri = ar * bi
    p_ir = ai * br

    # Add cross-terms and add half-LSB for round-half-up
    sum_r = (p_rr - p_ii) + (1 << (FRAC_LEN - 1))
    sum_i = (p_ri + p_ir) + (1 << (FRAC_LEN - 1))

    # Mask to wire width [2*W:0], whichi is (2*W + 1)
    sum_r_masked = sum_r & ((1 << (2 * WORD_LEN + 1)) - 1)
    sum_i_masked = sum_i & ((1 << (2 * WORD_LEN + 1)) - 1)

    # Slice [W-1+F : F]
    shifted_r = sum_r_masked >> FRAC_LEN
    shifted_i = sum_i_masked >> FRAC_LEN

    final_r = mask_and_sign_extend(shifted_r, WORD_LEN)
    final_i = mask_and_sign_extend(shifted_i, WORD_LEN)

    out_r = Fxp(val=final_r, n_word=WORD_LEN, n_frac=FRAC_LEN, already_scaled=True)
    out_i = Fxp(val=final_i, n_word=WORD_LEN, n_frac=FRAC_LEN, already_scaled=True)

    return (out_r, out_i)