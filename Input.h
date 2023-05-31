#pragma once
#include <iostream>
#include <Windows.h>

class Input
{
public:
	void set_input();//setst the directions and checks for illigal turns
	int get_direction();//returns the direction
	void set_start_direction();//sets the start direction
private:
	int direction;
};


