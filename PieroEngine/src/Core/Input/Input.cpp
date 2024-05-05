#include "Core/Input/Input.h"

namespace Piero {
Input* Input::s_Instance = nullptr;
std::unordered_map<std::string, bool> Input::s_Keys;

Input::Input() {}
Input::~Input() {
    s_Keys.clear();
    delete s_Instance;
    s_Instance = nullptr;
}
Input* Input::GetInstance() {
    if (s_Instance == nullptr) {
        s_Instance = new Input();
    }
    return s_Instance;
}
void Input::OnkeyDown(SDL_Event& e) {
    switch( e.key.keysym.sym ) {
        case SDLK_LEFT:
            PrintLn("pressed left");
            s_Keys["ArrowLeft"] = true;
            break;
        case SDLK_RIGHT:
            PrintLn("pressed right");
            s_Keys["ArrowRight"] = true;
            break;
        case SDLK_UP:
            s_Keys["ArrowUp"] = true;
            break;
        case SDLK_DOWN:
            s_Keys["ArrowDown"] = true;
            break;
        case SDLK_SPACE:
            PrintLn("pressed space");
            s_Keys["Space"] = true;
            break;
        default:
            break;
    }
}
void Input::OnkeyUp(SDL_Event& e) {
    switch( e.key.keysym.sym ) {
        case SDLK_LEFT:
            PrintLn("release key");
            s_Keys["ArrowLeft"] = false;
            break;
        case SDLK_RIGHT:
            PrintLn("release right");
            s_Keys["ArrowRight"] = false;
            break;
        case SDLK_UP:
            s_Keys["ArrowUp"] = false;
            break;
        case SDLK_DOWN:
            s_Keys["ArrowDown"] = false;
            break;
        case SDLK_SPACE:
            PrintLn("release space");
            s_Keys["Space"] = false;
            break;
        default:
            break;
    }
}

void Input::ShutDown() {
    s_Keys.clear();
    delete s_Instance;
    s_Instance = nullptr;
}



}