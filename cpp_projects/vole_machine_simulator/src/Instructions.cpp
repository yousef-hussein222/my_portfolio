#include "Instructions.h"

void Instructions::load1(int regAddress, int memAddress, Register &reg, Memory &mem)
{
    string value = mem.getMemory(memAddress);
    reg.setRegister(regAddress,value);
}
// ========================================================================

void Instructions::load2(int regAddress, const string& value, Register &reg)
{
    reg.setRegister(regAddress,value);
}
// ========================================================================

void Instructions::store(int regAddress, int memAddress, Register &reg, Memory &mem)
{
    mem.setMemory(memAddress,reg.getRegister(regAddress));
    if(memAddress == 0)
    {
        mem.setExpectedOutput(mem.getMemory(memAddress));
    }
}
// ========================================================================

void Instructions::move(int regAddress1, int regAddress2, Register &reg)
{
    string value = reg.getRegister(regAddress1);
    reg.setRegister(regAddress2,value);
}
// ========================================================================

void Instructions::jump(int regAddress, int memAddress, Register &reg, int &PC)
{
    if (reg.getRegister(regAddress) == reg.getRegister(0))
    {
        PC = memAddress;
    }
}
// ========================================================================

void Instructions::halt()
{
    cout << "Reached Instruction \"C000\". Program Finished" << endl;
}