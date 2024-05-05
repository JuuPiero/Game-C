#include "Core/Texture/Texture.h"
#include "Core/Window/Window.h"
#include "Helper/helper.h"

namespace Piero {

Texture::Texture(const char* filePath): m_FilePath(filePath), scale(Vector2D(1, 1)) {
    LoadImage(filePath);
}
Texture::~Texture() {
    PrintLn("Texture is destroyed");
    SDL_DestroyTexture(m_Texture);
}
void Texture::LoadImage(const char* filePath) {
    SDL_DestroyTexture(m_Texture);
    SDL_Surface* surface = IMG_Load(filePath);
    if (surface == NULL) {
        std::cout << "Failed to load image: " << IMG_GetError() << std::endl;
    }
    m_Texture = SDL_CreateTextureFromSurface(Window::GetRenderer(), surface);
    SDL_QueryTexture(m_Texture, NULL, NULL, &m_ImageWidth, &m_ImageHeight);
    SDL_FreeSurface(surface);
}
void Texture::Draw(int x, int y, int width, int height, bool flip) {
    SDL_Rect srcRect = {0, 0, width, height};
    SDL_Rect destRect = {x, y, width * scale.x, height * scale.y};
    SDL_RenderCopyEx(Window::GetRenderer(), m_Texture, &srcRect, &destRect, 0, nullptr, flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}
void Texture::DrawFrame(int x, int y, int width, int height, int row, int frame, bool flip) {
    SDL_Rect srcRect = {width * frame, height * row, width, height};
    SDL_Rect destRect = {x, y, width * scale.x, height * scale.y};
    SDL_RenderCopyEx(Window::GetRenderer(), m_Texture, &srcRect, &destRect, 0, nullptr, flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Texture::Draw() {
    SDL_RenderCopy(Window::GetRenderer(), m_Texture ,nullptr, nullptr);
}

}