#include "CPU.h"

CPU::CPU() : programCounter(10) {}

// ========================================================================

void CPU::fetch(Memory& memory)
{
    instructionRegister = memory.getMemory(programCounter);
    programCounter++;
    instructionRegister += memory.getMemory(programCounter);
    programCounter++;
}
// ========================================================================

vector<int> CPU::decode()
{
    vector<int> decoded;
    int opcode = stoi(instructionRegister.substr(0, 1) , nullptr,16);
    decoded.push_back(opcode);
    for (int i = 1; i < instructionRegister.length(); i++)
    {
        decoded.push_back( stoi(instructionRegister.substr(i, 1) , nullptr,16) );
    }
    return decoded;
}
// ========================================================================

void CPU::execute(Memory& memory, vector<int> decoded)
{
    int opcode = decoded[0];
    if(opcode == 1)
    {
        instruct.load1(decoded[1], decoded[2] * 16 + decoded[3], reg, memory);
    }
    else if(opcode == 2)
    {
        stringstream ss;
        ss << hex << decoded[2] << decoded[3];
        string sendValue = ss.str();
        transform(sendValue.begin(),sendValue.end(),sendValue.begin(),::toupper);
        instruct.load2(decoded[1], sendValue, reg);
    }
    else if(opcode == 3)
    {
        instruct.store(decoded[1], decoded[2] * 16 + decoded[3], reg, memory);
    }
    else if(opcode == 4)
    {
        instruct.move(decoded[2], decoded[3], reg);
    }
    else if(opcode == 5)
    {
        alu.addHexNumbers(decoded[1], decoded[2], decoded[3], reg);
    }
    else if(opcode == 6)
    {
        alu.addFloatPointNumber(decoded[1],decoded[2],decoded[3], reg);
    }
    else if(opcode == 11)
    {
        instruct.jump(decoded[1], decoded[2] * 16 + decoded[3], reg, programCounter);
    }
    else if(opcode == 12)
    {
        instruct.halt();
    }
    else
    {
        cout << "Invalid opcode: " << opcode << endl;
    }
}
// ========================================================================

void CPU::runNextStep(Memory& memory,int& state)
{
    if(state == 1)
    {
        while(true)
        {
            fetch(memory);
            if (instructionRegister == "C000")
            {
                break;
            }
            vector<int> decoded = decode();
            execute( memory, decoded);
            cout <<"======================================="<<endl;
            cout << "********* Memory Content *********"<<endl;
            memory.printMemoryStatus();
            cout << "********* Register Content *********"<<endl;
            reg.printRegisterStatus();
        }
    }
    else if(state == 2)
    {
        while(true)
        {
            fetch(memory);
            if (instructionRegister == "C000")
            {
                break;
            }
            vector<int> decoded = decode();
            execute(memory, decoded);
        }
    }
}
// ========================================================================

Register& CPU::callRegister()
{
    return reg;
}
// ========================================================================

int& CPU::getProgramCounter()
{
    return programCounter;
}