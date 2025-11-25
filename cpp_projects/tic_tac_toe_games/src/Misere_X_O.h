#ifndef ASSIGNMENT_2_TASK_2_MISERE_X_O_H
#define ASSIGNMENT_2_TASK_2_MISERE_X_O_H

#include "BoardGame_Classes.h"
#include<iomanip>
#include <cctype>
#include<cstdlib>
#include<ctime>


// --------------------------------- Implementation Of Misere_board_X_O
template<typename T>
class Misere_board_X_O : public Board<T>
{
private:
    bool flag_X;
    bool flag_O;
public:
    Misere_board_X_O();
    bool update_board(int x,int y,T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

template<typename T>
Misere_board_X_O<T>::Misere_board_X_O()
{
    flag_X = false;
    flag_O = false;
    this->rows = 3;
    this->columns = 3;
    this->board = new char*[this->rows];
    for(int i = 0;i<this->rows;i++)
    {
        this->board[i] = new char[this->columns];
        for(int j = 0;j<this->columns;j++)
        {
            this->board[i][j] = 0;
        }
    }
}
//========================================================

template<typename T>
bool Misere_board_X_O<T>::update_board(int x , int y, T symbol)
{
    if( x == -1 && y == -1)
    {
        return true;
    }
    else if(x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0)
    {
        if(!flag_X)
        {
            this->board[x][y] = toupper(symbol);
            this->n_moves++;
            return true;
        }
        else
        {
            return true;
        }
    }
    return false;
}
//========================================================

template<typename T>
void Misere_board_X_O<T>::display_board()
{
    for(int i = 0;i<this->rows;i++)
    {
        cout<<"|";
        for(int j = 0;j<this->columns;j++)
        {
            cout << setw(3)<< "(" << i << ","<<j << ")" << setw(2)<< this->board[i][j]<< " |";
        }
        cout << endl << "----------------------------------"<<endl;
    }
    cout << endl;
}
//========================================================

template<typename T>
bool Misere_board_X_O<T>::is_win()
{
    if(flag_X)
    {
        return true;
    }
    if(flag_O)
    {
        return true;
    }
    for(int i = 0;i<this->rows;i++)
    {
        if(this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0)
        {
            if(this->board[i][0] == 'O')
            {
                flag_O = true;
            }
            else
            {
                flag_X =  true;
            }

        }
        if(this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)
        {
            if(this->board[0][i] == 'O')
            {
                flag_O = true;
            }
            else
            {
                flag_X =  true;
            }
        }
    }
    if(this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0)
    {
        if(this->board[0][0] == 'O')
        {
            flag_O = true;
        }
        else
        {
            flag_X =  true;
        }
    }
    if(this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[0][2] != 0)
    {
        if(this->board[0][2] == 'O')
        {
            flag_O = true;
        }
        else
        {
            flag_X =  true;
        }
    }
    return false;
}


//========================================================

template<typename T>
bool Misere_board_X_O<T>::is_draw()
{
    return (this->n_moves == 9 && !is_win());
}
//========================================================

template<typename T>
bool Misere_board_X_O<T>::game_is_over()
{
    bool f =   ( is_win() && !flag_O ) || is_draw();
    return f;
}

// --------------------------------- Implementation Of Misere_Player_X_O

template<typename T>
class Misere_Player_X_O : public Player<T>
{
public:
    Misere_Player_X_O(string n, T symbol);
    void getmove(int& x, int& y) override;
};

template<typename T>
Misere_Player_X_O<T>::Misere_Player_X_O(string n, T symbol) : Player<T>(n,symbol) {}
//========================================================

template<typename T>
void Misere_Player_X_O<T>::getmove(int &x, int &y)
{
    if(!this->boardPtr->is_win())
    {
        string inputX,inputY;
        while (true)
        {
            cout << "Enter the value of x and y (0 to 2) separate by space: " << endl;
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
    else
    {
        x = y = -1;
    }
}
//========================================================

// --------------------------------- Implementation Of Misere_randomPlayer_X_O

template<typename T>
class Misere_randomPlayer_X_O : public RandomPlayer<T>
{
public:
    Misere_randomPlayer_X_O(T symbol);
    void getmove(int& x, int& y) override;
};

template<typename T>
Misere_randomPlayer_X_O<T>::Misere_randomPlayer_X_O(T symbol) : RandomPlayer<T>(symbol)
{
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast< unsigned int > (time(nullptr)));
}
//========================================================

template<typename T>
void Misere_randomPlayer_X_O<T>::getmove(int& x, int& y)
{
    if(!this->boardPtr->is_win())
    {
        x = rand() % this->dimension;
        y = rand() % this->dimension;
    }
    else
    {
        x = y = -1;
    }
//    x = rand() % this->dimension;
//    y = rand() % this->dimension;
}

#endif
