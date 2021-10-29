#ifndef __SOUND_HPP
#define __SOUND_HPP

#include <SDL.h>
#include <SDL_mixer.h>

class CSound 
{

    public:
        void playSound(Mix_Chunk* soundEffect);

        void loopMusic(Mix_Music* musicTrack);
        
};


#endif