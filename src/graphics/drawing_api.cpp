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

// void CDraw::rect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t c)
// {

// }

/*
x1 > x2, y1 > y2
x1 < x2, y1 < y2

x1 < x2, y1 < y2
*/

void CDraw::rectfill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t c)
{
    if (x1 < x2 && y1 < y2) 
    {
        
        for(uint16_t i = x1; i < x2; i++)
        {
            for(uint16_t j = y1; j < y2; j++)
            {
                pset(i, j, c);
            }
        } 

    } else if (x1 > x2 && y1 > y2)
    {

        for(uint16_t i = x2; i < x1; i++)
        {
            for(uint16_t j = y2; j < y1; j++)
            {
                pset(i, j, c);
            }
        } 

    } else if (x1 > x2 && y1 < y2)
    {

        for(uint16_t i = x2; i < x1; i++)
        {
            for(uint16_t j = y1; j < y2; j++)
            {
                pset(i, j, c);
            }
        } 

    } else if (x1 < x2 && y1 > y2)
    {

        for(uint16_t i = x1; i < x2; i++)
        {
            for(uint16_t j = y2; j < y1; j++)
            {
                pset(i, j, c);
            }
        } 
        
    } else if (x1 > x2 && y1 == y2)
    {
        // TODO line
    } else if (x1 < x2 && y1 == y2)
    {
        // TODO line
    } else if (x1 == x2 && y1 < y2)
    {
        // TODO line
    } else if (x1 == x2 && y1 > y2)
    {
        // TODO line
    } else if ( x1 == x2 && y1 == y2 )
    {

        pset(x1, x2, c);

    } 
}


void CDraw::cls()
{
    memset( grid, 0, sizeof(grid) );
}