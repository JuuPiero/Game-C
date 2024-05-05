#pragma once
#include <iostream>
#include <unordered_map>
#include <SDL.h>
#include "Helper/helper.h"

namespace Piero {
class Input {
public:
    Input();
    ~Input();
    void ShutDown();
    // void Update(SDL_Event& e);
    void OnkeyDown(SDL_Event& e);
    void OnkeyUp(SDL_Event& e);
    
    static Input* GetInstance();
    inline static const bool GetKeyDown(const char* key) { return s_Keys[key]; }

private:
    static Input* s_Instance;
    static std::unordered_map<std::string, bool> s_Keys;
};


}
