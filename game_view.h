#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Game_view
{
public:
	///this function draws the board
	void drawBoard(vector<pair<int, int>> snake, int fruit_x, int fruit_y, int fruit_type, int points);
};

