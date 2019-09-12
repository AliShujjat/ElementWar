#pragma once
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include <SDL2_mixer/SDL_mixer.h>
#include "Player.h"
#include "LTexture.h"
#include "Balochistan.h"
#include "Weapons.h"
#include "Enemy.h"
#include "Bullet.hpp"
#include <cmath>
#include <iostream>
#undef main

class Game
{
public:
    bool isrunning;
    SDL_Window* window;
    Mix_Music* music;
    Mix_Chunk* jump;
    
public:
    static SDL_Renderer* renderer;
    Game();
    ~Game();
    void inint(const char* title, int xpos, int ypos, int width, int height);
    void handleEvents();
    void update();
    void render(long long int frame);
    void clean();
};
