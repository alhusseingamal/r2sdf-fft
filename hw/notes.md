# Verilog Utilities & FFT Signal Timing

## `$bits()` Built-in Function

The `$bits()` function evaluates to the bit-width of a given signal. The syntax `$bits(rom_addr)'(...)` forces the mathematical result of the term inside brackets to be exactly the same size as `rom_addr`.

---

## Valid Output Signal Timing Mismatch

### The Problem

The `valid_out` signal, unlike the data signal, **does not go through** the delay buffer in an SDF stage. This creates a timing disconnect:

- **Data signal**: Takes $1 + (N-1) + P_{total}$ cycles to appear at output
- **Valid signal**: Takes only $1 + P_{total}$ cycles (skips the delay buffer)

Result: The data signal and its corresponding `valid_out` signal arrive at different times.

### Three Solutions

#### 1. **Hardware Solution** (Impractical)
Add shift registers to delay `valid_out` to match the data signal delay:
- The data signal has an extra $N-1$ cycle delay compared to `valid_out`
- Requires $N-1$ 1-bit shift registers for synchronization
- **Example**: For $N=4096$, this means **4095 shift registers** → massive hardware overhead

#### 2. **Software Solution** (Most Common)
Shift the responsibility to the software driver:
- The driver knows the hardware IP takes $N-1$ cycles to flush
- When `valid_out` goes high, **ignore the first** $N-1$ numbers
- Start saving data to memory on the **$N$-th number**
- Works well with known FFT configurations (e.g., $N=8$)

#### 3. **Modern Solution** (AXI4-Stream Protocol)
Use a `TLAST` signal instead of flagging the start:
- Flag the **end** of the frame with a `TLAST` wire instead of the beginning
- `TLAST` is tied to actual data calculation, so it flows naturally through the pipeline
- When software sees `TLAST` go high: "The number I just received is the final bin, so the previous $N$ numbers were valid"
---

## BRAMs and Synchronous Reads

### Why Synchronous Reads Matter

**Key Constraint**: FPGA BRAMs can only be read **synchronously**.

**Problem with asynchronous reads**: When you write code like:
```verilog
assign out_real = mem_real[safe_addr];
```

The synthesis tool **cannot** use BRAM resources. Instead, it must build the memory using:
- **LUTs** (Look-Up Tables), or
- **Distributed RAM**

For large memories, this is problematic since LUTs are limited. **Synchronous reads are preferred** because they enable BRAM inference—but they incur a **1-cycle overhead** compared to asynchronous reads.

### Example: Circular Buffer with Asynchronous Read

Starting with the basic (broken) approach:

```verilog
reg signed [W-1:0] mem_real [0:DEPTH-1];
reg signed [W-1:0] mem_imag [0:DEPTH-1];

// Pointer
localparam PTR_WIDTH = (DEPTH == 1 ? 1 : $clog2(DEPTH));
reg [PTR_WIDTH-1:0] ptr;
wire [PTR_WIDTH-1:0] safe_addr = (DEPTH == 1 ? 0 : ptr);
// Note: When DEPTH=1, PTR_WIDTH=1 (ptr can be 0 or 1)
// But memory only has 1 location (index 0), so safe_addr=0 prevents out-of-bounds

assign out_real = mem_real[safe_addr];  // Asynchronous read
assign out_imag = mem_imag[safe_addr];

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        ptr <= 0;
    end else if (en == 1'b1) begin
        mem_real[safe_addr] <= in_real;
        mem_imag[safe_addr] <= in_imag;
        ptr <= ptr + 1'b1;
    end
end
```

❌ **Problem**: This creates asynchronous reads, so synthesis uses LUTs instead of BRAMs.

### Converting to Synchronous Reads (Naïve Approach)

Simply changing `assign` to `always @(posedge clk)`:

