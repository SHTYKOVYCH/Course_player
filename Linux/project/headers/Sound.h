#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL.h>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

#define DESK_FREQ 44100

SDL_AudioDeviceID aDevice;
SDL_AudioSpec desirable, obtained;

typedef struct
{
	unsigned char soundnum;
	short** sounds;
}
sound_struct;

void ClearSound( sound_struct* sounds );

int PrepareSound( FILE* file, short* sounds );

int PrepareSounds( FILE* file, sound_struct* sounds );

void GenerateSine( short* wav, float freq );

void GenerateQuad( short* wav, float freq );

void GenerateTriangle( short* wav, float freq );

void GenerateSaw( short* wav, float freq );

int Beep( short* wav, unsigned int dur );

#endif
