#ifndef __INPUT_HPP
#define __INPUT_HPP

#include <SDL.h>
#include <map>
#include "types.hpp"

class CInputBackend {
    
    private:
        SDL_Event event;
        intVector2D cursorPos;

        void handleInput(SDL_Event* event);

    public:
        std::map<int, bool> keyboard;
        std::map<int, bool> oldKeyboard;


        bool mouseIsPressed = false;
        uint8_t  lastMouseKeyPressed;

        void updateInput();
        
};


#endif