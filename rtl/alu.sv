module alu #(parameter DATA_WIDTH = 8)
(
    input logic Carry, 
    input logic [2:0] ALUOp,
    input logic [DATA_WIDTH-1:0] ALU_src1, ALU_src2,
    output logic ALUCarryOut,
    output logic [DATA_WIDTH-1:0] ALUResult
);



//14 instructions 
// ADD, SUB, CMP, OR, XOR, ADDI, SUBI, JMP, BZ, BNZ, BC, ADC, SHL, MOV
// ADD, SUB, OR, XOR, ADC, SHL, MOV --> 3 bits for ALUOp

//ALUOp Encodings
// 000: ADD, ADDI
// 001: SUB, SUBI, CMP
// 010: OR
// 011: XOR
// 100: ADC
// 101: SHL
// 110: MOV
// 111: Reserved (nothing)


//Note: Our branch instructions do not need to perform any computations in the ALU, they simply use the respective Flag


always_comb begin
      ALUResult = '0;
      ALUCarryOut = 0;
    case (ALUOp)
        3'd0: {ALUCarryOut,ALUResult} = {1'b0, ALU_src1} + {1'b0, ALU_src2};
        3'd1: {ALUCarryOut, ALUResult} = {1'b0, ALU_src1} + {1'b0, ~ALU_src2} + 9'd1; //A - B = A + (-B)
        3'd2: ALUResult = ALU_src1 | ALU_src2;
        3'd3: ALUResult = ALU_src1 ^ ALU_src2;
        3'd4: {ALUCarryOut, ALUResult} = {1'b0, ALU_src1} + {1'b0, ALU_src2} + Carry;
        3'd5: begin 
            ALUResult = ALU_src1 << 1; //only supporting 1 bit shift for area and complexity reasons
            ALUCarryOut = ALU_src1[DATA_WIDTH-1];
        end
        3'd6: ALUResult = ALU_src2;
    endcase

end


endmodule