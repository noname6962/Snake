#include <iostream>
#include "game_controller.h"
#include "game_model.h"
#include "game_view.h"
using namespace std;

int main()
{
	game_view view;
	Collisions collisions;
	Input input;
	Snake snake(input);
	game_model model(snake, collisions, input);
	game_controller controller(model, view, snake, collisions, input);
	controller.launch();
	return 0;
}
