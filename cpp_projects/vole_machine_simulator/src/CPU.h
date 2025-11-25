#ifndef VOLE_MACHINE_TEST2_CPU_H
#define VOLE_MACHINE_TEST2_CPU_H

#include<iostream>
#include<sstream>
#include<algorithm>
#include "Register.h"
#include "ALU.h"
#include "Instructions.h"
using namespace std;

class CPU {
private:
    int programCounter;
    string instructionRegister;
    Register reg;
    ALU alu;
    Instructions instruct;
public:
    CPU();
    void fetch(Memory& memory);
    vector<int> decode();
    void execute(Memory& memory, vector<int> decoded);
    void runNextStep(Memory& memory,int& state);
    Register& callRegister();
    int& getProgramCounter();
};


#endif //VOLE_MACHINE_TEST2_CPU_H
