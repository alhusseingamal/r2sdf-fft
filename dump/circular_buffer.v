module circular_buffer #(parameter W = 16, DEPTH = 4) (
    input clk, 
    input reset_n, 
    input en, 

    input signed [W-1:0] in_real, 
    input signed [W-1:0] in_imag, 
    
    output signed [W-1:0] out_real, 
    output signed [W-1:0] out_imag
);

reg signed [W-1:0] mem_real [0:DEPTH-1];
reg signed [W-1:0] mem_imag [0:DEPTH-1];

// pointer
localparam PTR_WIDTH = (DEPTH == 1 ? 1 : $clog2(DEPTH));
reg [PTR_WIDTH-1:0] ptr;
wire [PTR_WIDTH-1:0 ] safe_addr = (DEPTH == 1 ? 0 : ptr);
// if DEPTH=1, PTR_WIDTH=1, that means ptr=0 or ptr=1
// But we have only 1 place in memory (at position 0 -> ptr=0), so we need to exclude the case when ptr=1 
// bec. that would be an out-of-bound access. So for the case where DEPTH=1, we fix safe_addr to always be 0

assign out_real = mem_real[safe_ayddr];
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


endmodule