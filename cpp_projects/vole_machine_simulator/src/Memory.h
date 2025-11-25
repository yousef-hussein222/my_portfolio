#ifndef VOLE_MACHINE_TEST2_MEMORY_H
#define VOLE_MACHINE_TEST2_MEMORY_H

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class Memory {
private:
    string memory[256];
    vector<string>expectedOutput;
public:
    Memory();
    void setMemory(int address,const string& value);
    string getMemory(int address);
    void printMemoryStatus();
    void setExpectedOutput(const string& val);
    void printExpectedOutput();
};

#endif //VOLE_MACHINE_TEST2_MEMORY_H
