import cocotb  
import random
from cocotb.triggers import Timer


#ALU Golden Reference Model

def alu_model(op, a, b, carry):
    if op == 0: # ADD, ADDI
        result = a + b
        return result & 0xFF, result >> 8
    elif op == 1: # SUB, SUBI, CMP
        result = a - b
        return result & 0xFF, int(a>=b)
    elif op == 2: # OR
        return a | b, 0
    elif op == 3: # XOR
        return a ^ b, 0
    elif op == 4: # ADC
        result = a + b + carry
        return result & 0xFF, result >> 8
    elif op == 5: # SHL
        return (a << 1) & 0xFF, (a >> 7) & 1
    elif op == 6: # MOV
        return b, 0
    
    raise ValueError("Invalid ALUOp")




#Reusable ALU Test Function

async def check_alu(dut, op, a, b, carry):

    dut.ALUOp.value = op
    dut.ALU_src1.value = a
    dut.ALU_src2.value = b
    dut.Carry.value = carry

    # Allow RTL time to evaluate

    await Timer(1, unit="ns")

    # Calculate expected outputs
    expected_result, expected_carry = alu_model(op, a, b, carry)

    # Read actual outputs
    actual_result = int(dut.ALUResult.value)
    actual_carry = int(dut.ALUCarryOut.value)

    assert actual_result == expected_result, (
        f"ALUOp = {op}, A = {a}, B = {b}, CarryIn = {carry}: "
        f"Expected result = {expected_result}, got = {actual_result}"
    )

    assert actual_carry == expected_carry, (
        f"ALUOp = {op}, A = {a}, B = {b}, CarryIn = {carry}: "
        f"Expected carry = {expected_carry}, got = {actual_carry}"
    )
    



@cocotb.test()
async def test_edge_cases(dut):

    cases = [
        #op, A, B, CarryIn

        (0, 0, 0, 0), # ADD Zero
        (0, 255, 1, 0), # ADD Overflow
        (0, 255, 255, 0), # ADD max operands

        (1, 5, 3 , 0), # SUB without borrow
        (1, 3, 5, 0), # SUB with borrow
        (1, 0, 0, 0), # SUB equal operands

        (2, 0xAA, 0x55, 0), #OR
        (3, 0xFF, 0xFF, 0), # XOR produces 0 

        (4, 255, 0, 1), # ADC carry-in
        (4, 255, 255, 1), # ADC overflow

        (5, 1, 3, 0), # SHL
        (6, 123, 45, 0) # MOV
    ]

    for op, a, b, carry in cases:
        await check_alu (dut, op, a, b, carry)


@cocotb.test()
async def test_random(dut):
    rng = random.Random(42)

    for op in range(7):
        for i in range(1000):
            a = rng.randint(0, 255)
            b = rng.randint(0, 255)
            carry = rng.randint(0, 1)

            await check_alu(dut, op, a, b, carry)


    # need to: finish basic testing of all units thus far
    # finish design
    # tomorrow: finish comprehensive verification of whole datapath