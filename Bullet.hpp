#pragma once
#include <stdio.h>
#include "Game.h"
#include "Weapons.h"

class Bullet
{
private:
    
    SDL_Texture* ObjTexture;
    SDL_Renderer* renderer;
    SDL_Rect srcAnimate[0];
    
    
public:
    SDL_Rect srcR, destR;
    float xpos;
    float ypos;
    
    Bullet(const char* Texturesheet, float x, float y);
    
    int get_x();
    void set_x(int x);
    
    int get_y();
    void set_y(int y);
    
    void Move();
    void Update();
    void Render();
};

