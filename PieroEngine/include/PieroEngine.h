#pragma once
#include "Core/Window/Window.h"
#include "Core/Texture/Texture.h"
#include "Core/ECS/GameObject.h"
#include "Core/Input/Input.h"

#include "Helper/helper.h"

#include <memory>
#include <functional>

namespace Piero {
class PieroEngine
{
public:
    PieroEngine();
    ~PieroEngine();
    static PieroEngine* GetInstance();
    virtual void Run(std::function<void()> callback = []() {});
    virtual void ShutDown();

    inline const WindowProps& GetWindowProps() const { return m_Window->GetProps(); }
    void SetWindowProps(const WindowProps& props);
protected:
    static PieroEngine* s_Instance;
    std::unique_ptr<Window> m_Window;
};
}