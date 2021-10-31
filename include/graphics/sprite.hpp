#ifndef __SPRITE_HPP
#define __SPRITE_HPP

#include <SDL.h>
#include "types.hpp"

#define SPRITESHEET_SIZE_X 256
#define SPRITESHEET_SIZE_Y 256

class CSprite
{
    private:
        SDL_Surface* spriteSheetRaw;
        uint8_t spriteSheetData[SPRITESHEET_SIZE_X][SPRITESHEET_SIZE_Y];

        const char* getFileExtension(const char* path);

        Color getPixel(const SDL_Surface* surface, uint16_t x, uint16_t y);

    public:
        void loadSpritesheet(const char* spriteSheetPath);


        void drawImage(uint16_t spriteX, uint16_t spriteY,
                       uint16_t screenX, uint16_t screenY,
                       uint16_t w=8, uint16_t h=8,
                       bool flipX=false, bool flipY=false);

};


#endif