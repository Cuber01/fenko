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
    Mix_Quit();
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

    sound.playSound("FrogJump1.wav");
    
    while(running)
    {
        main_loop();
    }

    quit();

	return 0;
}
