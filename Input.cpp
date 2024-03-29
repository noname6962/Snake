#include "Input.h"

void Input::set_input()
{
    if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (direction != 2)
        {
            direction = 1;
        }
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (direction != 1)
        {
            direction = 2;
        }
    }
    else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
        if (direction != 4)
        {
            direction = 3;
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
        if (direction != 3)
        {
            direction = 4;
        }
    }
}

int Input::get_direction()
{
    return direction;
}

void Input::set_start_direction()
{
    direction = 1;
}


