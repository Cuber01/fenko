#include <SDL.h>
#include <SDL_mixer.h>

#include "graphics/drawing_api.hpp"
#include "input/input_api.hpp"
#include "sound/sound.hpp"
#include "graphics/render.hpp"

#include "types.hpp"
#include "canvas.hpp"


bool running = true;

// objects
CRenderHandler Renderer;
CInput         input;
CDraw          draw;
CSound         sound;

void init()
{
    Renderer.init();
}

void quit()
{
    SDL_DestroyRenderer( Renderer.renderer );
	SDL_DestroyWindow( Renderer.window );
    Mix_Quit();
	SDL_Quit();
    exit(0);
}


void main_loop()
{
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
