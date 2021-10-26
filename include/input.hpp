#ifndef __INPUT_HPP
#define __INPUT_HPP

#include <SDL.h>
#include "types.hpp"

class CInputHandler {
    
    private:
        SDL_Event event;
        intVector2D cursorPos;

        void handleInput(SDL_Event* event);

    public:
        uint16_t lastKeyboardKeyPressed;
        uint8_t  lastMouseKeyPressed;

        bool mouseIsPressed = false;

        void updateInput();
        

};


#endif