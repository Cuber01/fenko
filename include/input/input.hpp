#ifndef __INPUT_HPP
#define __INPUT_HPP

#include <SDL.h>
#include <map>
#include "types.hpp"

class CInputBackend {
    
    private:
        SDL_Event event;
        intVector2D cursorPos;

        std::map<int, bool> keyboard;

        void handleInput(SDL_Event* event);

    public:
        uint16_t lastKeyboardKeyPressed;
        uint8_t  lastMouseKeyPressed;

        bool mouseIsPressed = false;

        void updateInput();
        
};


#endif