```verilog
reg signed [W-1:0] mem_real [0:DEPTH-1];
reg signed [W-1:0] mem_imag [0:DEPTH-1];

localparam PTR_WIDTH = (DEPTH == 1 ? 1 : $clog2(DEPTH));
reg [PTR_WIDTH-1:0] ptr;
wire [PTR_WIDTH-1:0] safe_addr = (DEPTH == 1 ? 0 : ptr);

always @(posedge clk or negedge reset_n) begin
    if (reset_n == 1'b0) begin
        ptr <= 0;
    end else if (en == 1'b1) begin
        mem_real[safe_addr] <= in_real;
        mem_imag[safe_addr] <= in_imag;

        out_real <= mem_real[safe_addr];   // Now synchronous (registered)
        out_imag <= mem_imag[safe_addr];

        ptr <= ptr + 1'b1;
    end
end
```

✅ **Advantage**: Synthesis can now infer BRAM.  
❌ **Major Problem**: This **breaks the math**!

### Why This Breaks: The DEPTH=4 Example

If your circular buffer should delay data by exactly 4 cycles (DEPTH=4):

1. Pointer reaches address 0
2. Clock ticks
3. Memory begins fetching data
4. Data arrives at output on **next** clock cycle
5. **Total delay = 5 cycles** (not 4!)

Since SDF FFT relies on **perfectly synchronized data streams**, an accidental $DEPTH+1$ delay will **misalign the Cooley-Tukey butterfly pairs**, producing garbage output.

### Solution: Address-Lookahead Trick

To compensate for the 1-cycle BRAM latency, **read from the address 1 cycle early**:
- Instead of reading from current address, read from `addr+1`

### The DEPTH=1 Edge Case

A synchronous RAM block requires a **minimum of 2 clock cycles** to write then read back. Therefore, you **cannot build a 1-cycle delay using BRAM**—it would require a standard **D-Flip-Flop** instead.

For `DEPTH=1`, we bypass the RAM array and register the input directly.

### Correct Implementation with Lookahead

```verilog
generate
    if (DEPTH==1) begin: gen_depth_1
        // DEPTH=1: Just use D-Flip-Flops
        always @(posedge clk or negedge reset_n) begin
            if (reset_n == 1'b0) begin
                out_real <= 0;
                out_imag <= 0;
            end else if (en == 1'b1) begin
                out_real <= in_real;
                out_imag <= in_imag;
            end
        end
    end else begin: gen_depth_n
        // DEPTH>1: Use BRAM with lookahead
        reg signed [W-1:0] mem_real [0:DEPTH-1];
        reg signed [W-1:0] mem_imag [0:DEPTH-1];
        
        localparam PTR_WIDTH = $clog2(DEPTH);
        reg [PTR_WIDTH-1:0] ptr;
        
        wire [PTR_WIDTH-1:0] lookahead_addr = ptr + 1;  // Read 1 cycle early
        
        always @(posedge clk or negedge reset_n) begin
            if (reset_n == 1'b0) begin
                ptr <= 0;
                out_real <= 0;
                out_imag <= 0;
            end else if (en == 1'b1) begin
                mem_real[lookahead_addr] <= in_real;
                mem_imag[lookahead_addr] <= in_imag;

                out_real <= mem_real[lookahead_addr + 1];
                out_imag <= mem_imag[lookahead_addr + 1];

                ptr <= lookahead_addr;
            end
        end
    end
endgenerate
```

### The Asynchronous Reset Pitfall 🚨

There's a critical issue with the previous code:

```verilog
always @(posedge clk or negedge reset_n) begin
    if (!reset_n) begin
        out_real <= 0;  // <-- THE PROBLEM
```

You're asking the hardware to **asynchronously reset the BRAM output** the moment `reset_n` goes low, independent of the clock.

**Physical limitation**: FPGA BRAM blocks do **not have asynchronous reset pins** on their output registers—only synchronous resets (if any).

**Synthesis consequence**: The synthesizer says: *"I cannot do this with BRAM, so I'll build it from 8,000 Flip-Flops instead"*—defeating the purpose of using BRAM!

### The Fix: Remove Reset from BRAM Outputs

We don't need to reset the memory data outputs because:
- **In DSP pipelines**, we don't care if memory holds garbage on reset
- The `valid_out` signal **prevents** downstream logic from reading it anyway

