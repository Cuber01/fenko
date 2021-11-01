#include <SDL.h>
#include <SDL_mixer.h>

#include "graphics/drawing_api.hpp"
#include "input/input_api.hpp"
#include "sound/sound.hpp"
#include "graphics/render.hpp"
#include "graphics/sprite.hpp"

#include "types.hpp"
#include "canvas.hpp"


bool running = true;

// objects
CRenderHandler renderer;
CInput         input;
CDraw          draw;
CSound         sound;
CSprite        sprite;

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

    sprite.drawImage(0, 0, 10, 10);

    renderer.draw(); 
}


int main()
{

    sprite.loadSpritesheet("spritesheet.png");

    while(running)
    {
        main_loop();
    }

    quit();

	return 0;
}
