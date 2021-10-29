#include <SDL.h>
#include <SDL_mixer.h>

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

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }
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
