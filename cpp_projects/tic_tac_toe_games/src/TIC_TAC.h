#ifndef _TIC_TAC_H
#define _TIC_TAC_H

#include "BoardGame_Classes.h"

template <typename T>
class Pyramic_Tic_Tac_Toe_Board:public Board<T> {
public:
    Pyramic_Tic_Tac_Toe_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class Pyramic_Tic_Tac_Toe_Player : public Player<T> {
public:
    Pyramic_Tic_Tac_Toe_Player (string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class Pyramic_Tic_Tac_Toe_Random_Player : public RandomPlayer<T>{
public:
    Pyramic_Tic_Tac_Toe_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Constructor for X_O_Board
template <typename T>
Pyramic_Tic_Tac_Toe_Board<T>::Pyramic_Tic_Tac_Toe_Board() {
        this->rows = 3;
        this->board = new char*[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new char[2 * i + 1];
            for (int j = 0; j < 2 * i + 1; j++) {
                this->board[i][j] = 0;
            }
        }
        this->n_moves = 0;
    }
template <typename T>
bool Pyramic_Tic_Tac_Toe_Board<T>::update_board(int x, int y, T mark) {
    int columns_in_row = 2 * x + 1;
    if (!(x < 0 || x >= this->rows || y < 0 || y >= columns_in_row) && (this->board[x][y] ==0 || mark == 0)) {
        if (mark == 0) {
            this->n_moves--;
            this->board[x][y] = 0;
        } else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
        return true;
    }
    return false;
}
template <typename T>
void Pyramic_Tic_Tac_Toe_Board<T>::display_board() {
    for (int i = 0; i < 3; i++) {
            cout <<"\n";
        if(i==0)cout <<"                  ";
        if(i==1)cout <<"         ";
        for (int j = 0; j < 2 * i + 1; j++) {

            cout<<"|("<< i << "," << j<<")";
          cout <<this->board[i][j] << " |";
        }
        cout <<endl;
    }
    cout <<"===================================="<<endl;
}

// Returns true if there is any winner
template <typename T>
bool Pyramic_Tic_Tac_Toe_Board<T>::is_win() {
    // Check all case that make any one will win
    if ((this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) ||//<>
        (this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != 0) ||//<>
        (this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != 0) ||//<>
        (this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != 0) ||//<>
        (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 0) ||//<>
        (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][3] != 0) ||//<>
        (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0) )//<>
    {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool Pyramic_Tic_Tac_Toe_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Pyramic_Tic_Tac_Toe_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
Pyramic_Tic_Tac_Toe_Player<T>::Pyramic_Tic_Tac_Toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Pyramic_Tic_Tac_Toe_Player<T>::getmove(int& x, int& y) {

    string inputX,inputY;
    while (true)
    {
        cout << "Please enter your move x and y (0 to 2) for the first number-X-and(0 to 4) for the second number-y-separated by spaces: "<<endl;
        cin >> inputX >> inputY;

        stringstream ss1(inputX);
        stringstream ss2(inputY);
        if ((ss1 >> x && ss1.eof()) && (ss2 >> y && ss2.eof()) && (x != -1 && y != -1))
        {
            break;
        }
        else
        {
            cout << "*** Enter only integers value for both (x,y) ! ***" << endl;
        }
    }
}
/// Constructor for X_O_Random_Player
template <typename T>
Pyramic_Tic_Tac_Toe_Random_Player<T>::Pyramic_Tic_Tac_Toe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = " Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
}

template <typename T>
void Pyramic_Tic_Tac_Toe_Random_Player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  // Random number between 0 and 2
    y = rand() % 5;
}
#endif

