#include "PieroEngine.h"
namespace Piero {
PieroEngine* PieroEngine::s_Instance = nullptr;
PieroEngine::PieroEngine() {}
void PieroEngine::SetWindowProps(const WindowProps& props) {
    m_Window = std::make_unique<Window>(props);
}

PieroEngine* PieroEngine::GetInstance() {
    if(s_Instance == nullptr) {
        s_Instance = new PieroEngine();
    }
    return s_Instance;
}


void PieroEngine::Run(std::function<void()> callback) {
    while(m_Window->IsRunning()) {
        // SetFillStyle(100, 20, 200, 255);
        // SDL_RenderClear(Window::GetRenderer());
        if(callback != nullptr) {
            callback();
        }

        SDL_RenderPresent(Window::GetRenderer());
        m_Window->Update();
        SDL_Delay(2);
    }
}

void PieroEngine::ShutDown() {
    m_Window->ShutDown();
    Input::GetInstance()->ShutDown();
    delete s_Instance;
    s_Instance = nullptr;
}
PieroEngine::~PieroEngine() {
    ShutDown();
}

}