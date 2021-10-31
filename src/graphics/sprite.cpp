#include <SDL_image.h>
#include <cstring>

#include "graphics/sprite.hpp"

void CSprite::loadSpritesheet(const char* spriteSheetPath)
{
    const char* png = "png";

    if(strcmp(getFileExtension(spriteSheetPath), png))
    {
        puts(getFileExtension(spriteSheetPath));
        return;
    }

    spriteSheetRaw = IMG_Load(spriteSheetPath);
}

const char* CSprite::getFileExtension(const char* path)
{
    const char *dot = strrchr(path, '.');
    if(!dot || dot == path) return "";
    return dot + 1;
}

// void spr(uint16_t spriteX, uint16_t spriteY, uint16_t screenX, uint16_t screenY,
//          uint16_t w, uint16_t h, bool flipX, bool flipY)
// {

// }