#include <stdint.h>
#include <memory.h>

#include "graphics/drawing_api.hpp"
#include "canvas.hpp"

void CDraw::pset(uint16_t x, uint16_t y, uint8_t c)
{
    grid[x][y] = c;
}

uint8_t CDraw::pget(uint16_t x, uint16_t y)
{
    return grid[x][y];
}
#include <stdio.h>
void CDraw::rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t c)
{

    for(uint16_t i = 0; i < w; i++)
    {
        pset(x+i, y, c);

        /*

        ────────

        */

        if(i == w-1)
        {
            for(uint16_t j = 0; j < h; j++)
            {
                pset(x+i, y+j, c);
            }


            /*

            ────────╮
                    │
                    │
                    │
                    

            */
        }
    }


    for(uint16_t i = 0; i < h; i++)
    {
        pset(x, y+i, c);

        /*
        
        ╭───────╮
        │       │
        │       │
        │       │
        

        */

        if(i == h-1)
        {
            for(uint16_t j = 0; j < w; j++)
            {
                pset(x+j, y+i, c);
            }


            /*

            ╭───────╮
            │       │
            │       │
            │       │  
            ╰───────╯

            */

        }
    }



}

void CDraw::rectfill(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t c)
{
    for(uint16_t i = 0; i < w; i++)
    {
        for(uint16_t j = 0; j < h; j++)
        {
            pset(x+i, y+j, c);
        }
    }
    
}


void CDraw::cls()
{
    memset( grid, 0, sizeof(grid) );
}