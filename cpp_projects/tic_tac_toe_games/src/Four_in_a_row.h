
#ifndef _FOUR_IN_A_ROW_H
#define _FOUR_IN_A_ROW_H


#include "BoardGame_Classes.h"
template <typename T>
class Four_in_a_row_Board:public Board<T> 
{
public:
    Four_in_a_row_Board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win();
    bool is_draw();
    bool game_is_over();
};
template <typename T>
class Four_in_a_row_Player : public Player<T> 
{
public:
    Four_in_a_row_Player (string name, T symbol);
    void getmove(int& x, int& y);

};

template <typename T>
class Four_in_a_row_Random_Player : public RandomPlayer<T>
{
public:
    Four_in_a_row_Random_Player(T symbol);
    void getmove(int &x, int &y) ;
};




#include<bits/stdc++.h>
template <typename T>
Four_in_a_row_Board<T>::Four_in_a_row_Board()
{
    this->rows = 6;
    this->columns = 7;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) 
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) 
        {
            this->board[i][j] = '.';
        }
    }
    this->n_moves = 0;
}
template <typename T>
bool Four_in_a_row_Board<T>::update_board(int x , int y , T symbol)
{
   if (y < 0 || y >= this->columns || this->board[0][y] != '.') 
    {
        return false;  
    }
    for (int i = this->rows - 1; i >= 0; i--) 
    {
        if (this->board[i][y] == '.') {
            this->board[i][y] = toupper(symbol);
            this->n_moves++;
            return true;
        }
    }
    return false;
}
template <typename T>
void Four_in_a_row_Board<T>::display_board() 
{
    for (int i = 0; i < this->rows; i++) 
    {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++)
        {
            cout << "("  << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------------------------------";
    }
    cout << endl;
}
template <typename T>
bool Four_in_a_row_Board<T>::is_win() 
{
   for(int i = 0 ; i < this->rows; i++)
   {
        for (int j = 0; j < this->columns; j++)
        {
           if(this->board[i][j] != '.')
            {
               if (j <= this->columns - 4 && 
                    this->board[i][j] == this->board[i][j + 1] &&
                    this->board[i][j] == this->board[i][j + 2] && 
                    this->board[i][j] == this->board[i][j + 3]) 
                    {
                        return true;
                    }

                if (i <= this->rows - 4 &&
                    this->board[i][j] == this->board[i + 1][j] &&
                    this->board[i][j] == this->board[i + 2][j] &&
                    this->board[i][j] == this->board[i + 3][j]) 
                    {
                        return true;
                    }
           
                if (i <= this->rows - 4 && j <= this->columns - 4 &&
                    this->board[i][j] == this->board[i + 1][j + 1] &&
                    this->board[i][j] == this->board[i + 2][j + 2] &&
                    this->board[i][j] == this->board[i + 3][j + 3]) 
                    {
                    return true;
                    }

                if (i >= 3 && j <= this->columns - 4 &&
                    this->board[i][j] == this->board[i - 1][j + 1] &&
                    this->board[i][j] == this->board[i - 2][j + 2] &&
                    this->board[i][j] == this->board[i - 3][j + 3]) 
                    {
                    return true;
                    }
            }
        }
    }
    return false;
}
template <typename T>
bool Four_in_a_row_Board<T>::is_draw() 
{
    return ((this->n_moves ==  this->columns * this->rows) && !is_win());
}

template <typename T>
bool Four_in_a_row_Board<T>::game_is_over() 
{
    return is_win() || is_draw();
}
template <typename T>
Four_in_a_row_Player<T>::Four_in_a_row_Player(string name, T symbol): Player<T>(name, symbol) {}
template <typename T>
void Four_in_a_row_Player<T>::getmove(int& x, int& y)
{
    string inputY;
    while (true)
    {
        cout << "Please enter your move Y between (0 to 6) : " << endl;
        cin >> inputY;

        stringstream ss2(inputY);
        if ((ss2 >> y && ss2.eof()) && y != -1)
        {
            break;
        }
        else
        {
            cout << "*** Enter only integer value for y ! ***" << endl;
        }
    }
}
template<class T>
Four_in_a_row_Random_Player<T>::Four_in_a_row_Random_Player(T symbol) :RandomPlayer<T>(symbol)
{
    this->dimension = 7;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void Four_in_a_row_Random_Player<T>::getmove(int& x, int& y) 
{
   
    y = rand() % this->dimension;
    x = -1; 
}

#endif
