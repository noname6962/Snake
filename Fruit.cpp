#include "Fruit.h"

int Fruit::get_fruit_x()
{
	return fruit_x;
}

int Fruit::get_fruit_y()
{
	return fruit_y;
}

void Fruit::spawn_fruit()
{
	srand(time(NULL));

	fruit_x = rand() % 20 + 1;
	fruit_y = rand() % 10 + 1;
}

int Fruit::get_game_speed()
{
	return 0;
}

int Fruit::get_grow_size()
{
	return 0;
}

