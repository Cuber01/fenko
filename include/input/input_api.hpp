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

        void updateInput();

        // check if button is currently pressed
        // use SDL_Keycodes https://wiki.libsdl.org/SDL_Keycode
        bool isButtonPressed(SDL_Keycode btn);

        // check if button is pressed but wasn't in the last frame
        // use SDL_Keycodes https://wiki.libsdl.org/SDL_Keycode
        bool wasButtonRecentlyPressed(SDL_Keycode btn);
        
};

#endif