#ifndef WORD_X_O_H
#define WORD_X_O_H

#include "BoardGame_Classes.h"
#include <fstream>
#include <utility>
template <typename T>
class Word_Board:public Board<T>{
    char ** board;
public:
    Word_Board ();
    bool update_board (int x , int y , T c);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Word_Player : public Player<T> {
public:
    Word_Player (string name, T symbol);
    void getmove(int& x, int& y) ;
};

template <typename T>
class Word_Random_Player : public RandomPlayer<T>{
public:
    Word_Random_Player (T symbol);
    void getmove(int &x, int &y) ;
};





//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
// Constructor for X_O_Board
template <typename T>
Word_Board<T>::Word_Board() {
    this->rows = this->columns = 3;
    this->board = new char *[3];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char [this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j]=0 ;

        }
    }
    this->n_moves = 0;
}
bool is_in_file(string s) {
    ifstream myfile("dic.txt");
    if (!myfile.is_open()) {
        cout << "Dictionary file not found.\n";
        return false;
    }
    string word;
    while (myfile >> word) {
        if (word == s) return true;
    }
    myfile.close();
    return false;
}


template <typename T>
bool Word_Board<T>::update_board(int x, int y, T c) {
    if (x == -1 && y == -1) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (this->board[x][y] != 0);
        this->n_moves++;

        char randomChar = 'A' + (rand() % 26);
        this->board[x][y] = toupper(randomChar);
        return true;
    }else if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && this->board[x][y]== 0) {
        this->n_moves++;
        char cc;
        cout << "Enter a character: ";
        cin >> cc;

        this->board[x][y] = toupper(cc);
        return true;
    }
    return false;
}


// Display the board and the pieces on it
template <typename T>
void Word_Board<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool Word_Board<T>::is_win() {
    // Check rows and columns
    for (int i = 0; i < this->rows; i++) {
        // Check row
        if (this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0) {//<>
            string row = string(1, this->board[i][0]) + string(1, this->board[i][1]) + string(1, this->board[i][2]);
            if (is_in_file(row)) {
                return true;
            }
            row = string(1, this->board[i][2]) + string(1, this->board[i][1]) + string(1, this->board[i][0]);
            if (is_in_file(row)) {
                return true;
            }
        }
        if (this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0) {//<>
            string col = string(1, this->board[0][i]) + string(1, this->board[1][i]) + string(1, this->board[2][i]);
            if (is_in_file(col)) {
                return true;
            }
            col = string(1, this->board[2][i]) + string(1, this->board[1][i]) + string(1, this->board[0][i]);
            if (is_in_file(col)) {
                return true;
            }
        }
    }
    if (this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0) {//<>
        string diag1 = string(1, this->board[0][0]) + string(1, this->board[1][1]) + string(1, this->board[2][2]);
        if (is_in_file(diag1)) {
            return true;
        }
        diag1 = string(1, this->board[2][2]) + string(1, this->board[1][1]) + string(1, this->board[0][0]);
        if (is_in_file(diag1)) {
            return true;
        }
    }
    if (this->board[0][2] != 0 && this->board[1][1]!= 0 && this->board[2][0] != 0) {//<!>
        string diag2 = string(1, this->board[0][2]) + string(1, this->board[1][1]) + string(1, this->board[2][0]);
        if (is_in_file(diag2)) {
            return true;
        }
        diag2 = string(1, this->board[2][0]) + string(1, this->board[1][1]) + string(1, this->board[0][2]);
        if (is_in_file(diag2)) {
            return true;
        }
    }
    return false;
}
// Return true if 9 moves are done and no winner
template <typename T>
bool Word_Board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}
template <typename T>
bool Word_Board<T>::game_is_over() {
    return is_win() || is_draw();
}

//--------------------------------------

// Constructor for X_O_Player
template <typename T>
Word_Player<T>::Word_Player(string name, T symbol) : Player<T>(name, symbol) {}
template <typename T>
void Word_Player<T>::getmove(int& x, int& y)
{
    string inputX,inputY;
    while (true)
    {
        cout << "* Enter the value of x and y (0 to 2) separate by space *" << endl;
        cin >> inputX >> inputY;

        stringstream ss1(inputX);
        stringstream ss2(inputY);
        if ((ss1 >> x && ss1.eof()) && (ss2 >> y && ss2.eof()) && (x != -1 && y != -1))
        {
            break;
        }
        else
        {
            cout << "* Enter only integers value for both (x,y) ! *" << endl;

        }
    }
}
// Constructor for X_O_Random_Player
template <typename T>
Word_Random_Player<T>::Word_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void Word_Random_Player<T>::getmove(int& x, int& y) {
    x = -1;
    y =-1;
}

#endif