#pragma once
#include <iostream>
#include <Windows.h>

class Input
{
public:
	///sets the directions and checks for illigal turns
	void set_input();

	///returns the direction of the snake
	int get_direction();

	///sets the start direction of the snake
	void set_start_direction();

private:
	int direction;
};


