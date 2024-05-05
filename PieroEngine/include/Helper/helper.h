#pragma once
#include <iostream>
#include <SDL.h>

#define PrintLn(mess) std::cout << mess << std::endl;
void SetFillStyle(int r, int g, int b, int a);
void FillRect(int x, int y, int width, int height);
int SDL_RenderFillCircle(SDL_Renderer * renderer, int x, int y, int radius);
void FillCircle(int x, int y, int radius);
void Delay(int miniSeconds);
// void SetBackgroundImage(const char * filepath);