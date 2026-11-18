module imm_gen #(parameter DATA_WIDTH = 8,
                 parameter IMM_WIDTH = 3
                 )
(
    input logic [IMM_WIDTH-1:0] imm, //instr[2:0]
    output logic [DATA_WIDTH-1:0] imm_ext
);


//number of bits to concatenate
localparam int N = DATA_WIDTH - IMM_WIDTH;




always_comb begin
    imm_ext = {{N{1'b0}}, imm};
end



endmodule