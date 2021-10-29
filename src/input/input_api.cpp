#include <SDL.h>
#include "input/input_api.hpp"
#include <map>

void CInput::updateInput()
{
    inputBackend.updateInput();
}

bool CInput::isButtonPressed(SDL_Keycode button)
{
    if (inputBackend.keyboard[button]) {
        return true;
    } 

    return false;
} 


bool CInput::wasButtonRecentlyPressed(SDL_Keycode button)
{
    return true;
}