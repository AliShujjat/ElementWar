//
//  Balochistan.hpp
//  Let'sMakeGames
//
//  Created by Ali Shujjat on 21/11/2018.
//  Copyright © 2018 Ali Shujjat. All rights reserved.
//

#ifndef Balochistan_hpp
#define Balochistan_hpp

#include <stdio.h>
#include "Game.h"
#include "LTexture.h"
#include "string"

class Balochistan {
private:
    SDL_Rect src, dest;
    SDL_Texture* Baloch;
    
public:
    Balochistan(const char* name);
    void LoadMap();
    void DrawMap();
    
    
};

#endif /* Balochistan_hpp */
