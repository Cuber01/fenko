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

        // Load spritesheet file. Has to be 256x256
        // Only .png files are supported
        void loadSpritesheet(const char* spriteSheetPath);

        // Draw a sprite from the spritesheet
        // spriteX, spriteY = coordinates of the left corner of your sprite on spritesheet
        // screenX, screenY = coordinates of the left corner from which the sprite shall be drawn on screen
        // w = width of the sprite, default 8
        // h = height of the sprite, default 8
        // flipX, flipY = whether the sprite shall be flipped on the X or Y axis. Default false
        void spr(uint16_t spriteX, uint16_t spriteY,
                       uint16_t screenX, uint16_t screenY,
                       uint16_t w=8, uint16_t h=8,
                       bool flipX=false, bool flipY=false);

};


#endif