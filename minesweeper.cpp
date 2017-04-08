#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


int bombs, checkx ,checky;
const int sizex = 10, sizey =10;

bool lose;

class Grid 

{
 public:
    bool has_bomb, marked;
    Grid(void) {
        has_bomb = false;
        marked = false;
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
            cout << "*|";
           }
           else
           {
            cout << "_|";
           }
            
        }
        cout << endl;
    }
}

int main()
{
    lose = false;
    bombs = 15;
    checkx = 0;
    checky = 0;
    Grid gameboard[sizex][sizey];
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
            gameboard[checkx][checky].marked = true;
            if (gameboard[checkx][checky].has_bomb == true)
            {
                lose = true; 
                cout << "YOU LOSE!!!" << endl;
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