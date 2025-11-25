#ifndef VOLE_MACHINE_TEST2_INSTRUCTIONS_H
#define VOLE_MACHINE_TEST2_INSTRUCTIONS_H

#include "Register.h"
#include "Memory.h"

class Instructions {
public:
    void load1(int regAddress,int memAddress,Register& reg,Memory& mem);
    void load2(int regAddress,const string& value,Register& reg);
    void store(int regAddress,int memAddress,Register& reg,Memory& mem);
    void move(int regAddress1,int regAddress2,Register& reg);
    void jump(int regAddress,int memAddress,Register& reg,int& PC);
    void halt();
};


#endif //VOLE_MACHINE_TEST2_INSTRUCTIONS_H
