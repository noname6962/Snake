#include <iostream>
#include "Game_controller.h"
#include "Game_model.h"
#include "Game_view.h"
using namespace std;

int main()
{
	Game_view view;
	Collisions collisions;
	Input input;
	Snake snake(input);
	Game_model model(snake, collisions, input);
	Game_controller controller(model, view, snake, collisions, input);
	controller.launch();
	return 0;
}
