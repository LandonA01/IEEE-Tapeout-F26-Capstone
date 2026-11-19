module branch_unit (
    input logic Zero, Carry,
    input logic Branch,
    input logic [1:0] BranchCond,
    output logic take_branch
);


logic branch_condition;

always_comb begin

    case(BranchCond)
        2'd0: branch_condition = 1'b1;
        2'd1: branch_condition  = Zero;
        2'd2: branch_condition = ~Zero;
        2'd3: branch_condition = Carry;
    endcase

    take_branch = branch_condition & Branch;

end


endmodule
