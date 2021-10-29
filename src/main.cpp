#include <SDL.h>

#include "graphics/drawing_api.hpp"
#include "types.hpp"
#include "graphics/render.hpp"
#include "canvas.hpp"
#include "input/input.hpp"

bool running = true;

// objects
CRenderHandler Renderer;
CInputBackend  InputHandler;
CDraw          draw;

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

    draw.rect(10, 10, 20, 20, 8);

    // draw.rectfill(40, 40, 50, 50, 8);

    draw.line(80, 80, 73, 46, 8);

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
