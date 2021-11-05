// This is a basic fenko example containing most of the standard api functions

// It's written in "lua" style. You shouldn't write your own projects this way, 
// but I believe this may be useful from people coming from pico-8 like libraries.

#include <SDL.h>
#include <SDL_mixer.h>

#include "graphics/drawing_api.hpp"
#include "graphics/sprite.hpp"
#include "graphics/render.hpp"

#include "input/input_api.hpp"
#include "sound/sound.hpp"

// main loop bool
bool running = true;

// create objects
CRenderHandler renderer;
CInput         input;
CDraw          draw;
CSound         sound;
//CSprite        sprite;

// circle variables
int circle_x = 10;
int circle_y = 10;
int circle_r = 5;
int circle_c = 8;

// load a music track
Mix_Music* music = sound.loadMusic("music.wav");

// quit function
void quit()
{

    // remember to clear your memory from unused music! (well, in this case it doesn't matter since we're exiting anyways but you get the point...)
    sound.freeMusic(music);

    // destroy the renderer and the window
    SDL_DestroyRenderer( renderer.renderer );
	SDL_DestroyWindow( renderer.window );

    // quit both SDL_Mix and SDL2
    Mix_Quit();
	SDL_Quit();

    // exit returning 0 exit code (success)
    exit(0);
}

void main_loop()
{
    // clear the board with color 1
    // see https://lospec.com/palette-list/pico-8 for a list of colors
    draw.clear(1);

    // draw a filled circle
    draw.circfill(circle_x, circle_y, circle_r, circle_c);

    // update input database (HAS TO BE CALLED EVERY FRAME, OTHERWISE THE USER WON'T BE ABLE TO PASS A CLOSE EVENT)
    input.updateInput();

    // check for input and move the circle if arrow keys are pressed
    if(input.btn(SDLK_LEFT))
    {
        circle_x -= 1;
    } 
    
    if (input.btn(SDLK_RIGHT))
    {
        circle_x += 1;
    } 
    
    if (input.btn(SDLK_UP))
    {
        circle_y -= 1;
    } 
    
    if (input.btn(SDLK_DOWN))
    {
        circle_y += 1;
    }

    SDL_Delay(10);

    // render everything (HAS TO BE CALLED AT THE END OF FRAME IF YOU'RE DRAWING ANYTHING)
    renderer.draw(); 
}


int main()
{

  // sprite.loadSpritesheet("spritesheet.png");


    while(running)
    {
        main_loop();
    }

    quit();

	return 0;
}

