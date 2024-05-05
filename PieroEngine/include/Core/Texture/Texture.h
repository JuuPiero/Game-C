#pragma once
#include "Math/Vector2D.h"
#include <iostream>
#include <SDL_image.h>
namespace Piero {
class Texture {

public:
    Texture(): scale(Vector2D(1, 1)) {}
    Texture(const char* filePath);
    ~Texture();
    void LoadImage(const char* filePath);
    void Draw();
    void Draw(Vector2D position, Vector2D size, bool flip = false);
    void Draw(int x, int y, int width, int height, bool flip = false);
    void DrawFrame(int x, int y, int width, int height, int row, int frame, bool flip = false);
    inline const std::string& GetFilePath() const { return m_FilePath; }

    inline int GetImageWidth() const { return m_ImageWidth; }
    inline int GetImageHeiht() const { return m_ImageHeight; }


public:
    Vector2D scale;
private:
    uint32_t m_Id;
    std::string m_FilePath;
    SDL_Texture* m_Texture;

    int m_ImageWidth;
    int m_ImageHeight;
};

}