#ifndef VOLE_MACHINE_TEST2_REGISTER_H
#define VOLE_MACHINE_TEST2_REGISTER_H

#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

class Register {
private:
    string registers[16];
public:
    Register();
    void setRegister(int address,const string& value);
    string getRegister(int address);
    void printRegisterStatus();
};


#endif //VOLE_MACHINE_TEST2_REGISTER_H
