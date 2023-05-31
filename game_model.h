#pragma once
#include "Snake.h"
#include "collisions.h"
#include "input.h"
#include "Fruit.h"
#include "Fruit2.h"
#include "Speed_fruit.h"
#include "Normal_fruit.h"
using namespace std;

enum class Direction
{
    None,
    Up,
    Down,
    Left,
    Right
};

class game_model
{
public:
    game_model(Snake& snake, Collisions& collisions, Input& input);
    void start_values();//sets the starting values of the game
    void fruit_operation(vector<pair<int, int>> snake);//if collisions with fruit occur, fruit is deleted, snake grows, points are added and new fruit is created
    int get_fruit_type();//returns fruit type
    int get_game_speed();//returns game speed
    int get_points();//returns points
    Fruit* fruit_object = nullptr; // Pointer to a Fruit object

private:
    int points;
    int fruit_type;
    int game_speed;
    int check;

    Snake& snake;
    Collisions& collisions;
    Input& input;

};

