#include "Game_controller.h"

Game_controller::Game_controller(Game_model& model, Game_view& view, Snake& snake, Collisions& collisions, Input& input) : model(model), collisions(collisions), view(view), snake(snake), input(input) {
}

void Game_controller::launch()
{
    this->model.start_values();
    auto start = chrono::steady_clock::now();

    while (this->collisions.check_snake_collision(this->snake.get_snakebody()) == 1)
    {
        auto now = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - start).count();

        this->input.set_input();

        if (elapsed == this->model.get_game_speed())
        {
            start = now;
            this->snake.move_snake();
            if (this->collisions.check_fruit_collision(this->snake.get_snakebody(), this->model.fruit_object->get_fruit_x(), this->model.fruit_object->get_fruit_y()) == 1)
            {
                this->model.fruit_operation(this->snake.get_snakebody());
            }
            this->view.drawBoard(this->snake.get_snakebody(), this->model.fruit_object->get_fruit_x(), this->model.fruit_object->get_fruit_y(), this->model.get_fruit_type(), this->model.get_points());
        }

    }
}