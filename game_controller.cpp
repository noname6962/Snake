#include "game_controller.h"

game_controller::game_controller(game_model& model, game_view& view, Snake& snake, Collisions& collisions, Input& input) : model(model), collisions(collisions), view(view), snake(snake), input(input) {
}

void game_controller::launch()
{
    this->model.start_values();//seting up the game
    auto start = chrono::steady_clock::now(); // get the start time

    while (this->collisions.check_snake_collision(this->snake.get_snakebody()) == 1)
    {
        auto now = chrono::steady_clock::now(); // get the current time
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - start).count(); // calculate elapsed time in milliseconds

        this->input.set_input(); // Get the direction from the user

        if (elapsed == this->model.get_game_speed())
        {
            start = now; // reset the start time
            this->snake.move_snake();
            if (this->collisions.check_fruit_collision(this->snake.get_snakebody(), this->model.fruit_object->get_fruit_x(), this->model.fruit_object->get_fruit_y()) == 1)//checking for fruit collision
            {
                this->model.fruit_operation(this->snake.get_snakebody());//executing everything connected to eaten fruit
            }
            this->view.drawBoard(this->snake.get_snakebody(), this->model.fruit_object->get_fruit_x(), this->model.fruit_object->get_fruit_y(), this->model.get_fruit_type(), this->model.get_points());
        }

    }
}