#include <stdint.h>
#include <memory.h>
#include <iostream>

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

void CDraw::line(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t c)
{
   int16_t m_new = 2 * (y2 - y1);
   int16_t slope_error_new = m_new - (x2 - x1);
   
   for (uint16_t x = x1, y = y1; x <= x2; x++)
   {
      pset(x, y, c);
 
      // Add slope to increment angle formed
      slope_error_new += m_new;
 
      // Slope error reached limit, time to
      // increment y and update slope error.
      if (slope_error_new >= 0)
      {
         y++;
         slope_error_new  -= 2 * (x2 - x1);
      }
   }
}

void CDraw::cls()
{
    memset( grid, 0, sizeof(grid) );
}