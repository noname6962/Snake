#pragma once
#include "input.h"
#include <iostream>
#include <vector>
using namespace std;
class Snake
{
public:
	Snake(Input& input);
	void start_snake();//setst the snake to the starting position
	void move_snake();//moves the snake in the direction of the input
	void grow(int grow_size);//grows the snake by the grow_size
	vector<pair<int, int>> get_snakebody();

private:
	vector<pair<int, int>> snakebody;
	int x1, x2;//x and y values of the tail position in prevous iterations of the game used to grow snake in correct places
	int y1, y2;
	Input& input;


};

