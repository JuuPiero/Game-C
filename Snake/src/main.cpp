#include "PieroEngine.h"
#include "Snake.h"
#include "Food.h"

int main(int argc, char* argv[]) {
    auto app = Piero::PieroEngine::GetInstance();
    app->SetWindowProps(Piero::WindowProps("Snake", 25 * 30, 25 * 30));
    auto snake = std::make_shared<Snake>();
    auto food = std::make_shared<Food>();
    
    app->Run([&snake, &food]() {
        Piero::Window::ClearBackground(0, 0, 0, 255);
        snake->Update();
        food->Update();
        if(snake->position.x == food->position.x && snake->position.y == food->position.y) {
            snake->Eat(food->position);
            food->Place();
        }
        Delay(100);
    });
    app->ShutDown();
    return 0;
}