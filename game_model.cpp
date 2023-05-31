#include "game_model.h"

game_model::game_model(Snake& snake, Collisions& collisions, Input& input) : snake(snake), input(input), collisions(collisions) {
}

void game_model::start_values()
{
	this->points = 1;
	this->snake.start_snake();//sets starting position of sanke
	this->input.set_start_direction(); // Set the starting direction
	fruit_object = new Normal_fruit(); // Assign the dynamically allocated Normal_fruit object to the fruit_object pointer
	check = 1; // Check is for checking if fruit spawned inside of snake
	fruit_type = 1;
	game_speed = 200;
	fruit_object->spawn_fruit(); // Spawn the fruit

}

void game_model::fruit_operation(vector<pair<int, int>> snake) // by fruit operation i mean adding points, growing sanke and creating new fruit
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

	srand(time(NULL));
	fruit_type = rand() % 3 + 1; // Generate a random number between 1 and 3
	//1 - normal fruit
	//2 - speed fruit
	//3 - grow fruit
	if (fruit_type == 1)
	{
		fruit_object = new Normal_fruit(); // Assign the dynamically allocated Normal_fruit object to the fruit_object pointer
	}
	else if (fruit_type == 2)
	{
		fruit_object = new Speed_fruit(); // Assign the dynamically allocated Speed_fruit object to the fruit_object pointer
	}
	else if (fruit_type == 3)
	{
		fruit_object = new Fruit2(); // Assign the dynamically allocated Fruit2 object to the fruit_object pointer
	}
	fruit_object->spawn_fruit(); // Spawn the fruit

	do //this function checks if fruit spawned inside of snake a if so spawns a new fruit
	{
		check = 0;
		for (int i = 1; i < snake.size(); i++) //checks collision with itself
		{
			if (fruit_object->get_fruit_x() == snake[i].first and fruit_object->get_fruit_y() == snake[i].second)
			{
				delete fruit_object;
				fruit_object->spawn_fruit(); // Spawn the fruit
				check = 1;
			}
		}
	} while (check == 1);

}

int game_model::get_fruit_type()
{
	return fruit_type;
}

int game_model::get_points()
{
	return points;
}

int game_model::get_game_speed()
{
	return game_speed;
}