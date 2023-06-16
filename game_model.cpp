#include "Game_model.h"

Game_model::Game_model(Snake& snake, Collisions& collisions, Input& input) : snake(snake), input(input), collisions(collisions) {
}

void Game_model::start_values()
{
	this->points = 1;
	this->snake.start_snake();
	this->input.set_start_direction();
	fruit_object = new Default_fruit();
	check = 1;
	fruit_type = 1;
	game_speed = 200;
	fruit_object->spawn_fruit();
}



void Game_model::fruit_operation(vector<pair<int, int>> snake) 
{
	this->snake.grow(fruit_object->get_grow_size());
	if (fruit_object->get_grow_size() == 2)
	{
		this->points++;
		this->points++;
	}
	else
	{
		this->points++;
	}
	game_speed = fruit_object->get_game_speed();
	delete fruit_object;

	/**
	*1 - normal fruit
	*2 - speed fruit
	*3 - grow fruit
	*/
	srand(time(NULL));
	fruit_type = rand() % 3 + 1;
	if (fruit_type == 1)
	{
		fruit_object = new Default_fruit();
	}
	else if (fruit_type == 2)
	{
		fruit_object = new Speed_fruit();
	}
	else if (fruit_type == 3)
	{
		fruit_object = new Big_fruit();
	}
	fruit_object->spawn_fruit();

	do
	{
		check = 0;
		for (int i = 1; i < snake.size(); i++)
		{
			if (fruit_object->get_fruit_x() == snake[i].first and fruit_object->get_fruit_y() == snake[i].second)
			{
				delete fruit_object;
				fruit_object->spawn_fruit();
				check = 1;
			}
		}
	} while (check == 1);

}

int Game_model::get_fruit_type()
{
	return fruit_type;
}

int Game_model::get_points()
{
	return points;
}

int Game_model::get_game_speed()
{
	return game_speed;
}