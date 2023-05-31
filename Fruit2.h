#pragma once
#include "Fruit.h"
class Fruit2 : public Fruit
{
	int get_game_speed() override;
	int get_grow_size() override;
};

