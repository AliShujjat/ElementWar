#include "Balochistan.h"

Balochistan::Balochistan(const char* name)
{
    Baloch = LTexture::LoadTexture(name);
    
    src.x = 0;
    src.y = 0;
    src.w = dest.w = 1280;
    src.h = dest.h = 720;
    
    dest.x = dest.y = 0;
}

void Balochistan::DrawMap()
{
    LTexture::Draw(Baloch, src, dest);
}
