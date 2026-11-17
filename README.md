# IEEE-Tapeout-F26-Capstone
IEEE Tapeout Fall 2026 Capstone – Landon, Vaishal, Ryan, Aryan

## ISA Overview

8-bit ISA. Supports 14 instructions of 4 types (R-Type, I-Type, B-Type, J-Type). Branching is absolute, as opposed to PC-relative All decisions made with the intention of optimizing PPA, particularly Area due to the tight constraint. Instruction formats and encodings are detailed below, along with a block diagram of the microarchitecture.


<br> <br>

Instructions are written in 8 bits, grouped in a 4-register instruction module. For jumps, absolute branching will be used over PC-relative addressing since there are only 4 instructions in instruction module. Simply setting the bits of the target address will reduce the area used on the chip. Two bits are allocated for denoting instruction type.

For register-register type operations, the arithmetic is applied on the inputs of source register and destination register and is entered as output into the destination register (Example: reg_dest = reg_dest (operation) reg_src).

00FFDDSS is a register operation where the first two bits are set to 00, the next FF bits denote an arithmetic operation, the DD bits denote the destination register, and the SS bits denote the source register.

For immediate-type operations, the arithmetic is applied to the input of the source register and immediate field and is entered as output into the destination register. (Example: reg_dest = reg_dest (operation) imm).

01DDIIII is an immediate operation where the first two bits are set to 01, the next DD bits denote the destination register, and the next IIII bits are the immediate field.

For branching operations, all potential branches and jumps are lumped into the four possible options: 00 JMP, 01 BZ, 10 BNZ, 11 BC.

10CCTTXX is a branching operation where the first two bits are set to 10, the next CC bits denote the one of the four possible branching options as described above, the next TT bits denote the target instruction if the branch succeeds, and the next XX bits are don't cares.

<br>

### Microarchitecture Diagram

<img src="https://cdn.phototourl.com/anon/2026-11-17-2601a975-0a80-44e3-83fc-df146591bef1.png" alt="Description" width="773" height="495">


<br>

### R-Type Instructions

| Format Bits | Funct3 | Destination Register | Source Register |
| ------------- | ------------- | ------------- | ------------- |
| 00 | instr[5:4] | instr[3:2] | instr[1:0] |


| Instruction | Funct3 | Operation | 
| ------------- | ------------- | ---------- |
| ADD  | 00 | `reg[dst] = reg[dst]  + reg[src]` | 
| SUB | 01  | `reg[dst] = reg[dst] - reg[src]`|
| OR | 10 | `reg[dst] = reg[dst] \| reg[src]` |
| XOR | 11 | `reg[dst] = reg[dst] ^ reg[src]` |

<br>

### I-Type Instructions

| Format Bits | Funct3 | Destination Register | Immediate |
| ------------- | ------------- | ------------- | ------------- |
| 01 | instr[5] | instr[4:3] | instr[2:0] |


| Instruction | Funct3 | Operation |
| ----------- | ------------- | ---------- |
| ADDI | 0 | `reg[dst] = reg[dst] + imm` |
| SUBI | 1 | `reg[dst]  = reg[dst] - imm` |

<br>

### B-Type (and J-Type) Instructions 

| Format Bits | Branch Condition | Branch Target | Don't Care (X) |
| ------------- | ------------- | ------------- | ------------- |
| 10 | instr[5:4] | instr[3:2] | instr[1:0] |

| Instruction | Branch Condition | Operation |
| ----------- | ------------- | ---------- | 
| JMP | 00 | `pc = pc + target` |
| BZ | 01 | `if (zero) pc = pc + target` |
| BNZ | 10 |  `if (!zero) pc = pc + target` |
| BC | 11 | `if (carry) pc = pc + target` |

<br>

### Special Instructions (Also R-Type)

| Format Bits | Funct3 | Destination Register | Source Register |
| ------------- | ------------- | ------------- | ------------- |
| 11 | instr[5:4] | instr[3:2] | instr[1:0] |

| Instruction | Funct3 | Operation
| ----------- | ------------- | ---------- |
| CMP | 00 | `reg[dst] - reg[src]` |
| ADC | 01 | `reg[dst] = reg[dst] + reg[src] + carry` |
| MOV | 10 | `reg[dst] = reg[src]` |
| SHL | 11 | `reg[dst] = reg[dst] << reg[src]` |


Clarification: ADC must follow a preceding ADD. ADC involves the upper 8 bits of the 16-bit operation, while ADD encompasses the lower 8 bits. Thus, we use the Carry from that preceding add.  The 16-bit result is {ADC dst, ADD dst}.
