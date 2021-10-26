#ifndef __DRAW_HPP
#define __DRAW_HPP

#include <stdint.h>

class CDraw {
    public:

        // Sets pixel at xy coordinates to c color
        void pset(uint16_t x, uint16_t y, uint8_t c);

        // Returns pixel color at xy coordinates
        uint8_t pget(uint16_t x, uint16_t y);

        // Draw an empty rectangle from x1 y1 (up left corner) to x2 y2 (down right corner) using c color
        void rect(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t c);

        // Draw a filled rectangle from x1 y1 (up left corner) to x2 y2 (down right corner) using c color
        void rectfill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t c);

        // Clears the screen
        void cls();

};


#endif