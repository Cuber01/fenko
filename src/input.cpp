#include <SDL.h>
#include "input.hpp"
#include "main.hpp"

void CInputHandler::updateInput()
{
    while (SDL_PollEvent(&event))
    {
        handleInput(&event);
    }
}


void CInputHandler::handleInput(SDL_Event* event)
{

    // mouse
    switch (event->type)
    {
        
        case SDL_MOUSEMOTION:
            SDL_GetMouseState( &cursorPos.x, &cursorPos.y );
            break;

        case SDL_MOUSEBUTTONDOWN:
            lastMouseKeyPressed = event->button.button;
            mouseIsPressed = true;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseIsPressed = false;
            break;

    }

    // keyboard and quit
    switch (event->type)
    {

    case SDL_KEYDOWN:
        lastKeyboardKeyPressed = event->key.keysym.sym;
        break;

    case SDL_QUIT:
        running = false;
        break;

    }

}