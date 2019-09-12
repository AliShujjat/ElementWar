#pragma once
#include <stdio.h>
#include "SDL2/SDL.h"
#include "LTexture.h"
#include "Game.h"

class Weapons
{
protected:
    SDL_Rect srcR, destR;
    SDL_Texture* ObjTexture;
    SDL_Renderer* renderer;
    SDL_Rect srcAnimate[0];
    float xpos;
    float ypos;

public:
    Weapons(const char* Texturesheet, int x, int y);
    ~Weapons();
    
    void Render();
    void Update();
    
    void set_xpos(float number);
    float get_xpos();
    
    void set_ypos(float number);
    float get_ypos();
    
};
