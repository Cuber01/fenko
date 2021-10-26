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

void CDraw::cls()
{
    memset( grid, 0, sizeof(grid) );
}