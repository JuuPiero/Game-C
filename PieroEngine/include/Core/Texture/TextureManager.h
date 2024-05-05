#pragma once
#include <unordered_map>
#include "Core/Texture/Texture.h"
#include <memory>

namespace Piero {
class TextureManager {
public:
    TextureManager(/* args */);
    ~TextureManager();
    void Update();
    void AddTexture();
private:

};

}
