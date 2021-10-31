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
CRenderHandler renderer;
CInput         input;
CDraw          draw;
CSound         sound;


void quit()
{
    SDL_DestroyRenderer( renderer.renderer );
	SDL_DestroyWindow( renderer.window );

    Mix_Quit();
	SDL_Quit();

    exit(0);
}


void main_loop()
{
    input.updateInput();

    renderer.draw(); 

}

Mix_Chunk* a = sound.loadSound("AppleCrunch.wav");
Mix_Music* b = sound.loadMusic("bp_MUS_CivilBATTLE.ogg");


int main()
{

        sound.playSound(a);
        sound.playMusic(b);

    while(running)
    {
        main_loop();
    }

    quit();

	return 0;
}
