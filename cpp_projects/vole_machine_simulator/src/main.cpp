#include "VoleMachine.h"

void Menu()
{
    cout << "********** Welcome to Vole Machine Program **********"<<endl;
    cout << "1-Load Instructions From File"<<endl << "2-Display Memory Status"<<endl
    << "3-Display Register Status" <<endl << "4-Exit Program"<<endl;
}

int main ()
{
    VoleMachine Machine;
    bool flag = true;
    while(flag)
    {
        Menu();
        int choice;
        cout << "Enter your choice: "<<endl;
        while( !(cin >> choice) )
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Enter only integers value !"<<endl;
        }
        switch (choice)
        {
            case 1:
                cout << "Do you want to print register and memory contents every time ?"<<endl;
                cout << "1-Print Memory and Register Status *** Do not worry if a lot of outputs appear, this is not infinite loop ***"<<endl;
                cout << "2-Print all results in the end"<<endl;
                while(true)
                {
                    cout << "Enter your choice: "<<endl;
                    while( !(cin >> Machine.state) )
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Enter only integers value !"<<endl;
                    }
                    if(Machine.state != 1 && Machine.state != 2)
                    {
                        cout << "Please Enter a number 1 or 2 !"<<endl;
                        continue;
                    }
                    break;
                }
                Machine.loadProgramFile();
                break;
            case 2:
                Machine.print_memory();
                break;
            case 3:
                Machine.print_register();
                break;
            case 4:
                flag = false;
                break;
            default:
                cout << "Please Enter a number from 1 to 4 !"<<endl;
        }
    }
    return 0 ;
}