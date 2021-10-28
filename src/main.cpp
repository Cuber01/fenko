#include <SDL.h>

#include "graphics/drawing_api.hpp"
#include "types.hpp"
#include "graphics/render.hpp"
#include "canvas.hpp"
#include "input.hpp"

bool running = true;

// objects
CRenderHandler Renderer;
CInputHandler  InputHandler;
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

    InputHandler.updateInput();

    Renderer.draw(); 

}

int main()
{
    init();

    while(running)
    {
        main_loop();
        draw.circfill(80, 80, 10, 8);
        draw.line(70, 60, 20, 70, 8);
    }

    quit();

	return 0;
}
