#ifndef __DRAW_HPP
#define __DRAW_HPP

#include <stdint.h>

class CDraw {
    public:

        // Sets pixel at xy coordinates to c color
        void pset(uint16_t x, uint16_t y, uint8_t c);

        // Returns pixel color at xy coordinates
        uint8_t pget(uint16_t x, uint16_t y);

        // Clears the screen
        void cls();

};


#endif