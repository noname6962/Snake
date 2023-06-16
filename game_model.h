#pragma once
#include "Snake.h"
#include "collisions.h"
#include "input.h"
#include "Fruit.h"
#include "Big_fruit.h"
#include "Speed_fruit.h"
#include "Default_fruit.h"
using namespace std;

enum class Direction
{
    None,
    Up,
    Down,
    Left,
    Right
};

class Game_model
{
public:
    ///constructor funtion
    Game_model(Snake& snake, Collisions& collisions, Input& input);

    /**
    *sets the starting values of
    * 
    * points
    * snake star position
    * input
    * starting fruit type
    * and game speed
    */
    void start_values();

    /**
    *this functions is used if the snake eats a fruit
    * 
    * it grows a snake
    * adds points
    * sets game speed of eaten fruit
    * spawns new fruit
    * checks if the fruit spawned on the snake
    * and if so corrects it
    */
    void fruit_operation(vector<pair<int, int>> snake);

    ///returns fruit type
    int get_fruit_type();

    ///returns game speed
    int get_game_speed();

    ///returns points
    int get_points();

    ///Pointer to a Fruit object
    Fruit* fruit_object = nullptr;

private:
    int points;
    int fruit_type;
    int game_speed;
    int check;

    Snake& snake;
    Collisions& collisions;
    Input& input;

};

