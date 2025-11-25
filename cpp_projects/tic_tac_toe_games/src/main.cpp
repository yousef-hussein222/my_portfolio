#include <iostream>
#include "BoardGame_Classes.h"
#include "X_O_5x5.h"
#include "Misere_X_O.h"
#include "X_O_9x9.h"
#include "Four_in_a_row.h"
#include "Numerical_tic_tac_toe.h"
#include "Four_by_four_tic_tac_toe.h"
#include "TIC_TAC.h"
#include "word_X_O.h"

using namespace std;

int validChoice()
{
    int choice;
    string input;
    cout << "Enter your choice: " << endl;
    while (true)
    {
        cin >> input;
        stringstream ss(input);
        if (ss >> choice && ss.eof())
        {
            break;
        }
        else
        {
            cout << "Enter only integers value!" << endl;
        }
    }
    return choice;
}

void FourInRow()
{
    Player<char>* players[2];
    auto * B = new Four_in_a_row_Board<char>();
    string playerXName, player2Name;

    // Set up player 1
    cout << "Enter Player 1 name: " << endl;
    cin >> playerXName;
    while(true)
    {
        cout << "Choose Player 1 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";
        switch(validChoice())
        {
            case 1:
                players[0] = new Four_in_a_row_Player<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Four_in_a_row_Random_Player<char>('X');
                break;
            default:
                cout << "** Invalid choice Player 1 choose 1 or 2. **\n";
                continue;
        }
        break;
    }

    // Set up player 2
    cout << "Enter Player 2 name: " << endl;
    cin >> player2Name;
    while(true)
    {
        cout << "Choose Player 2 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice())
        {
            case 1:
                players[1] = new Four_in_a_row_Player<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new Four_in_a_row_Random_Player<char>('O');
                break;
            default:
                cout << "** Invalid choice Player 2 choose 1 or 2. **\n";
                continue;
        }
        break;
    }

    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void NumericalTicTacToe()
{
    Player<char>* players[2];
    auto* B = new Numerical_tic_tac_toe<char>();
    string playerXName, player2Name;

    // Set up player 1
    cout << "Enter Player 1 name: "<< endl;
    cin >> playerXName;
    while(true)
    {
        cout << "Choose Player 1 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice()) {
            case 1:
                players[0] = new Numerical_tic_tac_toe_Player<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Numerical_tic_tac_toe_Random_Player<char>('X');
                break;
            default:
                cout << "** Invalid choice Player 1 choose 1 or 2. **\n";
                continue;
        }
        break;
    }


    // Set up player 2
    cout << "Enter Player 2 name: "<<endl;
    cin >> player2Name;
    while(true)
    {
        cout << "Choose Player 2 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice()) {
            case 1:
                players[1] = new Numerical_tic_tac_toe_Player<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new Numerical_tic_tac_toe_Random_Player<char>('O');
                break;
            default:
                cout << "** Invalid choice Player 2 choose 1 or 2. **\n";
                continue;
        }
        break;
    }


    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void fourByFourTicTacToe()
{
    Player<char> *players[2];
    auto *B = new Four_by_four_tic_tac_toe<char>();
    string playerXName, player2Name;

    // Set up player 1
    cout << "Enter Player 1 name: " << endl;
    cin >> playerXName;
    while (true) {
        cout << "Choose Player 1 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch (validChoice()) {
            case 1:
                players[0] = new Four_by_four_tic_tac_toe_Player<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Four_by_four_tic_tac_toe_RandomPlayer<char>('X');
                break;
            default:
                cout << "** Invalid choice Player 1 choose 1 or 2. **\n";
                continue;
        }
        break;
    }


    // Set up player 2
    cout << "Enter Player 2 name: "<<endl;
    cin >> player2Name;
    while (true)
    {
        cout << "Choose Player 2 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice()) {
            case 1:
                players[1] = new Four_by_four_tic_tac_toe_Player<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new Four_by_four_tic_tac_toe_RandomPlayer<char>('O');
                break;
            default:
                cout << "** Invalid choice Player 2 choose 1 or 2. **\n";
                continue;
        }
        break;
    }


    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void Pyramic_Tic_Tac_Toe()
{
    Player<char>* players[2];
    auto * B = new Pyramic_Tic_Tac_Toe_Board<char>();
    string playerXName, player2Name;

// Set up player 1
    cout << "Enter Player 1 name: "<<endl;
    cin >> playerXName;

    while (true)
    {
        cout << "Choose Player 1 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";
        switch(validChoice()) {
            case 1:
                players[0] = new Pyramic_Tic_Tac_Toe_Player<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Pyramic_Tic_Tac_Toe_Random_Player<char>('X');
                break;
            default:
                cout << "** Invalid choice Player 1 choose 1 or 2. **\n";
                continue;
        }
        break;
    }

// Set up player 2
    cout << "Enter Player 2 name: "<<endl;
    cin >> player2Name;
    while (true)
    {
        cout << "Choose Player 2 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";
        switch(validChoice()) {
            case 1:
                players[1] = new Pyramic_Tic_Tac_Toe_Player<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new Pyramic_Tic_Tac_Toe_Random_Player<char>('O');
                break;
            default:
                cout << "** Invalid choice Player 2 choose 1 or 2. **\n";
                continue;
        }
        break;
    }

// Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();
// Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void word_X_O()
{
    Player<char>* players[2];
    auto* B = new Word_Board<char>();
    string playerXName, player2Name;

    // Set up player 1
    cout << "Enter Player 1 name: "<<endl;
    cin >> playerXName;
    while(true)
    {
        cout << "Choose Player 1 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";
        switch(validChoice()) {
            case 1:
                players[0] = new Word_Player<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Word_Random_Player<char>('X');
                break;
            default:
                cout << "** Invalid choice for Player 1 choose 1 or 2.**\n";
                continue;
        }
        break;
    }


// Set up player 2
    cout << "Enter Player 2 name: "<<endl;
    cin >> player2Name;
    while(true)
    {
        cout << "Choose Player 2 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice()) {
            case 1:
                players[1] = new Word_Player<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new Word_Random_Player<char>('O');
                break;
            default:
                cout << "** Invalid choice for Player 2 choose 1 or 2.**\n";
                continue;
        }
        break;
    }

// Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

// Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void X_O_9x9()
{
    Player<char>* players[2];
    auto* B = new X_O_9x9_Board<char>();
    string playerXName, player2Name;

    // Set up player 1
    cout << "Enter Player 1 name: "<<endl;
    cin >> playerXName;
    while(true)
    {
        cout << "Choose Player 1 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice()) {
            case 1:
                players[0] = new Player_9x9_X_O<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new Random_Player_9x9_X_O<char>('X');
                break;
            default:
                cout << "** Invalid choice for Player 1 choose 1 or 2.**\n";
                continue;
        }
        break;
    }


    // Set up player 2
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    while(true)
    {
        cout << "Choose Player 2 type:\n";
        cout << "1.Human\n";
        cout << "2.Random Computer\n";

        switch(validChoice()) {
            case 1:
                players[1] = new Player_9x9_X_O<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new Random_Player_9x9_X_O<char>('O');
                break;
            default:
                cout << "** Invalid choice for Player 2 choose 1 or 2.**\n";
                continue;
        }
        break;
    }


    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void X_O_5x5()
{
    Player<char>* players[2];
    auto* B = new Board_5x5_X_O<char>();
    string playerXName, player2Name;


    // Set up player 1
    cout << "Enter Player 1 name: "<<endl;
    cin >> playerXName;
    while(true)
    {
        cout << "Choose Player 1 type: "<<endl;
        cout << "1.Human"<<endl;
        cout << "2.Random Computer"<<endl;

        switch(validChoice()) {
            case 1:
                players[0] = new Player_5x5_X_O<char>(playerXName, 'X');
                break;
            case 2:
                players[0] = new RandomPlayer_5x5_X_O<char>('X');
                break;
            default:
                cout << "** Invalid choice for Player 1 choose 1 or 2.**"<<endl;
                continue;
        }
        break;
    }


    // Set up player 2
    cout << "Enter Player 2 name: "<<endl;
    cin >> player2Name;
    while(true)
    {
        cout << "Choose Player 2 type: "<<endl;
        cout << "1.Human"<<endl;
        cout << "2.Random Computer"<<endl;

        switch(validChoice()) {
            case 1:
                players[1] = new Player_5x5_X_O<char>(player2Name, 'O');
                break;
            case 2:
                players[1] = new RandomPlayer_5x5_X_O<char>('O');
                break;
            default:
                cout << "** Invalid choice for Player 2 choose 1 or 2.**"<<endl;
                continue;
        }
        break;
    }


    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void misere_X_O()
{
    Player<char>* players[2];
    auto *B = new Misere_board_X_O<char>();

    string playerXName, player2Name;

    cout << "Enter Player 1 name: "<<endl;
    cin >> playerXName;
    while(true)
    {
        cout << "Choose Player 1 type: "<<endl;
        cout << "1.Human"<<endl;
        cout << "2.Random Computer"<<endl;

        switch(validChoice()) {
            case 1:
                players[0] = new Misere_Player_X_O<char>(playerXName, 'X');
                players[0]->setBoard(B);
                break;
            case 2:
                players[0] = new Misere_randomPlayer_X_O<char>('X');
                players[0]->setBoard(B);
                break;
            default:
                cout << "** Invalid choice for Player 1 choose 1 or 2.**"<<endl;
                continue;
        }
        break;
    }


    // Set up player 2
    cout << "Enter Player 2 name: "<<endl;
    cin >> player2Name;
    while(true)
    {
        cout << "Choose Player 2 type: "<<endl;
        cout << "1.Human"<<endl;
        cout << "2.Random Computer"<<endl;

        switch(validChoice()) {
            case 1:
                players[1] = new Misere_Player_X_O<char>(player2Name, 'O');
                players[1]->setBoard(B);
                break;
            case 2:
                players[1] = new Misere_randomPlayer_X_O<char>('O');
                players[1]->setBoard(B);
                break;
            default:
                cout << "** Invalid choice for Player 2 choose 1 or 2.**"<<endl;
                continue;
        }
        break;
    }


    // Create the game manager and run the game
    GameManager<char> x_o_game(B, players);
    x_o_game.run();

    // Clean up
    delete B;
    for (auto & player : players) {
        delete player;
    }
}

void mainMenu()
{
    cout << "*** Welcome To Our X-O Program ***" << endl;
    cout << "1-Start Program"<<endl<< "2-Exit Program"<<endl;
}
void gamesMenu()
{
    cout << "*** Choose Game To Play ***"<< endl << "1-Pyramic Tic-Tac-Toe"<<endl << "2-Four-in-a-row Tic-Tac-Toe"<<endl
    <<"3-5x5 Tic-Tac-Toe"<<endl << "4-Word Tic-Tac-Toe"<<endl << "5-Numerical Tic-Tac-Toe"<<endl<<"6-Misere Tic Tac Toe"<<
    endl<<"7-4x4 Tic-Tac-Toe"<<endl<<"8-Ultimate Tic-Tac-Toe"<<endl<<"9-Return to Main Menu"<<endl;
}

void implementOfMain()
{
    bool flag = true,flag2= true;
    while(flag)
    {
        mainMenu();
        switch (validChoice())
        {
            case 1:
                while(flag2)
                {
                    gamesMenu();
                    switch (validChoice())
                    {
                        case 1:
                            Pyramic_Tic_Tac_Toe();
                            break;
                        case 2:
                            FourInRow();
                            break;
                        case 3:
                            X_O_5x5();
                            break;
                        case 4:
                            word_X_O();
                            break;
                        case 5:
                            NumericalTicTacToe();
                            break;
                        case 6:
                            misere_X_O();
                            break;
                        case 7:
                            fourByFourTicTacToe();
                            break;
                        case 8:
                            X_O_9x9();
                            break;
                        case 9:
                            flag2 = false;
                            break;
                        default:
                            cout << "*** Enter a number from 1 to 9 ***"<<endl;
                    }
                }
                flag2 = true;
                break;
            case 2:
                flag = false;
                break;
            default:
                cout << "*** Enter a number 1 or 2 ***"<<endl;
        }
    }
}

int main()
{
    implementOfMain();
    return 0;
}
