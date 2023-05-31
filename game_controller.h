#pragma once

#include "game_model.h"
#include "game_view.h"
#include "input.h"
#include <chrono>
#include <thread>

using namespace std;

class game_controller
{
public:
    game_controller(game_model& model, game_view& view, Snake& snake, Collisions& collisions, Input& input);
    void launch();

private:
    game_model& model;
    game_view& view;
    Snake& snake;
    Collisions& collisions;
    Input& input;
};

