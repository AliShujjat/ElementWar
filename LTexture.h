#ifndef LTexture_hpp
#define LTexture_hpp

#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
#include "Game.h"

class LTexture
{
public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
    void Render( int x, int y, SDL_Rect* clip);
    
};

#endif /* LTexture_hpp */
