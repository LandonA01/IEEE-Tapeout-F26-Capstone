module control (
    input logic [3:0] control_data,
    output logic ALUSrc,
    output logic [2:0] ALUOp,
    output logic RegWrite,
    output logic Branch, 
    output logic [1:0] BranchCond,
    output logic [1:0] FlagUpdate //[1] = Carry, [0] = Zero

);



//ALUOp Encodings
// 000: ADD, ADDI
// 001: SUB, SUBI, CMP
// 010: OR
// 011: XOR
// 100: ADC
// 101: SHL
// 110: MOV
// 111: Reserved (nothing)


always_comb begin

    ALUOp = '0;
    ALUSrc = 1'b0;
    BranchCond = '0;
    RegWrite = 1'b0;
    Branch = 1'b0;
    FlagUpdate = '0;

    case(control_data[3:2])
        2'd0: begin
            case(control_data[1:0]) 
                2'd0: begin
                    ALUOp = 3'b000; // ADD
                    FlagUpdate = 2'b11;
                end
                2'd1: begin
                    ALUOp = 3'b001; // SUB
                    FlagUpdate = 2'b11;
                end
                2'd2: begin 
                    ALUOp = 3'b010; // OR
                    FlagUpdate = 2'b01;
                end
                2'd3: begin
                    ALUOp = 3'b011; // XOR
                    FlagUpdate = 2'b01;
                end
            endcase
            RegWrite = 1'b1;
        end
        2'd1: begin 
            ALUOp = control_data[1] ? 3'b001 : 3'b000; // ADDI, SUBI
            RegWrite = 1'b1;
            ALUSrc = 1'b1;
            FlagUpdate = 2'b11;
        end
        2'd2: begin 
            BranchCond = control_data[1:0];
            Branch = 1'b1;
        end
        2'd3: begin
            case(control_data[1:0])
                2'd0: begin 
                    ALUOp = 3'b001; //CMP
                    FlagUpdate = 2'b11;
                end
                2'd1: begin 
                    ALUOp = 3'b100; // ADC
                    RegWrite = 1'b1;
                    FlagUpdate = 2'b11;
                end
                2'd2: begin 
                    ALUOp = 3'b110; // MOV
                    RegWrite = 1'b1;
                end
                2'd3: begin 
                    ALUOp = 3'b101; //SHL
                    RegWrite = 1'b1;
                    FlagUpdate = 2'b11;
                end
            endcase
        end
    endcase

end


endmodule