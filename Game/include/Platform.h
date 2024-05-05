#pragma once
#include "PieroEngine.h"
using namespace Piero;
class Platform : public GameObject {
public:
    Platform();
    void Update() override;

    void CollisionDetect(GameObject* obj);

public:
    Vector2D size;
private:
};
