#pragma once
#include "Fruit.h"
class Normal_fruit : public Fruit
{
	int get_game_speed() override;
	int get_grow_size() override;
};

