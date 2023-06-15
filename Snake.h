#pragma once
#include "input.h"
#include <iostream>
#include <vector>
using namespace std;
class Snake
{
public:
	Snake(Input& input);

	///this function sets the snake to the starting position
	void start_snake();

	///this function moves the snake in the direction of the input
	void move_snake();

	///grows the snake by the grow_size
	void grow(int grow_size);
	vector<pair<int, int>> get_snakebody();

private:
	vector<pair<int, int>> snakebody;

	///x and y values of the tail position in prevous iterations of the game used to grow snake in correct places
	int x1, x2;
	int y1, y2;
	Input& input;


};

