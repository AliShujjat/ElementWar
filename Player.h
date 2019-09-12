#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "LTexture.h"
#include "Game.h"


class Player
{
private:
    SDL_Texture* ObjTexture;
    SDL_Renderer* renderer;
    SDL_Rect srcAnimate[8];
    bool jump;
    bool animate;
    int height;
    int width;
    float xpos;
    float ypos;
    

public:
    SDL_Rect srcR, destR;
    
    Player(const char* Texturesheet, int x, int y, int height, int width);
    
    void Update();
    void Move();
    void Render(long long int frame);
    
    void set_jump(bool status);
    bool get_jump();
    
    void set_animate(bool status);
    bool get_animate();
    
    void set_xpos(float number);
    float get_xpos();
    
    void set_ypos(float number);
    float get_ypos();
    
};

#endif /* Player_hpp */
