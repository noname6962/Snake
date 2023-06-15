#include "game_view.h"



using namespace std;

/// width and height of the game board
const int width = 22;
const int height = 12;

void game_view::drawBoard(vector<pair<int, int>> snake, int fruit_x, int fruit_y, int fruit_type, int points)
{
    system("cls");

    char board[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            board[i][j] = '.';
        }
        for (int j = 0; j < width; j++)
        {
            board[0][j] = '#';
            board[height - 1][j] = '#';
        }
        for (int i = 1; i < height - 1; i++)
        {
            board[i][0] = '#';
            board[i][width - 1] = '#';
        }
    }



    /** Draw the fruit
    *D - Default
    *S - speed fruit
    *B - Big fruit (2x growth)
    */
    if (fruit_type == 1)
    {
        board[fruit_y][fruit_x] = 'D';
    }
    else if (fruit_type == 2)
    {
        board[fruit_y][fruit_x] = 'S';
    }
    else if (fruit_type == 3)
    {
        board[fruit_y][fruit_x] = 'B';
    }


    /**
    * 0 - head of the snake
    * o - body of the snake
    */
    for (int i = 0; i < snake.size(); i++)
    {
        int x = snake[i].first;
        int y = snake[i].second;

        if (i == 0)
        {
            board[y][x] = 'O';
        }
        else
        {
            board[y][x] = 'o';
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << board[i][j];
        }
        if (i == 1)
        {
            cout << " Points: " << points;
        }

        cout << endl;
    }
}
