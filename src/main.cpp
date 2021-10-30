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

Mix_Chunk* a = sound.loadSound("FrogJump1.wav");
Mix_Music* b  = sound.loadMusic("bp_MUS_MantisBATTLE.ogg");

void main_loop()
{
    input.updateInput();

    Renderer.draw(); 

    sound.playSound(a);

}

int main()
{
    init();


    sound.playMusic(b);
    

    while(running)
    {
        main_loop();
    }

    Mix_FreeChunk(a);
    Mix_FreeMusic(b);

    quit();

	return 0;
}
