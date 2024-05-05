#include "Player.h"
#include "Platform.h"

int main(int argc, char* argv[]) {
    auto app = Piero::PieroEngine::GetInstance();
    app->SetWindowProps(Piero::WindowProps("Platform", 800, 600));
    auto player = std::make_shared<Player>();
    auto platform = std::make_shared<Platform>();
    
    app->Run([&player, &platform]() {
        static int b = 211;
        Piero::Window::ClearBackground(148, 0, b, 1);
        player->Update();
        platform->Update();
        platform->CollisionDetect(player.get());
        if(b == 0) b = 211;
        b--;
    });
    app->ShutDown();
    return 0;
}