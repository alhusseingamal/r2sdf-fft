module circular_buffer #(parameter W = 16, DEPTH = 4) (
    input clk, 
    input reset_n, 
    input en, 

    input signed [W-1:0] in_real, 
    input signed [W-1:0] in_imag, 
    
    output reg signed [W-1:0] out_real, 
    output reg signed [W-1:0] out_imag
);

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
        // memory arrays
        (* ram_style = "block" *) reg signed [W-1:0] mem_real [0:DEPTH-1];
        (* ram_style = "block" *) reg signed [W-1:0] mem_imag [0:DEPTH-1];
        
        localparam PTR_WIDTH = $clog2(DEPTH);
        reg [PTR_WIDTH-1:0] ptr;
        wire [PTR_WIDTH-1:0 ] lookahead_addr = ptr+1;    // lookahead addr
        
        // Block 1: pointer control (needs async reset)
        always @(posedge clk or negedge reset_n) begin
            if (reset_n == 1'b0) begin
                ptr <= 0;
            end else if (en == 1'b1) begin
                ptr <= lookahead_addr;
            end
        end
        // Block 2: BRAM interface (synchronous reads and writes, no async resets)
        always @(posedge clk) begin
            if (en == 1'b1) begin
                mem_real[lookahead_addr] <= in_real;
                mem_imag[lookahead_addr] <= in_imag;

                out_real <= mem_real[lookahead_addr+1];
                out_imag <= mem_imag[lookahead_addr+1];
            end
        end
    end
endgenerate

endmodule
