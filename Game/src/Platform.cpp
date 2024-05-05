#include "Platform.h"
#include "Player.h"

Platform::Platform() {
    position = Vector2D(400, 400);
    size = Vector2D(150, 30);
}
void Platform::Update() {
    SetFillStyle(0, 255, 100, 255);
    FillRect(position.x, position.y, size.x, size.y);
}

void Platform::CollisionDetect(GameObject *object) {
    auto player = dynamic_cast<Player*>(object);
    if(player->position.y + player->velocity.y + player->size.y * player->scale.y >= position.y
		&& player->position.y + player->size.y * player->scale.y <= position.y
		&& player->position.x + player->size.x * player->scale.x - 100 > position.x
		&& player->position.x <= position.x + size.x - 100
    ) {
        player->velocity.y = 0;
    }
}