```verilog
generate
    if (DEPTH==1) begin: gen_depth_1
        always @(posedge clk or negedge reset_n) begin
            if (reset_n == 1'b0) begin
                out_real <= 0;
                out_imag <= 0;
            end else if (en == 1'b1) begin
                out_real <= in_real;
                out_imag <= in_imag;
            end
        end
    end else begin: gen_depth_n
        // Memory Arrays
        reg signed [W-1:0] mem_real [0:DEPTH-1];
        reg signed [W-1:0] mem_imag [0:DEPTH-1];

        localparam PTR_WIDTH = $clog2(DEPTH);
        reg [PTR_WIDTH-1:0] ptr;
        
        wire [PTR_WIDTH-1:0] lookahead_addr = (ptr == DEPTH - 1) ? 0 : (ptr + 1'b1);

        // Block 1: Pointer Control (Needs async reset)
        always @(posedge clk or negedge reset_n) begin
            if (!reset_n) begin
                ptr <= 0;
            end else if (en) begin
                ptr <= lookahead_addr;
            end
        end

        // Block 2: BRAM Inference (NO RESET ON OUTPUTS!)
        always @(posedge clk) begin
            if (en) begin
                // Write
                mem_real[ptr] <= in_real;
                mem_imag[ptr] <= in_imag;

                // Synchronous Read (Lookahead)
                out_real <= mem_real[lookahead_addr];
                out_imag <= mem_imag[lookahead_addr];
            end
        end
    end
endgenerate
```

**Key improvements**:
- ✅ Block 1: Controls pointer with async reset (can use Flip-Flops)
- ✅ Block 2: Pure BRAM inference—no resets on outputs, only synchronous control
- ✅ Lookahead addressing compensates for BRAM 1-cycle latency
- ✅ `valid_out` signal handles garbage data on reset



**Synthesis for Xilinx Platform**:
```bash
synth_xilinx -top top_level
```
- Number of total Cells decreases.  
- Because Xilinx, has dedicated DSP48 slices, Yosys recognized the complex_multiplier submodules and mapped them directly into those DSP slices.
    That is why 70,000 standard logic gates instantly vanished from the synthesis report.
- Number of used Flip-flops decreases.  
- Distributed RAM (LUTRAM) (RAM32M and RAM64M) are now used.  
- BRAM (RAMB18E1) was not used because depths are too shallow (N=256 is still very shallow), so the synthesis tool decided that LUTRAM is more efficient to use here.  
- 
You can use a synthesis directive (attribute) in your Verilog to force Yosys to use Block RAM, even if the memory is tiny. Add this line right above your memory array declarations in  
```verilog
(* ram_style = "block" *) reg signed [W-1:0] mem_real [0:DEPTH-1];
(* ram_style = "block" *) reg signed [W-1:0] mem_imag [0:DEPTH-1];
```

You can now observe yosys synthesis report to see the usage of BRAM (RAMB18E1).  






## Reorder Buffer for FFT Output?

Is a reorder buffer necessary? In most DSP designs, the answer is: **no**.

### Why bit-reversed output is often acceptable

- Professional DSP practice commonly leaves FFT output in **bit-reversed order**.
- Commercial FFT IP cores usually offer an option for **Output Ordering**: Natural or Bit/Digit Reversed.

### Why a reorder buffer is optional

1. **Heavy silicon cost**
   - Reordering requires buffering the full FFT frame.
   - That means an extra **$N$-deep dual-port memory block**.
   - For $N=4096$, this is a large BRAM penalty.
   - It also adds **$N$ cycles of latency**.

2. **Software can do it cheaply**
   - If the FFT feeds a CPU or host, the data is already being read into memory.
   - A CPU can unscramble a bit-reversed array in software with a few lines of code.
   - So hardware often avoids wasting area and power on this task.

3. **Symmetric DSP chains remove the need entirely**
   - In systems like Wi-Fi or 5G, the FFT receiver and IFFT transmitter are paired.
   - An IFFT can be designed to accept bit-reversed inputs and produce sequential outputs.
   - This lets designers wire the FFT output directly into the IFFT input without any reorder buffer.

### Bottom line

A reorder buffer is useful only if the next stage strictly requires natural order. Otherwise, leaving the FFT output bit-reversed is usually the smaller, cheaper design choice.