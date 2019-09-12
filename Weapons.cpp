#include "Weapons.h"
#include "SDL2/SDL.h"

Weapons::~Weapons(){} 

Weapons::Weapons(const char* Texturesheet, int x, int y)
{
    ObjTexture = LTexture::LoadTexture(Texturesheet);
    xpos = x;
    ypos = y;
    
    srcR.w = 44;
    srcR.h = 31;
    srcR.x = 0;
    srcR.y = 0;
    
    destR.x = xpos;
    destR.y = ypos;
    destR.w = srcR.w;
    destR.h = srcR.h;
    
    
    srcAnimate[ 0 ].x = 0;
    srcAnimate[ 0 ].y = 0;
    srcAnimate[ 0 ].w = 18;
    srcAnimate[ 0 ].h = 14;
}

void Weapons::Update()
{
    srcR.w = 44;
    srcR.h = 31;
    srcR.x = 0;
    srcR.y = 0;
    
    destR.x = xpos;
    destR.y = ypos;
    destR.w = srcR.w;
    destR.h = srcR.h;
    
}

void Weapons::Render()
{
    SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &destR);
}

//Getter & Setter function x position
void Weapons::set_xpos(float number)
{
    xpos = number;
}


float Weapons::get_xpos()
{
    return xpos;
}

//Getter & Setter function y position
void Weapons::set_ypos(float number)
{
    ypos = number;
}


float Weapons::get_ypos()
{
    return ypos;
}
