module flags #(parameter DATA_WIDTH = 8)
 (
    input logic clk, rst_n,
    input logic [1:0] FlagUpdate, //[1] --> CWrite, [0] --> ZWrite
    input logic ALUCarryOut,
    input logic [DATA_WIDTH-1:0] ALUResult,
    output logic Zero, Carry
 );



always_ff @(posedge clk) begin
    if (!rst_n) begin
        Zero <= 1'b0;
        Carry <= 1'b0;
    end else begin
        if (FlagUpdate[0]) Zero <= (ALUResult == '0);

        if (FlagUpdate[1]) Carry <= ALUCarryOut;
    end
end



endmodule