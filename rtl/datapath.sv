module datapath #(parameter DATA_WIDTH = 8, 
                  parameter IMM_WIDTH = 3,
                  parameter REG_COUNT = 4,
                  parameter INSTR_CNT = 4) 
(
    input logic clk, rst_n,
    input logic Readback, Execute,
    input logic [DATA_WIDTH-1:0] instr,
    input logic [$clog2(REG_COUNT)-1:0] read_index,
    output logic [$clog2(INSTR_CNT)-1:0] pc,
    output logic [DATA_WIDTH-1:0] read_data
);


//pc

logic [1:0] branch_target;
logic take_branch;

pc #(.INSTR_CNT(INSTR_CNT)) pc_1
(
    .clk(clk),
    .rst_n(rst_n),
    .take_branch(take_branch),
    .Execute(Execute),
    .branch_target(branch_target),
    .pc(pc)
);


//decode

logic [$clog2(REG_COUNT)-1:0] dst_reg, src_reg;
logic [IMM_WIDTH-1:0] imm;
logic [3:0] control_data;

decode #(.DATA_WIDTH(DATA_WIDTH),
         .IMM_WIDTH(IMM_WIDTH),
         .REG_COUNT(REG_COUNT)) decode_1
(
    .instr(instr),
    .dst_reg(dst_reg), 
    .src_reg(src_reg),
    .imm(imm),
    .branch_target(branch_target),
    .control_data(control_data)   
);


//imm gen

logic [DATA_WIDTH-1:0] imm_ext;

imm_gen #(.DATA_WIDTH(DATA_WIDTH),
          .IMM_WIDTH(IMM_WIDTH)) imm_gen_1
(
    .imm(imm),
    .imm_ext(imm_ext)
);


//register file

logic [$clog2(REG_COUNT)-1:0] rf_dst_reg;
logic [DATA_WIDTH-1:0] ALUResult, ALU_src1, ALU_src2;
logic RegWrite, rf_write_en;

assign rf_write_en = RegWrite & Execute;
assign rf_dst_reg = Readback ? read_index : dst_reg;
assign read_data = ALU_src1;

reg_file #(.DATA_WIDTH(DATA_WIDTH), 
            .REG_COUNT(REG_COUNT)) reg_file_1
 (
    .clk(clk),
    .rst_n(rst_n),
    .RegWrite(rf_write_en),
    .src_reg(src_reg),
    .dst_reg(rf_dst_reg),
    .ALUResult(ALUResult),
    .ALU_src1(ALU_src1),
    .ALU_src2(ALU_src2)
);

//alu

logic ALUSrc, Carry;
logic [2:0] ALUOp;
logic ALUCarryOut;
logic [DATA_WIDTH-1:0] alu_operand_2;

assign alu_operand_2 = ALUSrc ? imm_ext : ALU_src2; 

alu #(.DATA_WIDTH(DATA_WIDTH)) alu_1
(
    .Carry(Carry),
    .ALUOp(ALUOp),
    .ALU_src1(ALU_src1),
    .ALU_src2(alu_operand_2),
    .ALUCarryOut(ALUCarryOut),
    .ALUResult(ALUResult)
);

//branch unit

logic Zero, Branch;
logic [1:0] BranchCond;

branch_unit branch_unit_1 
(
    .Zero(Zero),
    .Carry(Carry),
    .Branch(Branch),
    .BranchCond(BranchCond),
    .take_branch(take_branch)
);

//flag unit

logic [1:0] FlagUpdate, flag_update_en;

assign flag_update_en = FlagUpdate & {2{Execute}};

flags #(.DATA_WIDTH(DATA_WIDTH)) flags_1
 (
    .clk(clk),
    .rst_n(rst_n),
    .FlagUpdate(flag_update_en),
    .ALUCarryOut(ALUCarryOut),
    .ALUResult(ALUResult),
    .Zero(Zero),
    .Carry(Carry)
 );

//control_unit

control control_1 (
    .control_data(control_data),
    .ALUSrc(ALUSrc),
    .ALUOp(ALUOp),
    .RegWrite(RegWrite),
    .Branch(Branch),
    .BranchCond(BranchCond),
    .FlagUpdate(FlagUpdate)
);



endmodule