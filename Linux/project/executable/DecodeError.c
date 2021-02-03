#include <stdio.h>

#include "DecodeError.h"

void DecodeError( int errno )
{
	printf( "Error: " );
	switch( errno )
	{
		case(1):
			printf( "couldn't open file\n" );
			break;
		case(2):
			printf( "couldn't read from file\n" );
			break;
		case(3):
			printf( "wrong file structure\n" );
			break;
		case(4):
			printf( "SDL initialisation\n" );
			break;
		case(5):
			printf( "OpenGl initialisation error\n" );
			break;
		case(6):
			printf( "memory allocation\n" );
			break;
		case(7):
			printf( "graphics error\n" );
			break;
	}
}
