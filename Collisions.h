#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Collisions
{
public:
	///this function checks if the snake collides with itself or the wall
	int check_snake_collision(vector<pair<int, int>> snake);

	///this function checks if the snake collides with the fruit
	int check_fruit_collision(vector<pair<int, int>> snake, int fruit_x, int fruit_y);
};

