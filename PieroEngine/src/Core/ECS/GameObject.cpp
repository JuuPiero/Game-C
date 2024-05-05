#include "Core/ECS/GameObject.h"
#include "Helper/helper.h"

namespace Piero {
GameObject::GameObject(): position(Vector2D(0, 0)) {
    PrintLn("Created GameObject");
    Start();
}

void GameObject::Start() {

}

void GameObject::Update() {

}
}