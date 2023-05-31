#include "Snake.h"

Snake::Snake(Input& input) : input(input)
{
}

void Snake::start_snake() //staring position of snake
{
    snakebody.emplace_back(5, 5);
    snakebody.emplace_back(5, 6);

}


vector<pair<int, int>> Snake::get_snakebody() //returns the snake body
{
    return snakebody;
}

void Snake::move_snake() //moves the snake
{
    // Get the current head position
    pair<int, int> head = snakebody.front();
    int x = head.first;
    int y = head.second;

    // Determine the new head position based on the direction
    switch (this->input.get_direction()) {
    case 1:  // Move up
        y--;
        break;
    case 2:  // Move down
        y++;
        break;
    case 3:  // Move left
        x--;
        break;
    case 4:  // Move right
        x++;
        break;
    }

    // Create the new head position
    pair<int, int> new_head = make_pair(x, y);

    // Add the new head position to the front of the snake's body
    snakebody.insert(snakebody.begin(), new_head);

    //setting possitions of the tail in previous iterations of the game
    x2 = x1;
    y2 = y1;
    x1 = snakebody.back().first;
    y1 = snakebody.back().second;


    // Remove the tail of the snake
    snakebody.pop_back();
}

void Snake::grow(int grow_size) //grows the snake
{
    if (grow_size == 1)
    {
        snakebody.emplace_back(x1, y1);
    }
    else if (grow_size == 2)
    {
        snakebody.emplace_back(x1, y1);
        snakebody.emplace_back(x2, y2);
    }
}
