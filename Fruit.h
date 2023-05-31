#pragma once
#include <stdlib.h>
#include <time.h> 

class Fruit
{
public:
	int get_fruit_x();
	int get_fruit_y();
	void spawn_fruit();
	virtual int get_game_speed() = 0;
	virtual int get_grow_size() = 0;

	int fruit_x;
	int fruit_y;
	int game_speed;
	int grow_size;
};

