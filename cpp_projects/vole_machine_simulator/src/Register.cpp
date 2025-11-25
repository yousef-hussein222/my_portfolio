#include "Register.h"

// empty Constructor
Register::Register()
{
    for(int i = 0;i<16;i++)
    {
        registers[i] = "00";
    }
}
// =============================================================

void Register::setRegister(int address,const string& value)
{
    if(address >= 0)
    {
        registers[address] = value;
    }
}
// =============================================================

string Register::getRegister(int address)
{
    if(address >= 0)
    {
        return registers[address];
    }
    return "Invalid Address";
}
// =============================================================

void Register::printRegisterStatus()
{
    for(int i = 0;i<16;i++)
    {
        stringstream ss;
        ss << hex << i;
        string index = ss.str();
        transform(index.begin(),index.end(),index.begin(), ::toupper);
        cout << "R"<< hex << index << ": "<< registers[i] << endl;
    }
}