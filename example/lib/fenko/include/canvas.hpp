#ifndef __CANVAS_HPP
#define __CANVAS_HPP

#include <stdint.h>

#define ROWS 128
#define COLS 128

#define SCALE 4

#define WINDOW_WIDTH ROWS*SCALE
#define WINDOW_HEIGHT COLS*SCALE

extern uint8_t grid[ROWS][COLS];

#endif