#ifndef __SOUND_HPP
#define __SOUND_HPP

#include <SDL.h>
#include <SDL_mixer.h>

class CSound 
{
    public:
        CSound();

        // Load a sound chunk to memory
        // Note: To get Mix_Chunk* type you have to include SDL_mixer.h
        // Next action: playSound(sound)
        Mix_Chunk* loadSound(const char* soundPath);

        // Load music to memory
        // Note: To get Mix_Music* type you have to include SDL_mixer.h
        // Next action: playMusic(music)
        Mix_Music* loadMusic(const char* musicPath);

        // Free sound from memory
        // This should be done when you no longer need it
        void freeSound(Mix_Chunk* sound);

        // Free music from memory
        // This should be done when you no longer need it
        void freeMusic(Mix_Music* musicTrack);

        // Play a Mix_Chunk 
        // Change loops parameter to specify how many times it should loop (default 0)
        void playSound(Mix_Chunk* sound, uint8_t loops=0);

        // Play a music track once
        // Change loops parameter to specify how many times it should loop (default 0)
        void playMusic(Mix_Music* musicTrack, uint8_t loops=0);

        // Play a music track indefinitely
        // Next action: pauseMusic() or haltMusic()
        void loopMusic(Mix_Music* musicTrack);

        // Pause currently playing music
        // Next action: resumeMusic()
        void pauseMusic();

        // Resume currently paused music
        void resumeMusic();

        // Stop currently playing music
        void haltMusic();
        
};


#endif