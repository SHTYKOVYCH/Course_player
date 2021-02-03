#include <SDL2/SDL.h>
#include <math.h>

#include "Sound.h"

int initSound()
{
	SDL_zero(desirable);
	desirable.freq = DESK_FREQ;
	desirable.format = AUDIO_S16SYS;
	desirable.channels = 1;
	desirable.samples = 512;
	desirable.callback = NULL;

	aDevice = SDL_OpenAudioDevice(NULL, 0, &desirable, &obtained, 0);

	if( aDevice == NULL )
	{
		return 4;
	}
	
	if( desirable.freq != obtained.freq )
	{
		return 4;
	}

	if( desirable.format != obtained.format )
	{
		return 4;
	}

	if( desirable.channels != obtained.channels )
	{
		return 4;
	}

	if( desirable.samples != obtained.samples )
	{
		return 4;
	}

	SDL_ClearQueuedAudio( aDevice );
	
	return 0;
}

void deinitSound()
{
	SDL_ClearQueuedAudio( aDevice );
	SDL_CloseAudioDevice( aDevice );
}

int PrepareSounds( FILE* file, sound_struct* sounds )
{
	int error = Check( file, "SOUNDNUM" );

	if( error )
	{
		return error;
	}

	if( fread( &( sounds -> soundnum ), 1, 1, file ) != 1 )
	{
		return 2;
	}

	sounds -> sounds = (short**) calloc( sizeof( short* ),  sounds -> soundnum + 1 );

	if( sounds -> sounds == NULL )
	{
		return 6;
	}

	sounds -> sounds[0] = (short*) calloc( sizeof(short), DESK_FREQ );

	for( unsigned char i = 1; i < sounds -> soundnum+1; ++i )
	{
		sounds -> sounds[i] = (short*) malloc( sizeof( short ) * DESK_FREQ );
		if( sounds -> sounds[i] == NULL )
		{
			ClearSound( sounds );
			return 6;
		}

		error = PrepareSound( file, sounds -> sounds[i] );

		if( error )
		{
			ClearSound( sounds );
			return error;
		}
	}

	return 0;
}

int PrepareSound( FILE* file, short* wav )
{
	unsigned char type;

	if( fread( &type, 1, 1, file ) != 1 )
	{
		return 2;
	}

	if( type > 4 )
	{
		return 3;
	}

	float freq;

	if( fread( &freq, sizeof( float ), 1, file ) != 1 )
	{
		return 2;
	}
	
	if( freq < 0 )
	{
		return 3;
	}

	switch( type )
	{
		case( 0 ):
			GenerateSine( wav, freq );
			break;
		case( 1 ):
			GenerateQuad( wav, freq );
			break;
		case( 3 ):
			GenerateTriangle( wav, freq );
			break;
		case( 2 ):
			GenerateSaw( wav, freq );
			break;
	}

	return 0;
}

void GenerateSine( short* wav, float freq )
{
	for( int i = 0; i < DESK_FREQ; ++i )
	{
		wav[i] = sinf( 2*M_PI*i*freq / DESK_FREQ ) * 5000;
	}
}

void GenerateQuad( short* wav, float freq )
{
	for( int i = 0; i < DESK_FREQ; ++i )
	{
		wav[i] = 5000 * sinf( 2*M_PI*i*freq / DESK_FREQ );
		
		if( wav[i] > 0 )
		{
			wav[i] = 1500;
		}
		else
		{
			wav[i] = -1500;
		}
	}
}

void GenerateTriangle( short* wav, float freq )
{
	for(int i = 0; i < DESK_FREQ; ++i)
	{
		wav[i] = 2*5000/M_PI*asin(sin( ( 2*M_PI * freq * i ) / DESK_FREQ ));
	}
}

void GenerateSaw( short* wav, float freq )
{
	for(int i = 0; i < DESK_FREQ; ++i)
	{
		wav[i] = 2*1500/M_PI * atan(tan(M_PI*freq*i/DESK_FREQ));
	}
}

void ClearSound( sound_struct* sounds )
{
	for( unsigned char i = 0; i < sounds -> soundnum; ++i )
	{
		free( sounds -> sounds[i] );
	}

	free( sounds -> sounds );
}

int Beep( short* wav, unsigned int dur )
{
	int now = 0;
	SDL_PauseAudioDevice( aDevice, 0 );
	unsigned int time = SDL_GetTicks();
	for( int i = dur; i > 0; --i)
	{
		for(int k = DESK_FREQ/1000; k > 0; --k)
		{
			if( SDL_QueueAudio( aDevice, &(wav[now]), sizeof(short)) )
			{
				return 7;
			}
			now = (now + 1) % DESK_FREQ;
		}
	}
	time = SDL_GetTicks() - time;
	if( time < dur )
	{
		SDL_Delay( dur - time );
	}
	SDL_PauseAudioDevice( aDevice, 1 );
}
