#include "Player.h"

//Constructor for player. Creates the objects.
Player::Player(const char* Texturesheet, int x, int y, int g_width, int g_height)
{
    ObjTexture = LTexture::LoadTexture(Texturesheet);
    
    xpos = x;
    ypos = y;
    width = g_width;
    height = g_height;
    jump = false;
    animate = false;
    
    //Frame 1
    srcAnimate[ 0 ].x = 0;
    srcAnimate[ 0 ].y = 0;
    srcAnimate[ 0 ].w = 80;
    srcAnimate[ 0 ].h = 110;
    
    //Frame 2
    srcAnimate[ 1 ].x = 209;
    srcAnimate[ 1 ].y = 0;
    srcAnimate[ 1 ].w = 51;
    srcAnimate[ 1 ].h = 110;

    //Frame 3
    srcAnimate[ 2 ].x = 404;
    srcAnimate[ 2 ].y = 0;
    srcAnimate[ 2 ].w = 69;
    srcAnimate[ 2 ].h = 110;

    //Frame 4
    srcAnimate[ 3 ].x = 608;
    srcAnimate[ 3 ].y = 0;
    srcAnimate[ 3 ].w = 80;
    srcAnimate[ 3 ].h = 110;

    //Frame 5
    srcAnimate[ 4 ].x = 811;
    srcAnimate[ 4 ].y = 0;
    srcAnimate[ 4 ].w = 60;
    srcAnimate[ 4 ].h = 110;

    //Frame 6
    srcAnimate[ 5 ].x = 1021;
    srcAnimate[ 5 ].y = 0;
    srcAnimate[ 5 ].w = 60;
    srcAnimate[ 5 ].h = 100;

    //Frame 7
    srcAnimate[ 6 ].x = 1206;
    srcAnimate[ 6 ].y = 0;
    srcAnimate[ 6 ].w = 72;
    srcAnimate[ 6 ].h = 97;
    
    //Frame 8
    srcAnimate[ 7 ].x = 1408;
    srcAnimate[ 7 ].y = 0;
    srcAnimate[ 7 ].w = 79;
    srcAnimate[ 7 ].h = 91;
}

//Displaying the player.
//To see animation of player go to where the
//player update is called in the game.cpp and
//set player bool to true.
void Player::Update()
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

void Player::Render(long long int frame)
{
    //To draw our texture
    if (!animate && SDL_KEYUP)
    {
        SDL_RenderCopy(Game::renderer, ObjTexture, &srcR, &destR);
    }
    else
    {
        SDL_RenderCopy(Game::renderer, ObjTexture, &srcAnimate[frame % 7], &destR);
    }
}

//Getter & Setter function jump
void Player::set_jump(bool status)
{
    jump = status;
}

bool Player::get_jump()
{
    return jump;
}

//Getter & Setter function animate
void Player::set_animate(bool status)
{
    animate = status;
}

bool Player::get_animate()
{
    return animate;
}

//Getter & Setter function x position
void Player::set_xpos(float number)
{
    xpos = number;
}


float Player::get_xpos()
{
    return xpos;
}

//Getter & Setter function y position
void Player::set_ypos(float number)
{
    ypos = number;
}


float Player::get_ypos()
{
    return ypos;
}
