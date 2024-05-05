#include "Helper/helper.h"
#include "Core/Window/Window.h"
#include <SDL_image.h>

void SetFillStyle(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(Piero::Window::GetRenderer(), r, g, b, a);
}

void FillRect(int x, int y, int width, int height) {
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(Piero::Window::GetRenderer(), &rect);
}
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius) {
    int offsetx, offsety, d;
    int status;
    offsetx = 0;
    offsety = radius;
    d = radius -1;
    status = 0;
    while (offsety >= offsetx) {

        status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                     x + offsety, y + offsetx);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                     x + offsetx, y + offsety);
        status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                     x + offsetx, y - offsety);
        status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                     x + offsety, y - offsetx);

        if (status < 0) {
            status = -1;
            break;
        }

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    return status;
}

void FillCircle(int x, int y, int radius) {
    SDL_RenderFillCircle(Piero::Window::GetRenderer(), x, y, radius);
}
void Delay(int miniSeconds) {
    SDL_Delay(miniSeconds);
}
// void SetBackgroundImage(const char * filepath) {
//     SDL_Surface* surface = IMG_Load(filepath);
//     if(surface == nullptr) {
//         std::cout << "cannot load image at " << filepath << std::endl;
//     }
//     SDL_Texture* m_Texture = SDL_CreateTextureFromSurface(Piero::Window::GetRenderer(), surface);
//     SDL_FreeSurface(surface);
//     SDL_RenderCopy(Piero::Window::GetRenderer(), m_Texture ,nullptr, nullptr);
//     SDL_DestroyTexture(m_Texture);
// }