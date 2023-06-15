#include "Snake.h"

Snake::Snake(Input& input) : input(input)
{
}

void Snake::start_snake()
{
    snakebody.emplace_back(5, 5);
    snakebody.emplace_back(5, 6);

}


vector<pair<int, int>> Snake::get_snakebody()
{
    return snakebody;
}

void Snake::move_snake()
{
    
    pair<int, int> head = snakebody.front();
    int x = head.first;
    int y = head.second;

    
    switch (this->input.get_direction()) {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    }


    pair<int, int> new_head = make_pair(x, y);

    snakebody.insert(snakebody.begin(), new_head);

    x2 = x1;
    y2 = y1;
    x1 = snakebody.back().first;
    y1 = snakebody.back().second;

    snakebody.pop_back();
}

void Snake::grow(int grow_size)
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
