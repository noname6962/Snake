#include "game_view.h"



using namespace std;

const int width = 22; // Width of the game board
const int height = 12; // Height of the game board

// Draw the game board
void game_view::drawBoard(vector<pair<int, int>> snake, int fruit_x, int fruit_y, int fruit_type, int points)
{
    system("cls"); // Clear the console

    char board[height][width];

    // Fill the board with dots
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            board[i][j] = '.';
        }
        for (int j = 0; j < width; j++)
        {
            board[0][j] = '#'; // Top wall
            board[height - 1][j] = '#'; // Bottom wall
        }
        for (int i = 1; i < height - 1; i++)
        {
            board[i][0] = '#'; // Left wall
            board[i][width - 1] = '#'; // Right wall
        }
    }



    // Draw the fruit
    //N - normal fruit
    //S - speed fruit
    //G - 2x growth fruit
    if (fruit_type == 1)
    {
        board[fruit_y][fruit_x] = 'N';
    }
    else if (fruit_type == 2)
    {
        board[fruit_y][fruit_x] = 'S';
    }
    else if (fruit_type == 3)
    {
        board[fruit_y][fruit_x] = 'G';
    }


    // Draw the snake
    for (int i = 0; i < snake.size(); i++)
    {
        int x = snake[i].first;
        int y = snake[i].second;

        if (i == 0)
        {
            board[y][x] = 'O'; // Head of the snake
        }
        else
        {
            board[y][x] = 'o'; // Body of the snake
        }
    }

    // Print the board
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
