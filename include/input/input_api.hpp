#ifndef __INPUT_API_HPP
#define __INPUT_API_HPP

// if (key_map[SDLK_Return]) printf("Return has been pressed.");

#include <SDL.h>
#include "input.hpp"

#define isButtonPressed btn
#define isMouseButtonPressed mbtn

class CInput {
    
    private:
        CInputBackend inputBackend;

    public:

        void updateInput();

        // check if button is currently pressed
        // use SDL_Keycode values https://wiki.libsdl.org/SDL_Keycode
        bool isButtonPressed(SDL_Keycode button);

        // check if mouse button is currently pressed
        // use either SDL_BUTTON_RIGHT, SDL_BUTTON_LEFT or SDL_BUTTON_MIDDLE 
        bool isMouseButtonPressed(uint8_t button);
        
};

#endif