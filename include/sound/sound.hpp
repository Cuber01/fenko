#ifndef __SOUND_HPP
#define __SOUND_HPP

#include <SDL.h>
#include <SDL_mixer.h>

#define sfx         playSound
#define music       playMusic
#define loop_music  loopMusic
#define pause_music pauseMusic
#define stop_music  haltMusic

class CSound 
{
    public:
        CSound();

        Mix_Chunk* loadSound(const char* soundPath);

        Mix_Music* loadMusic(const char* musicPath);

        void playSound(Mix_Chunk* sound);

        void playMusic(Mix_Music* musicTrack);

        void loopMusic(Mix_Music* musicTrack);

        void pauseMusic();

        void resumeMusic();

        void haltMusic();
        
};


#endif