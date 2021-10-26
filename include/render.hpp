#ifndef __RENDER_HPP
#define __RENDER_HPP


class CRenderHandler {
    public:
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        SDL_Surface* surface = NULL;
        SDL_Texture* texture = NULL;

        const char* glsl_version;
        SDL_GLContext gl_context;

        void init();
        void draw();
        void clear();

};


#endif