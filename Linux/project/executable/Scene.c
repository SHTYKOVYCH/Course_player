#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include "Scene.h"
#include "Sound.h"
#include "Check.h"
#include "Graphics.h"

extern SDL_Window* gWindow;
extern SDL_GLContext GLContext;

int Scene( FILE* mouvie )
{
	int error = Check( mouvie, "SCENE" );

	if( error )
	{
		return error;
	}

	scene_struct scene;

	error = PrepareSounds( mouvie, &( scene.sounds ) );

	if( error )
	{
		return error;
	}

	unsigned int scenefields;
	error = ReadSceneFields( mouvie, &scenefields );

	if( error )
	{
		ClearSound( &( scene.sounds ) );
		return error;
	}

	error = SDL_init();

	if( error )
	{
		ClearSound( &( scene.sounds ) );
		return error;
	}
	
	glClear( GL_COLOR_BUFFER_BIT );

	for( unsigned int i = 0; i < scenefields; ++i )
	{
		error = WorkWithField( mouvie, &scene );

		if( error )
		{
			ClearSound( &( scene.sounds ) );
			return error;
		}
	}

	SDL_deinit();

	ClearSound( &( scene.sounds ) );
	return 0;
}

int WorkWithField( FILE* file, scene_struct* scene )
{
	char check[6];
	check[5] = 0;
	
	if( fread( check, 1, 5, file ) != 5 )
	{
		return 2;
	}

	if( !strcmp( check, "BGCLR" ) )
	{
		int error = SetBGCLR( file, scene );
		
		return error;
	}

	if( !strcmp( check, "COLOR" ) )
	{
		int error = SetColor( file, scene );
		
		return error;
	}

	if( !strcmp( check, "SOUND" ) )
	{
		int error = PlaySound( file, &( scene -> sounds ) );
		return error;
	}

	if( !strcmp( check, "SHAPE" ) )
	{
		int error = DrawShape( file, scene );

		return error;
	}

	if( !strcmp( check, "FRAME" ) )
	{
		int error = SwapBuffer( file, scene );

		return error;
	}

	return 3;
}

int PlaySound( FILE* file, sound_struct* sounds )
{
	unsigned char num;
	
	if( fread( &num, 1, 1, file ) != 1 )
	{
		return 2;
	}

	if( num > sounds -> soundnum )
	{
		return 3;
	}

	int dur;

	if( fread( &dur, 4, 1, file ) != 1 )
	{
		return 2;
	}

	int error = Beep( sounds -> sounds[num], dur );

	return error;
}

void SDL_deinit()
{
	deinitSound();
	SDL_DestroyWindow( gWindow );

	SDL_Quit();
}

int SDL_init()
{
	if(SDL_Init( SDL_INIT_AUDIO | SDL_INIT_VIDEO ) < 0)
	{
		return 4;
	}

	if( initSound() )
	{
		return 4;
	}

	gWindow = SDL_CreateWindow( "Film", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );

	if( gWindow == NULL )
	{
		deinitSound();
		return 4;
	}

	if( initGL() )
	{
		deinitSound();
		SDL_deinit();
		return 7;
	}

	return 0;
}

int initGL()
{
	GLContext = SDL_GL_CreateContext( gWindow );

	if( GLContext == NULL )
	{
		return 7;
	}

	GLenum error = GL_NO_ERROR;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		return 7;
	}

	glOrtho( 0, 640, 480, 0, 0, 1 );

	error = glGetError();
	if( error != GL_NO_ERROR )
	{
		return 7;
	}

	return 0;
}

int ReadSceneFields( FILE* file, unsigned int* num )
{
	int error = Check( file, "SCENEFIELDS" );

	if( error )
	{
		return error;
	}

	if( fread( num, sizeof(int), 1, file ) != 1 )
	{
		return 2;
	}

	return 0;
}
