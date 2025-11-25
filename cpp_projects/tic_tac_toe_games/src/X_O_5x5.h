#ifndef ASSIGNMENT_2_TASK_2_X_O_5X5_H
#define ASSIGNMENT_2_TASK_2_X_O_5X5_H

#include "BoardGame_Classes.h"
#include<iomanip>
#include<cctype>
#include<map>
#include<limits>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

// --------------------------------- Implementation Of Board_5x5_X_O
template<typename T>
class Board_5x5_X_O : public Board<T>
{
public:
    Board_5x5_X_O(); // Empty Constructor
    bool update_board(int x,int y,T symbol) override;
    void display_board() override;
    bool is_win() override;
    bool is_draw() override;
    bool game_is_over() override;
};

template<typename T>
Board_5x5_X_O<T>::Board_5x5_X_O()
{
    this->rows = 5;
    this->columns = 5;
    this->n_moves = 0;
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
//============================================================

template<typename T>
bool Board_5x5_X_O<T>::update_board(int x, int y, T symbol)
{
    if(x == -1 && y == -1)
    {
        this->n_moves++;
        return true;
    }
    if(x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0)
    {
        if(this->n_moves < 24)
        {
            this->board[x][y] = toupper(symbol);
            this->n_moves++;
            return true;
        }
        else
        {
            this->board[x][y] = toupper(0);
            this->n_moves++;
            return true;
        }

    }
    return false;
}
//============================================================

template<typename T>
void Board_5x5_X_O<T>::display_board()
{
    for(int i = 0;i<this->rows;i++)
    {
        cout<<"|";
        for(int j = 0;j<this->columns;j++)
        {
            cout << setw(3)<< "(" << i << ","<<j << ")" << setw(2)<< this->board[i][j]<< " |";
        }
        cout << endl << "--------------------------------------------------------"<<endl;
    }
    cout << endl;
}
//============================================================

template<typename T>
bool Board_5x5_X_O<T>::is_win()
{
    map<char,int>mp;

    if(this->n_moves >= 24)
    {
        for(int j = 0;j<this->columns;j++)
        {
            for(int i = 0;i<this->rows;i++)
            {
                if(j == 0 || j == 1)
                {
                    if( i < 3 )
                    {
                        if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2])
                        {
                            mp[this->board[i][j]]++;
                        }
                        if(this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2])
                        {
                            mp[this->board[i][j]]++;
                        }
                        if(this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j])
                        {
                            mp[this->board[i][j]]++;
                        }
                    }
                    else
                    {
                        if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2])
                        {
                            mp[this->board[i][j]]++;
                        }
                    }
                }
                else if(j == 2)
                {
                    if( i < 3 )
                    {
                        if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2])
                        {
                            mp[this->board[i][j]]++;
                        }
                        if(this->board[i][j] == this->board[i+1][j+1] && this->board[i+1][j+1] == this->board[i+2][j+2])
                        {
                            mp[this->board[i][j]]++;
                        }
                        if(this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j])
                        {
                            mp[this->board[i][j]]++;
                        }
                        if(this->board[i][j] == this->board[i+1][j-1] && this->board[i+1][j-1] == this->board[i+2][j-2])
                        {
                            mp[this->board[i][j]]++;
                        }
                    }
                    else
                    {
                        if(this->board[i][j] == this->board[i][j+1] && this->board[i][j+1] == this->board[i][j+2])
                        {
                            mp[this->board[i][j]]++;
                        }
                    }
                }
                else if(j == 3 || j == 4)
                {
                    if(i < 3 )
                    {
                        if(this->board[i][j] == this->board[i+1][j-1] && this->board[i+1][j-1] == this->board[i+2][j-2])
                        {
                            mp[this->board[i][j]]++;
                        }
                        if(this->board[i][j] == this->board[i+1][j] && this->board[i+1][j] == this->board[i+2][j])
                        {
                            mp[this->board[i][j]]++;
                        }
                    }
                }

            }
        }
    }

    // ===================================================
    if(this->n_moves == 24 && mp['O']  > mp['X'])
    {
        return true;
    }
    else if(this->n_moves == 25 && mp['X']  > mp['O'])
    {
        return true;
    }
    else
    {
        return false;
    }

}
//============================================================

template<typename T>
bool Board_5x5_X_O<T>::is_draw()
{
    return (this->n_moves == 25 && !is_win());
}
//============================================================

template<typename T>
bool Board_5x5_X_O<T>::game_is_over()
{
    return is_draw() || is_win();
}
//============================================================

// --------------------------------- Implementation Of Player_5x5_X_O

template<typename T>
class Player_5x5_X_O : public Player<T>
{
public:
    static vector< pair<int,int> >vec;
    static int count ;
    Player_5x5_X_O(string n,T symbol);
    void getmove(int& x , int& y) override;
};

template<typename T>
int Player_5x5_X_O<T>::count = 0;

template<typename T>
vector< pair<int,int> > Player_5x5_X_O<T>::vec = {{-2,-2}};

template<typename T>
Player_5x5_X_O<T>::Player_5x5_X_O(string n, T symbol) : Player<T>(n,symbol) {}
//============================================================

template<typename T>
void Player_5x5_X_O<T>::getmove(int &x, int &y)
{
    if(Player_5x5_X_O<T>::count < 24)
    {
        string inputX,inputY;
        while (true)
        {
            cout << "Enter the value of x and y (0 to 4) separate by space: " << endl;
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

        pair<int,int> p = {x,y};
        auto it = find( Player_5x5_X_O::vec.begin(),Player_5x5_X_O::vec.end(),p);
        if(it == Player_5x5_X_O::vec.end() && (x < 5 && x >= 0) && (y < 5 && y >= 0) )
        {
            Player_5x5_X_O::count++;
            Player_5x5_X_O::vec.emplace_back(x,y);
        }
    }
    else
    {
        x = y = -1;
    }
}
//============================================================

// --------------------------------- Implementation Of RandomPlayer_5x5_X_O

template<typename T>
class RandomPlayer_5x5_X_O : public RandomPlayer<T>
{
public:
    RandomPlayer_5x5_X_O(T symbol);
    void getmove(int& x,int& y) override;
};

template<typename T>
RandomPlayer_5x5_X_O<T>::RandomPlayer_5x5_X_O(T symbol ):RandomPlayer<T>(symbol)
{
    srand(static_cast<unsigned int >( time(nullptr) ) );
    this->name = "Random Computer Player";
    this->dimension = 5;
}
//============================================================

template<typename T >
void RandomPlayer_5x5_X_O<T>::getmove(int &x, int &y)
{
    if(Player_5x5_X_O<T>::count < 24)
    {
        x = rand() % this->dimension;
        y = rand() % this->dimension;
        pair<int,int> p = {x,y};
        auto it = find( Player_5x5_X_O<T>::vec.begin(),Player_5x5_X_O<T>::vec.end(),p);
        if(it == Player_5x5_X_O<T>::vec.end())
        {
            Player_5x5_X_O<T>::count++;
            Player_5x5_X_O<T>::vec.emplace_back(x,y);
        }
    }
    else
    {
        x = y = -1;
    }
}

#endif
