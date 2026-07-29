import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

from collections import deque
from model.butterfly import *
from config import *
class SDFStage:
    def __init__(self, n_fft, stage_index):
        """
        Initializes a Single-path Delay Feedback stage.
        """
        self.delay_len = n_fft // (2**(stage_index+1))   # delay_len is the buffer length, assuming stage indexing starts at 0
        
        # Initialize the delay buffer (deque) with zeros.
        self.buffer = deque([ComplexFxp(0,0)] * self.delay_len, maxlen=self.delay_len)
        
        # State machine counter
        self.counter = 0 
        
    # each stage spends the 1st half in OFF mode (Fill/Flush phase), and 2nd half in ON mode (Compute phase)
    def process_sample(self, input_sample, twiddle):
        if self.counter < self.delay_len:
            # Fill phase: push input_sample into buffer
            output = self.buffer.popleft()
            self.buffer.append(input_sample)
        else:
            # Butterfly phase: pop delayed_sample, compute butterfly, feedback B_out
            delayed_sample = self.buffer.popleft()
            A_out, B_out = bit_true_butterfly(delayed_sample, input_sample, twiddle)
            self.buffer.append(B_out)  # Feedback B_out into buffer
            output = A_out
        
        # Increment and wrap self.counter
        self.counter = (self.counter + 1) % (2 * self.delay_len)
        
        return output