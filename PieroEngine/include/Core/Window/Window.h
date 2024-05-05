#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace Piero {
struct WindowProps {
    int width, height;
    const char* title;
    WindowProps(const char* title, int width, int height) : title(title), width(width), height(height) {}
};
class Window {
public:
    Window(const WindowProps& props);
    void Update();
    void Events();
    void ShutDown();

    static void ClearBackground(int r, int g, int b, int a);

    inline const WindowProps& GetProps() const { return m_Props; }
    inline bool IsRunning() { return m_IsRunning; }
    ~Window();

    inline static SDL_Renderer* GetRenderer() { return m_Renderer; }
private:
    bool m_IsRunning;
    WindowProps m_Props;
    SDL_Window* m_Window;
    static SDL_Renderer* m_Renderer;
};
}