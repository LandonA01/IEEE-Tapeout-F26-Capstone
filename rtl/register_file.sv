module reg_file #(parameter DATA_WIDTH = 8, 
                  parameter REG_COUNT = 4) 
                  (
    input logic clk, rst_n,
    input logic RegWrite,
    input logic [$clog2(REG_COUNT)-1:0] src_reg, dst_reg, //instr[1:0] and instr[3:2]
    input logic [DATA_WIDTH-1:0] ALUResult,
    output logic [DATA_WIDTH-1:0] ALU_src1, ALU_src2
);


logic [DATA_WIDTH-1:0] rf [REG_COUNT-1:0]; //4, 8-bit registers


//Write logic

//If RegWrite == 1, write ALUResult
//Else, keep previous value of register (no update)

always_ff @(posedge clk) begin
    if (!rst_n) begin
        for (int i = 0; i < REG_COUNT; i++) begin
            rf[i] <= '0;
        end
    end else begin
        if (RegWrite) rf[dst_reg] <= ALUResult;
    end
end


//Read Logic

always_comb begin
    ALU_src1 = rf[rf_dst_reg];
    ALU_src2 = rf[src_reg];
end






endmodule