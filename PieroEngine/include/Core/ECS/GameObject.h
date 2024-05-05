#pragma once

#include "Math/Vector2D.h"
namespace Piero {
class GameObject {
public:
    GameObject();
    GameObject(double x, double y): position(Vector2D(x, y)) {};
    ~GameObject() = default;
    virtual void Start();
    virtual void Update();
public:
    Vector2D position;
    Vector2D scale;
// protected:
//     std::shared_ptr<Texture> m_Texture;

};

}