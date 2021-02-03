#ifndef SCENE_H
#define SCENE_H

#include "Sound.h"

SDL_Window* gWindow;
SDL_GLContext GLContext;

typedef struct
{
	sound_struct sounds;
	unsigned char drawColor[3];
	unsigned char backColor[3];
}
scene_struct;

int Scene( FILE* mouvie );

int SDL_init( );

void SDL_deinit();

int ReadSceneFields(  FILE* file, unsigned int* num );

int initGL();

int WorkWithField( FILE* file, scene_struct* scene);

int PlaySound( FILE* file, sound_struct* sounds );

#endif
