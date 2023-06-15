#pragma once
#include "Fruit.h"
class Speed_fruit : public Fruit
{
	///implementations of virtual functions from base class
	int get_game_speed() override;
	int get_grow_size() override;
};

