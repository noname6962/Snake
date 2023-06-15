#pragma once
#include <stdlib.h>
#include <time.h> 

class Fruit
{
public:
	///returns the x coordinate of the fruit
	int get_fruit_x();

	///returns the y coordinate of the fruit
	int get_fruit_y();

	/// spawns new fruit
	void spawn_fruit();

	/// virtual functions implemented in derived classes that returns the game speed and 
	virtual int get_game_speed() = 0;
	virtual int get_grow_size() = 0;

	int fruit_x;
	int fruit_y;
	int game_speed;
	int grow_size;
};

