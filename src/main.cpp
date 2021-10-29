#include <SDL.h>

#include "graphics/drawing_api.hpp"
#include "types.hpp"
#include "graphics/render.hpp"
#include "canvas.hpp"
#include "input/input_api.hpp"

bool running = true;

// objects
CRenderHandler Renderer;
CInput         input;
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
    exit(0);
}

void main_loop()
{

    SDL_Delay(10);


    input.updateInput();

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
