#ifndef __RENDER_HPP
#define __RENDER_HPP

#include <SDL.h>

class CRenderHandler {
    public:
        CRenderHandler();

        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        SDL_Surface* surface = NULL;
        SDL_Texture* texture = NULL;

        void draw();
        void clear();

};


#endif