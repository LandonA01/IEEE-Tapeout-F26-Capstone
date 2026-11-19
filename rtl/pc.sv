module pc (
    input logic clk, rst_n,
    input logic take_branch,
    input logic [1:0] branch_target,
    output logic [1:0] pc
);


logic [1:0] pc_next;

always_ff @(posedge clk) begin
    if (!rst_n) begin
        pc <= '0;
    end else begin
        pc <= pc_next;
    end
end


assign pc_next = take_branch ? branch_target : (pc + 1);


endmodule