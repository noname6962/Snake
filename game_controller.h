#pragma once

#include "game_model.h"
#include "game_view.h"
#include "input.h"
#include <chrono>
#include <thread>

using namespace std;

class Game_controller
{
public:
    ///this function is the constructor for the game_controller class
    Game_controller(Game_model& model, Game_view& view, Snake& snake, Collisions& collisions, Input& input);

    /**
    * this function does  the main loop of the game
    * 
    * firstly it sets the starting values of the game
    * starts game clock used for seting the game speed
    * 
    * then it enters game loop
    * and executes it until snake collides with itself or wall
    * 
    * in this loop it checks for user input
    * after that it checks if the time elapsed is equal to the game speed
    * if it is it moves the snake and checks for fruit and snake collision
    * and executes everything connected to eaten fruit
    * 
    * at the end of the loop it draws the board
    */
    void launch();

private:
    Game_model& model;
    Game_view& view;
    Snake& snake;
    Collisions& collisions;
    Input& input;
};

