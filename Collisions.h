#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Collisions
{
public:
	int check_snake_collision(vector<pair<int, int>> snake);
	int check_fruit_collision(vector<pair<int, int>> snake, int fruit_x, int fruit_y);

private:
	int fruit_collision;
};

