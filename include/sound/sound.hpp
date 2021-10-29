#ifndef __SOUND_HPP
#define __SOUND_HPP

#include <SDL.h>
#include <SDL_mixer.h>

class CSound 
{
    private:
        Mix_Chunk* loadSound(const char* soundPath);

        Mix_Music* loadMusic(const char* musicPath);

    public:
        void playSound(const char*soundPath);

        void playMusic(char* musicPath);

        void loopMusic(char* musicPath);

        void pauseMusic();

        void resumeMusic();

        void haltMusic();
        
};


#endif