
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include "sound/sound.hpp"

Mix_Music* CSound::loadMusic(const char* musicPath)
{
    Mix_Music* rv = Mix_LoadMUS( musicPath );
    if( rv == NULL )
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }

    return rv;
}

Mix_Chunk* CSound::loadSound(const char* soundPath)
{
    Mix_Chunk* rv = Mix_LoadWAV( soundPath );
    if( rv == NULL )
    {
        printf( "Failed to load music! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(1);
    }

    return rv;
}

void CSound::playSound(const char* soundPath)
{
    Mix_Chunk* sound = loadSound(soundPath);

    Mix_PlayChannel(-1, sound, 0);
}

void CSound::playMusic(char* musicPath)
{
    Mix_Music* musicTrack = loadMusic(musicPath);

    Mix_PlayMusic( musicTrack, 1 );
}


void CSound::loopMusic(char* musicPath)
{
    Mix_Music* musicTrack = loadMusic(musicPath);

    Mix_PlayMusic( musicTrack, -1 );
}


void CSound::pauseMusic()
{
    Mix_PauseMusic();
}

void CSound::resumeMusic()
{
    Mix_ResumeMusic();
}

void CSound::haltMusic()
{
    Mix_HaltMusic();
}






