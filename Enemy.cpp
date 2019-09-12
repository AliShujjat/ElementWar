#include "Enemy.h"

//Constructor for player. Creates the objects.

Enemy::Enemy(){}

Enemy::Enemy(const char* Texturesheet, int x, int y, int g_width, int g_height)
{
    ObjTexture = LTexture::LoadTexture(Texturesheet);
    
    xpos = x;
    ypos = y;
    width = g_width;
    height = g_height;
    alive = true;
}

//Displaying the player.
//To see animation of player press spacebar plz
void Enemy::Update()
{
    srcR.w = width;
    srcR.h = height;
    srcR.x = 0;
    srcR.y = 0;
    
    destR.x = xpos;
    destR.y = ypos;
    destR.w = srcR.w;
    destR.h = srcR.h;
    
}

void Enemy::Render(long long int frame)
{
    //To draw our texture
    SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &destR);
}

//Getter & Setter function x position
void Enemy::set_xpos(float number)
{
    xpos = number;
}


float Enemy::get_xpos()
{
    return xpos;
}

//Getter & Setter function y position
void Enemy::set_ypos(float number)
{
    ypos = number;
}


float Enemy::get_ypos()
{
    return ypos;
}
