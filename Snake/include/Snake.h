#pragma once
#include "PieroEngine.h"
#include <vector>
using namespace Piero;
class Snake : public GameObject {
public:
    Snake();
    ~Snake();
    void Update() override;
    void Eat(Vector2D foodPos) {
        m_Segments.push_back(foodPos);
    }
public:
    Vector2D velocity;
    Vector2D size = Vector2D(30, 30);
private:
    std::vector<Vector2D> m_Segments;
};
void Snake::Update() {
    if(Input::GetKeyDown("ArrowRight")) {
        velocity.x = 1;
        velocity.y = 0;
    }
    else if(Input::GetKeyDown("ArrowLeft")) {
        velocity.x = -1;
        velocity.y = 0;
    }
    else if(Input::GetKeyDown("ArrowUp")) {
        velocity.x = 0;
        velocity.y = -1;
    }
    else if(Input::GetKeyDown("ArrowDown")) {
        velocity.x = 0;
        velocity.y = 1;
    }
    position.x = position.x + velocity.x * size.x;
    position.y = position.y + velocity.y * size.x;

    SetFillStyle(255, 0, 0, 255);
    FillRect(position.x, position.y, size.x, size.y);

  

    if(m_Segments.size() - 1 > 0) {
        m_Segments[0] = position;
        for (size_t i = m_Segments.size(); i > 0; i--) {
            m_Segments[i] = m_Segments[i - 1];
        }
    }

    for (auto &segment : m_Segments) {
        FillRect(segment.x, segment.y, size.x, size.y);
    }
}

Snake::Snake() {
    m_Segments.push_back(position);
}

Snake::~Snake() {
    m_Segments.clear();
}
