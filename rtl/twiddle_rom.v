`include "definitions.vh"
module twiddle_rom #(
    parameter W = 16,
    parameter N = 8
)(
    input  wire [$clog2(N/2)-1:0] addr,
    output wire signed [W-1:0] twiddle_real,
    output wire signed [W-1:0] twiddle_imag
);

    // memory for N/2 complex points
    reg signed [2*W-1:0] rom_data [0 : (N/2)-1];   // real and imaginary parts are packed into one row

    // load the pre-calculated twiddle factors from hex file
    initial begin
        $readmemh(`TWIDDLE_FACTORS_FILE, rom_data);
    end

    // Combinational read
    wire [2*W-1:0] current_val = rom_data[addr];

    // Split the packed data back into real and imaginary
    assign twiddle_real = current_val[2*W-1 : W];
    assign twiddle_imag = current_val[W-1   : 0];

endmodule
