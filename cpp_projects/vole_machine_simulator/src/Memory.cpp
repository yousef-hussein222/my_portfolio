#include "Memory.h"

// Constructor
Memory::Memory()
{
    for(int i = 0;i<256;i++)
    {
        memory[i] = "00";
    }
}

// =============================================================

void Memory::setMemory(int address,const string& value)
{
    if(address >= 0 && address < 256)
    {
        memory[address] = value;
    }
}
// =============================================================

string Memory::getMemory(int address)
{
    if(address >= 0 && address < 256)
    {
        return memory[address];
    }
    return "Invalid Address";
}
// =============================================================

void Memory::printMemoryStatus()
{
    int breakLine = 0;
    for (int i = 0 ; i < 256 ; i++)
    {
        stringstream ss;
        ss << hex << i;
        string index = ss.str();
        transform(index.begin(),index.end(),index.begin(), ::toupper);
        cout << "M"<< index << ": " <<  memory[i];
        if (breakLine < 3)
        {
            breakLine++;
            if  (i <= 15)
            {
                cout << "     ||               ";
            }
            else
            {
                cout << "    ||               ";
            }
        }
        else
        {
            cout << endl;
            breakLine = 0;
        }
    }
    cout <<endl;
}
// =============================================================

void Memory::setExpectedOutput(const string &val)
{
    expectedOutput.push_back(val);
}
// =============================================================

void Memory::printExpectedOutput()
{
    cout << endl << "********* Expected Output *********"<<endl;
    cout << "The values in Hexadecimal: ";
    for(auto& it :expectedOutput)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "The values in ASCII: ";
    for(auto& it :expectedOutput)
    {
        char asciiChar = static_cast<char>(stoi(it, nullptr, 16));
        cout << asciiChar << " ";
    }
    cout << endl;
}
// =============================================================

