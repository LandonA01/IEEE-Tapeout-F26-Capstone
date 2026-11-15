# IEEE-Tapeout-F26-Capstone
IEEE Tapeout Fall 2026 Capstone – Landon, Vaishal, Ryan, Aryan

ISA Overview 

Instructions are written in 8 bits, grouped in a 4-register instruction module. Thus for PC-relative addressing, an immediate field of 1 byte is sufficient to move from one instruction to the subsequent instruction. Two bits are allocated for denoting instruction type. 


For register-register type operations, the arithmetic is applied on the inputs of source register and destination register and is entered as output into the destination register (Example: reg_dest = reg_dest (operation) reg_src). 
> 00FFDDSS is a register operation where the first two bits are set to 00, the next FF bits denote an arithmetic operation, the DD bits denote the destination register, and the SS bits denote the source register.

For immediate-type operations, the arithmetic is applied to the input of the source register and immediate field and is entered as output into the destination register. (Example: reg_dest = reg_dest (operation) imm). 
> 01DDIIII is an immediate operation where the first two bits are set to 01, the next DD bits denote the destination register, and the next IIII bits are the immediate field. 

For branching operations, all potential branches and jumps are lumped into the four possible options: 00 JMP, 01 BZ, 10 BNZ, 11 BC. 
> 10CCTTXX is a branching operation where the first two bits are set to 10, the next CC bits denote the one of the four possible branching options as described above, the next TT bits denote the target instruction if the branch succeeds, and the next XX bits are don't cares. 
