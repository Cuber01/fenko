#include <SDL.h>

#include "types.hpp"
#include "render.hpp"
#include "canvas.hpp"
#include "input.hpp"

bool running = true;

// objects
CRenderHandler Renderer;
CInputHandler  InputHandler;

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

void main_loop()
{

    SDL_Delay(10);

    InputHandler.updateInput();

    Renderer.draw(); 

}

int main()
{
    init();

    while(running)
    {
        main_loop();
    }

    quit();

	return 0;
}
