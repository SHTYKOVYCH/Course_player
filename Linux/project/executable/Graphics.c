#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <math.h>

#include "Graphics.h"

int SetBGCLR( FILE* file, scene_struct* scene )
{
	if( fread( scene -> backColor, 1, 3, file ) != 3 )
	{
		return 2;
	}

	return 0;
}

int SetColor( FILE* file, scene_struct* scene )
{
	if( fread( scene -> drawColor, 1, 3, file ) != 3 )
	{
		return 2;
	}

	return 0;
}

int DrawShape( FILE* file, scene_struct* scene )
{
	unsigned char type;

	if( fread( &type, 1, 1, file ) != 1 )
	{
		return 2;
	}

	int error;
	switch( type )
	{
		case( 0 ):
			error = DrawPoint( file, scene );
			return error;
		case( 1 ):
			error = DrawLine( file, scene );
			return error;
		case( 2 ):
			error = DrawQuad( file, scene );
			return error;
		case( 3 ):
			error = DrawTriangle( file, scene );
			return error;
		case( 4 ):
			error = DrawCircle( file, scene );
			return error;
		case( 5 ):
			error = DrawWQuad( file, scene );
			return error;
		case( 6 ):
			error = DrawWTriangle( file, scene );
			return error;
		case( 7 ):
			error = DrawWCircle( file, scene );
			return error;
		default:
			return 3;
	}
}

int DrawPoint( FILE* file, scene_struct* scene )
{
	int X, Y;
	
	if( fread( &X, 4, 1, file ) != 1 )
	{
		return 2;
	}

	if( fread( &Y, 4, 1, file ) != 1 )
	{
		return 2;
	}
	
	glBegin( GL_POINTS );
		glColor3ubv( scene -> drawColor );
		glVertex2i( X, Y );
	glEnd();

	return 0;
}

int DrawLine( FILE* file, scene_struct* scene )
{
	int points[2][2];

	for( int i = 0; i < 2; ++i )
	{
		if( fread( &( points[i][0] ), 4, 1, file ) != 1 )
		{
			return 2;
		}

		if( fread( &( points[i][1] ), 4, 1, file ) != 1 )
		{
			return 2;
		}
	}

	glBegin( GL_LINES );
		glColor3ubv( scene -> drawColor );

		for( int i = 0; i < 2; ++i )
		{
			glVertex2i( points[i][0], points[i][1] );
		}

	glEnd();

	return 0;
}

int DrawQuad( FILE* file, scene_struct* scene )
{
	int points[4][4];

	for( int i = 0; i < 4; ++i )
	{
		if( fread( &( points[i][0] ), 4, 1, file ) != 1 )
		{
			return 2;
		}

		if( fread( &( points[i][1] ), 4, 1, file ) != 1 )
		{
			return 2;
		}
	}

	glBegin( GL_QUADS );
		glColor3ubv( scene -> drawColor );

		for( int i = 0; i < 4; ++i )
		{
			glVertex2i( points[i][0], points[i][1] );
		}

	glEnd();

	return 0;
}

int DrawTriangle( FILE* file, scene_struct* scene )
{
	int points[3][3];

	for( int i = 0; i < 3; ++i )
	{
		if( fread( &( points[i][0] ), 4, 1, file ) != 1 )
		{
			return 2;
		}

		if( fread( &( points[i][1] ), 4, 1, file ) != 1 )
		{
			return 2;
		}
	}

	glBegin( GL_TRIANGLES );
		glColor3ubv( scene -> drawColor );

		for( int i = 0; i < 3; ++i )
		{
			glVertex2i( points[i][0], points[i][1] );
		}

	glEnd();

	return 0;
}

int DrawCircle( FILE* file, scene_struct* scene )
{
	unsigned int X, Y, RAD;

	if( fread( &X, 4, 1, file ) != 1 )
	{
		return 2;
	}

	if( fread( &Y, 4, 1, file ) != 1 )
	{
		return 2;
	}

	if( fread( &RAD, 4, 1, file ) != 1 )
	{
		return 2;
	}

	glBegin( GL_TRIANGLE_FAN );
	
	glColor3ubv( scene -> drawColor );
	glVertex2i( X, Y );

	for( int i = 0; i < 361; ++i )
	{
		float theta = 2 * M_PI * i / 360;

		int x = RAD * cosf( theta );
		int y = RAD * sinf( theta );

		glVertex2i( X + x, Y + y );
	}

	glEnd();
	return 0;
}

int DrawWQuad( FILE* file, scene_struct* scene )
{
	int points[4][4];

	for( int i = 0; i < 4; ++i )
	{
		if( fread( &( points[i][0] ), 4, 1, file ) != 1 )
		{
			return 2;
		}

		if( fread( &( points[i][1] ), 4, 1, file ) != 1 )
		{
			return 2;
		}
	}

	glBegin( GL_LINE_LOOP );
		glColor3ubv( scene -> drawColor );

		for( int i = 0; i < 4; ++i )
		{
			glVertex2i( points[i][0], points[i][1] );
		}

	glEnd();

	return 0;
}

int DrawWCircle( FILE* file, scene_struct* scene )
{
	int X, Y, RAD;

	if( fread( &X, 4, 1, file ) != 1 )
	{
		return 2;
	}

	if( fread( &Y, 4, 1, file ) != 1 )
	{
		return 2;
	}

	if( fread( &RAD, 4, 1, file ) != 1 )
	{
		return 2;
	}

	glBegin( GL_LINE_LOOP );

	glColor3ubv( scene -> drawColor );
		
	for( int i = 0; i < 360; ++i )
	{
		float theta = 2 * M_PI * i / 360;

		int x = RAD * cosf( theta );
		int y = RAD * sinf( theta );

		glVertex2i( X + x, Y + y );
	}

	glEnd();
	return 0;
}

int DrawWTriangle( FILE* file, scene_struct* scene )
{
	int points[3][3];

	for( int i = 0; i < 3; ++i )
	{
		if( fread( &( points[i][0] ), 4, 1, file ) != 1 )
		{
			return 2;
		}

		if( fread( &( points[i][1] ), 4, 1, file ) != 1 )
		{
			return 2;
		}
	}

	glBegin( GL_LINE_LOOP );
		glColor3ubv( scene -> drawColor );

		for( int i = 0; i < 3; ++i )
		{
			glVertex2i( points[i][0], points[i][1] );
		}

	glEnd();

	return 0;
}

int SwapBuffer( FILE* file, scene_struct* scene )
{
	char bool;

	if( fread( &bool, 1, 1, file ) != 1 )
	{
		return 2;
	}

	glClearColor( scene -> backColor[0], scene -> backColor[1], scene -> backColor[2], 1 );

	SDL_GL_SwapWindow( gWindow );
	
	if( bool )
	{
		glClear( GL_COLOR_BUFFER_BIT );
	}
	return 0;
}
