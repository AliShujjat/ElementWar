#include "Bullet.hpp"
#include "math.h"
#include <iostream>
using namespace std;

Bullet::Bullet(const char* Texturesheet, float x, float y)
{
    ObjTexture = LTexture::LoadTexture(Texturesheet);
    
    xpos = x;
    ypos = y;
    
    std::cout<<"In Bullet constrcutor ("<<xpos<<","<<ypos<<")"<<endl;
    
    srcR.w = 29;
    srcR.h = 8;
    srcR.x = 0;
    srcR.y = 0;

    destR.x = xpos;
    destR.y = ypos;
    destR.w = srcR.w;
    destR.h = srcR.h;
    
    srcAnimate[ 0 ].x = 0;
    srcAnimate[ 0 ].y = 0;
    srcAnimate[ 0 ].w = 29;
    srcAnimate[ 0 ].h = 8;
    
    std::cout<<"In Bullet constrcutor dest ("<<destR.x<<","<<destR.y<<")"<<endl;
}

void Bullet::Move()
{
    xpos -= 5;
}

int Bullet::get_x()
{
    return xpos;
}

int Bullet::get_y()
{
    return ypos;
}

void Bullet::set_x(int x)
{
    xpos = x;
}

void Bullet::set_y(int y)
{
    ypos = y;
}

void Bullet::Update()
{
    srcR.w = 29;
    srcR.h = 8;
    srcR.x = 0;
    srcR.y = 0;

    destR.x = xpos;
    destR.y = ypos;
    destR.w = srcR.w;
    destR.h = srcR.h;
    
    std::cout<<"In Bullet Update dest ("<<destR.x<<","<<destR.y<<")"<<endl;

}

void Bullet::Render()
{
    SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &destR);
}

//bool Bullet::CollisionDetection()
//{
//    if (xpos == enemy.getpositionx() && ypos == enemy.getpositiony())
//    {
//        return true;
//    }
//}

//void Bullet::set_active(bool y)
//{
//    is_active = y;
//}
//
//bool Bullet::get_active()
//{
//    return is_active;
//}



