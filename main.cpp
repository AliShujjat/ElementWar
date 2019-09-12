#include <iostream>
#include "Game.h"

//Defining the game pointer
Game* game = nullptr;

int main(int argc, const char * argv[])
{
    //All Variables to control speed of game.
    const int FPS = 60;
    const int FrameDelay = 1000/FPS;
    Uint32 FrameStart;
    int FrameTime;
    double frame = 0;
    
    //Creates the game enviornment.
    game = new Game();
    game->inint("Element War", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720);

    //Loops until quit isrunning is true.
    while (game->isrunning)
    {
        FrameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render(frame);
        frame += 0.2;
        
        FrameTime = SDL_GetTicks() - FrameStart;
        if (FrameDelay > FrameTime)
        {
            SDL_Delay(FrameDelay - FrameTime);
        }
    }
    game->clean();
    return 0;
}



