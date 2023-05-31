#include "Collisions.h"

int Collisions::check_snake_collision(vector<pair<int, int>> snake) //checks snake collision with itself and the walls
{
	int head_x = snake[0].first;
	int head_y = snake[0].second;

	if (head_x == 0 or head_x == 21 or head_y == 0 or head_y == 11) //checks collision with the wall
	{
		return 0;
	}
	else
	{
		for (int i = 1; i < snake.size(); i++) //checks collision with itself
		{
			if (head_x == snake[i].first and head_y == snake[i].second)
			{
				return 0;
			}
		}
	}
	return 1;
}

int Collisions::check_fruit_collision(vector<pair<int, int>> snake, int fruit_x, int fruit_y) //checks collision with the fruit
{
	int head_x = snake[0].first;
	int head_y = snake[0].second;

	if (head_x == fruit_x and head_y == fruit_y)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

