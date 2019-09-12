#pragma once
#include <stdio.h>
#include "Game.h"
#include "LTexture.h"


class Enemy
{
protected:
    SDL_Texture* ObjTexture;
    SDL_Renderer* renderer;
    SDL_Rect srcAnimate[8];
    int height;
    int width;
    float xpos;
    float ypos;
    bool alive;
    
    
public:
    SDL_Rect srcR, destR;
    
    Enemy();
    Enemy(const char* Texturesheet, int x, int y, int height, int width);
    
    void Update();
    void Move();
    void Render(long long int frame);
    
    void set_xpos(float number);
    float get_xpos();
    
    void set_ypos(float number);
    float get_ypos();
    
    void set_alive(bool status);
    bool get_alive();
    
};
