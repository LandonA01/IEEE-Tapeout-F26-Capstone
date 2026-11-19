module decode #(parameter DATA_WIDTH = 8,
                parameter IMM_WIDTH = 3,
                parameter REG_COUNT = 4)
(
    input logic [DATA_WIDTH-1:0] instr,
    output logic [$clog2(REG_COUNT)-1:0] dst_reg, src_reg,
    output logic [IMM_WIDTH-1:0] imm,
    output logic [1:0] branch_target,
    output logic [3:0] control_data       //format type, funct3, and branch cond for control signal generation
);


always_comb begin

    dst_reg = '0;
    src_reg = '0;
    imm = '0;
    branch_target = 2'b00;
    control_data = instr[7:4];

    case(instr[7:6]) 
        2'd0: begin
            dst_reg = instr[3:2];
            src_reg = instr[1:0];   
        end
        2'd1: begin
            dst_reg = instr[4:3];
            imm = instr[2:0];
        end
        2'd2: begin
            branch_target = instr[3:2];
        end
        2'd3: begin
            dst_reg = instr[3:2];
            src_reg = instr[1:0];
        end
    endcase

end



endmodule
