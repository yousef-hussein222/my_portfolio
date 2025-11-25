#ifndef VOLE_MACHINE_TEST2_VOLEMACHINE_H
#define VOLE_MACHINE_TEST2_VOLEMACHINE_H

#include "CPU.h"
#include "Memory.h"
#include<fstream>

class VoleMachine {
private:
    CPU processor;
    Memory memory;
public:
    int state = 0;
    string validExtension ();
    void loadProgramFile();
    void print_memory ();
    void print_register ();
};


#endif //VOLE_MACHINE_TEST2_VOLEMACHINE_H
