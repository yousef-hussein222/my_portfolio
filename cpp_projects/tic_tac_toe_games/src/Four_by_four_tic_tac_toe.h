#ifndef _FOUR_BY_FOUR_TIC_TAC_TOE_H
#define _FOUR_BY_FOUR_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <utility>
#include <unordered_map>
using namespace std;

template <typename T>
class Four_by_four_tic_tac_toe : public Board<T>
{
public:
    Four_by_four_tic_tac_toe();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

template <typename T>
class Four_by_four_tic_tac_toe_Player : public Player<T>
{
public:
    Four_by_four_tic_tac_toe_Player(string name, T symbol);
    void getmove(int &x, int &y);
};

template <typename T>
class Four_by_four_tic_tac_toe_RandomPlayer : public RandomPlayer<T>
{
public:
    Four_by_four_tic_tac_toe_RandomPlayer(T symbol);
    void getmove(int &x, int &y);
};

#include <bits/stdc++.h>
template <class T>
Four_by_four_tic_tac_toe<T>::Four_by_four_tic_tac_toe()
{
    this->rows = 4;
    this->columns = 4;
    this->board = new char *[this->rows];
    for (int i = 0; i < this->rows; i++)
    {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++)
        {
            this->board[i][j] = '.';
        }
    }
    this->n_moves = 0;
    this->board[0][1] = 'X';
    this->board[0][3] = 'X';
    this->board[3][0] = 'X';
    this->board[3][2] = 'X';
    this->board[0][0] = 'O';
    this->board[0][2] = 'O';
    this->board[3][1] = 'O';
    this->board[3][3] = 'O';
}

template <typename T>
bool Four_by_four_tic_tac_toe<T>::update_board(int x, int y, T symbol)
{
    if(x == -1 && y == -1)
    {
        while(true)
        {
            x = rand() % 4;
            y = rand() % 4;
            if (this->board[x][y] != '.')
            {
                continue;
            }
            else
            {
                int old_x, old_y;
                old_x = rand() % 4;
                old_y = rand() % 4;
                if (old_x < 0 || old_x >= this->rows || old_y < 0 || old_y >= this->columns || this->board[old_x][old_y] != symbol) 
                {
                    continue;
                }

                if (this->board[old_x][old_y] != symbol ||
                    abs(old_x - x) + abs(old_y - y) != 1)
                {
                    continue;
                }

                this->board[old_x][old_y] = '.';
                this->board[x][y] = symbol;

                this->n_moves++;
                return true;
            }
        }
    }
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != '.')
    {
        return false;
    }

    int old_x, old_y;
    string inputX,inputY;
    while (true)
    {
        cout << "Enter the current position of the piece to move (row and column): ";
        cin >> inputX >> inputY;


        stringstream ss1(inputX);
        stringstream ss2(inputY);
        if ((ss1 >> old_x && ss1.eof()) && (ss2 >> old_y && ss2.eof()) )
        {
            break;
        }
        else
        {
            return false;
        }
    }
    if (old_x < 0 || old_x >= this->rows || old_y < 0 || old_y >= this->columns || this->board[old_x][old_y] != symbol) 
    {
        return false;
    }

    if (this->board[old_x][old_y] != symbol ||
        abs(old_x - x) + abs(old_y - y) != 1)
    {
        return false;
    }

    this->board[old_x][old_y] = '.';
    this->board[x][y] = symbol;

    this->n_moves++;
    return true;
}

template <typename T>
void Four_by_four_tic_tac_toe<T>::display_board()
{
    for (int i = 0; i < this->rows; i++) 
    {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) 
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------------------";
    }
    cout << endl;
}
template <typename T>
bool Four_by_four_tic_tac_toe<T>::is_win()
{
    for (int i = 0; i < this->rows; i++) 
    {
        for (int j = 0; j < this->columns; j++) 
        {
            if (j <= this->columns - 3 && this->board[i][j] != '.' &&
                this->board[i][j] == this->board[i][j + 1] &&
                this->board[i][j] == this->board[i][j + 2]) 
            {
                return true;
            }

            if (i <= this->rows - 3 && this->board[i][j] != '.' &&
                this->board[i][j] == this->board[i + 1][j] &&
                this->board[i][j] == this->board[i + 2][j]) 
            {
                return true;
            }

            if (i <= this->rows - 3 && j <= this->columns - 3 && this->board[i][j] != '.' &&
                this->board[i][j] == this->board[i + 1][j + 1] &&
                this->board[i][j] == this->board[i + 2][j + 2]) 
            {
                return true;
            }

            if (i >= 2 && j <= this->columns - 3 && this->board[i][j] != '.' &&
                this->board[i][j] == this->board[i - 1][j + 1] &&
                this->board[i][j] == this->board[i - 2][j + 2]) 
            {
                return true;
            }
        }
    }

    return false;
}



template <typename T>
bool Four_by_four_tic_tac_toe<T>::is_draw()
{
    return (this->n_moves == this->columns * this->rows * 10000) && !is_win();
}

template <typename T>
bool Four_by_four_tic_tac_toe<T>::game_is_over()
{
    return is_win() || is_draw();
}

template <typename T>
Four_by_four_tic_tac_toe_Player<T>::Four_by_four_tic_tac_toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Four_by_four_tic_tac_toe_Player<T>::getmove(int &x, int &y)
{
    string inputX,inputY;
    while (true)
    {
        cout << "Enter the new position (row and column) (0 to 3) separated by spaces: " << endl;
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

template <class T>
Four_by_four_tic_tac_toe_RandomPlayer<T>::Four_by_four_tic_tac_toe_RandomPlayer(T symbol) : RandomPlayer<T>(symbol)
{
    this->dimension = 4;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Four_by_four_tic_tac_toe_RandomPlayer<T>::getmove(int &x, int &y)
{
    x = -1;
    y = -1;
}

#endif