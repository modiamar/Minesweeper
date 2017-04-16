#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>

using namespace std;


int bombs, checkx ,checky;
const int sizex = 10, sizey =10;


bool lose;

class Grid 

{
 public:
    bool has_bomb, marked;
    int adjacent_bombs;
    Grid(void) {
        has_bomb = false;
        marked = false;
        adjacent_bombs = 0;

    }
};

void drawBoard(Grid board[sizex][sizey])

{
    cout<< "_";
    for (int i = 0; i < sizex; i++)
    {
        cout << i << "_";
    }
    cout << endl;

    for (int y = 0; y < sizey; y++)
    {
        cout << y;
        for (int x = 0; x < sizex; x++)
        {
           if(board[x][y].has_bomb && board[x][y].marked)

           {
            cout << "!|";
           }
           else if (board[x][y].marked)
           {
            if (board[x][y].marked and board[x][y].adjacent_bombs != 0)
           {
                if (x == 0 and y == 0)
                    {
                        if (board[x][y].adjacent_bombs -5 == 0)
                        {
                            cout << "0|";
                        }
                        else
                        {
                            cout << board[x][y].adjacent_bombs - 4;
                            cout <<  "|";
                        }
                    }
                else if (x == 0 or x == 9 or y == 9 or y == 0)
                {
                    if (board[x][y].adjacent_bombs -1 == 0)
                    {
                        cout << "0|";
                    }
                    else
                    {
                        cout << board[x][y].adjacent_bombs -1;
                        cout <<  "|";
                    }
                }
                else
                {
                    cout << board[x][y].adjacent_bombs;
                    cout <<  "|";
                }
                

           }
           else
           {
            cout << "0|";
           }
            
           }
           else
           {
            cout << "_|";
           }
            
        }
        cout << endl;
    }
}


void checkSurroundingPoints(int checkx, int checky, Grid gameboard[sizex][sizey])
{
    int bombcount = 0;
    if(checkx < 10 and checky < 10)
    {
        if (gameboard[checkx][checky].has_bomb == false and gameboard[checkx][checky].marked == false)
        {
            if (checkx < 10 and checky < 10 and checkx >= 0 and checky >= 0)
            {
                int rMin = max(checkx - 1, 0);
                int cMin = max(checky - 1, 0);
                int rMax = min(checkx + 1, 10 - 1);
                int cMax = min(checky + 1, 10 - 1);
                gameboard[checkx][checky].marked = true;
                if (gameboard[rMax][checky].has_bomb)
                {
                    bombcount++;
                }
                if (gameboard[checkx][cMin].has_bomb)
                {

                    bombcount ++;
                }
                if (gameboard[checkx][cMax].has_bomb)
                {
                    bombcount ++;
                }
                if (gameboard[rMin][checky].has_bomb)
                {
                    bombcount ++;
                }
                if (gameboard[rMin ][cMin].has_bomb)
                {
                    bombcount ++;
                }
                if (gameboard[rMax][cMax].has_bomb)
                {
                    bombcount ++;
                }
                if (gameboard[rMin][cMax].has_bomb)
                {
                    bombcount ++;
                }
                if (gameboard[rMax ][cMin].has_bomb)
                {
                    bombcount ++;
                }

                gameboard[checkx][checky].adjacent_bombs = bombcount;
                if (gameboard[checkx][checky].adjacent_bombs >= 1)
                {
                    bombcount = 0;
                    return;
                }
                else
                {
                    bombcount = 0;
                    checkSurroundingPoints(checkx - 1, checky, gameboard);
                    checkSurroundingPoints(checkx, checky - 1, gameboard);
                    checkSurroundingPoints(checkx + 1, checky, gameboard);
                    checkSurroundingPoints(checkx, checky + 1, gameboard);
                }

            }
            else
                return;
            
        }
        else
            return;
    }
    else
        return;
}

int main()
{
    lose = false;
    bombs = 30;
    checkx = 0;
    checky = 0;
    Grid gameboard[sizex][sizey];
    int n_rows = sizeof(gameboard)/sizeof(gameboard[0]);
    int n_cols = sizeof(gameboard[0])/sizeof(gameboard[0][0]);
    int items = n_cols * n_rows;
    for (int i = 0; i < bombs; i++)
    {
        int xpos = rand() %10;
        int ypos = rand() %10;
        if(gameboard[xpos][ypos].has_bomb == false)
        {
            gameboard[xpos][ypos].has_bomb = true;
        }
        else
        {
            i--;
        }
    }

    while(lose != true)
    {
        cout << "Input an x value to check" << endl;
        cin >> checkx;
        cout << "Input a y value to check" << endl;
        cin >> checky;
        if (gameboard[checkx][checky].marked == false)
        {
            checkSurroundingPoints(checkx,checky, gameboard);
            gameboard[checkx][checky].marked = true;
            
            int countSquares = 0;
            for (int k = 0; k < sizex; k++)
            {
                for (int m = 0; m < sizey; m++)
                {
                    if (gameboard[k][m].marked)
                    {
                        countSquares++;
                    }
                }
            }
            if (gameboard[checkx][checky].has_bomb == true)
            {
                lose = true; 
                cout << "YOU LOSE!!!" << endl;
            }

            else if (items - countSquares <= bombs)
            {
                lose = true;
                cout << "YOU WIN!!!!!" << endl;
            }
            
            else 
            {
                cout << "Shoot again" << endl;
            }

            cout << endl;
            drawBoard(gameboard);
            cout << endl;

        }

    }
}