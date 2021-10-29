#ifndef __INPUT_API_HPP
#define __INPUT_API_HPP

// if (key_map[SDLK_Return]) printf("Return has been pressed.");

#include <SDL.h>
#include "input.hpp"

#define btn isButtonPressed
#define btnp wasButtonRecentlyPressed

class CInput {
    
    private:
        CInputBackend inputBackend;

    public:

        // check if btn button is currently pressed
        bool isButtonPressed(SDL_Keycode btn);

        // check if btn button is pressed but wasn't in the last frame
        bool wasButtonRecentlyPressed(SDL_Keycode btn);
        
};

#endif