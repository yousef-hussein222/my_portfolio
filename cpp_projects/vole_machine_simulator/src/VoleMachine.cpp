#include "VoleMachine.h"

string VoleMachine::validExtension()
{
    string fileName,extension;
    while(true)
    {
        cout << "Enter the file name to load instructions: "<<endl;
        cin >> fileName;
        size_t found = fileName.find('.');
        extension = fileName.substr(found + 1);
        if(found != string::npos && extension == "txt")
        {
            return fileName;
        }
        else
        {
            cout << "********** Enter a valid extension Ex: (filename.txt) **********" << endl;
        }
    }
}
// ===========================================================

void VoleMachine::loadProgramFile()
{
    ifstream file;
    while(true)
    {
        file.open(validExtension() );
        bool isEmpty =  file.peek() == ifstream::traits_type::eof();
        if (file.fail() || isEmpty)
        {
            cout << "******* Error:Could not open the file or file name does not exist or file is empty ! *******\n";
            continue;
        }
        break;
    }
    string line;
    int counter = 10;
    string str1 , str2 ;
    while (getline(file, line))
    {
        if(!line.empty())
        {
            string newLine;
            for(char c:line)
            {
                if(!isspace(c))
                {
                    newLine += c;
                }
            }
            transform(newLine.begin(),newLine.end(),newLine.begin(),::toupper);
            if(newLine.length() == 4)
            {
                str1 = newLine.substr(0,2) ;
                memory.setMemory(counter , str1) ;
                counter++ ;
                str2 = newLine.substr(2,2) ;
                memory.setMemory(counter , str2) ;
                counter++ ;
            }
        }
    }
    cout << "Instructions Loaded Successfully"<<endl;
    if(state == 1)
    {
        processor.runNextStep(memory,state);
        cout << "Program Counter: "<<processor.getProgramCounter()<<endl;
        cout <<"======================================="<<endl;
        memory.printExpectedOutput();
        cout <<"======================================="<<endl;
    }
    else if(state == 2)
    {
        processor.runNextStep(memory,state);
        cout <<"======================================="<<endl;

        cout << "********** Memory Content **********"<<endl;
        memory.printMemoryStatus();
        cout <<"======================================="<<endl;

        cout << "********** Register Content **********"<<endl;
        processor.callRegister().printRegisterStatus();
        cout <<"======================================="<<endl;

        memory.printExpectedOutput();
        cout <<"======================================="<<endl;

        cout << "Program Counter: "<<processor.getProgramCounter()<<endl;
        cout <<"======================================="<<endl;
    }
}
// ===========================================================

void VoleMachine::print_memory()
{
    memory.printMemoryStatus();
}
// ===========================================================

void VoleMachine::print_register()
{
    processor.callRegister().printRegisterStatus();
}