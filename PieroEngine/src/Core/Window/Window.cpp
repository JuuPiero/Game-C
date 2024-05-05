#include "Core/Window/Window.h"
#include <iostream>
#include "Core/Input/Input.h"

namespace Piero {
SDL_Renderer* Window::m_Renderer = nullptr;

Window::Window(const WindowProps& props): m_Props(props) {
    int init = SDL_Init(SDL_INIT_EVERYTHING);
    if(init < 0) {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
    }
    m_Window = SDL_CreateWindow(m_Props.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_Props.width, m_Props.height, SDL_WINDOW_RESIZABLE);
    if(m_Window == NULL) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
    }
    m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
}

void Window::Update() {
    Events();
}

void Window::Events() {
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type) {
        case SDL_QUIT:
            ShutDown();
            break;
        case SDL_KEYDOWN:
            Input::GetInstance()->OnkeyDown(e);
            break;
        case SDL_KEYUP:
            Input::GetInstance()->OnkeyUp(e);
            break;
    }
}

void Window::ShutDown() {
    m_IsRunning = false;
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    SDL_Quit();
}

Window::~Window() {
    ShutDown();
}

void Window::ClearBackground(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
    SDL_RenderClear(m_Renderer);
}

}