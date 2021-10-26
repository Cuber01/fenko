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
        grid[10][10] = 2;
        grid[11][10] = 3;
        grid[12][10] = 4;
        grid[13][10] = 5;
        grid[14][10] = 6;
    }

    quit();

	return 0;
}
