#include <SDL_image.h>
#include <cstring>

#include "graphics/sprite.hpp"
#include "types.hpp"
#include "canvas.hpp"
#include "data.hpp"


Color CSprite::getPixel(const SDL_Surface* surface, uint16_t x, uint16_t y)
{
	// bytes per pixel
	const Uint8 bpp = surface->format->BytesPerPixel;

	Uint8* pixel = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	Uint32 PixelData = *(Uint32*)pixel;

	Color color;

	// Retrieve the RGB values of the specific pixel
	SDL_GetRGB(PixelData, surface->format, &color.r, &color.g, &color.b);

	return color;
}


void CSprite::loadSpritesheet(const char* spriteSheetPath)
{
    const char* png = "png";

    if(strcmp(getFileExtension(spriteSheetPath), png))
    {
        puts(getFileExtension(spriteSheetPath));
        return;
    }

    spriteSheetRaw = IMG_Load(spriteSheetPath);

    for (uint16_t x = 0; x < SPRITESHEET_SIZE_X; x++) {
        for (uint16_t y = 0; y < SPRITESHEET_SIZE_Y; y++) {

            Color pixelColor = getPixel(spriteSheetRaw, x, y);

            for(uint16_t i = 0; i < COLOR_AMOUNT; i++)
            {
                if(palette[i].r == pixelColor.r &&
                   palette[i].g == pixelColor.g &&
                   palette[i].b == pixelColor.b) 
                {
                    spriteSheetData[x][y] = i;
                }

            }

        }

    }
    
    SDL_FreeSurface(spriteSheetRaw);
}

const char* CSprite::getFileExtension(const char* path)
{
    const char *dot = strrchr(path, '.');
    if(!dot || dot == path) return "";
    return dot + 1;
}

void CSprite::drawImage(uint16_t spriteX, uint16_t spriteY, uint16_t screenX, uint16_t screenY,
                        uint16_t w, uint16_t h, bool flipX, bool flipY)
{

    if(flipX && flipY)
    {

        for(uint16_t x = 0; x < w; x++)
        {
            for(uint16_t y = 0; y < h; y++)
            {
                grid[screenX - x + w][screenY - y + h] = spriteSheetData[spriteX+x][spriteY+y]; 
            }
        }

    } else if (flipX)
    {

        for(uint16_t x = 0; x < w; x++)
        {
            for(uint16_t y = 0; y < h; y++)
            {
                grid[screenX - x + w][screenY+y] = spriteSheetData[spriteX+x][spriteY+y]; 
            }
        }

    } else if (flipY)
    {

        for(uint16_t x = 0; x < w; x++)
        {
            for(uint16_t y = 0; y < h; y++)
            {
                grid[screenX+x][screenY - y + h] = spriteSheetData[spriteX+x][spriteY+y]; 
            }
        }

    } else 
    {
        for(uint16_t x = 0; x < w; x++)
        {
            for(uint16_t y = 0; y < h; y++)
            {
                grid[screenX+x][screenY+y] = spriteSheetData[spriteX+x][spriteY+y]; 
            }
        }

    }

}