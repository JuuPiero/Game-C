#pragma once
#include <PieroEngine.h>
using namespace Piero;
class Food : public GameObject {
public:
    Food();
    ~Food();
    void Update() override {
        SetFillStyle(0, 255 , 0, 255);
        FillRect(position.x, position.y, size.x, size.y);
    }
    void Place() {
        position.x = rand() % 25 * 30;
        position.y = rand() % 25 * 30;
    }
public:

    Vector2D size = Vector2D(30, 30);
private:

};

Food::Food() {
    position = Vector2D(10 * size.x, 10 * size.y);
}

Food::~Food()
{
}
