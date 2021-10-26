#include <SDL.h>

#include "types.hpp"
#include "render.hpp"
#include "canvas.hpp"

// sdl
SDL_Event event;

//int
uint16_t lastKeyboardKeyPressed;
uint8_t  lastMouseKeyPressed;

//bool
bool mouseIsPressed = false;
bool running = true;

intVector2D cursorPos;

// objects
CRenderHandler Renderer;

void init()
{

    Renderer.init();

}

void quit()
{
    SDL_DestroyRenderer( Renderer.renderer );
	SDL_DestroyWindow( Renderer.window );
	SDL_Quit();
}

void handleEvent(SDL_Event* event)
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

    // keyboard
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

void main_loop()
{

    SDL_Delay(10);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        handleEvent(&event);
    }

    Renderer.draw(); 

}

int main(int argc, char *argv[])
{
    init();

    while(running)
    {
        main_loop();
    }

    quit();

	return 0;
}
