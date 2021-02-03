#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OpenFile.h"
#include "DecodeError.h"
#include "ReadSceneNum.h"
#include "Scene.h"

void main( int argc, char** argv )
{
	FILE* mouvie;
	
	int error = OpenFile( argc, argv, &mouvie );

	if( error )
	{
		DecodeError( error );
		return;
	}

	unsigned char sceneNum;

	error = ReadSceneNum( mouvie, &sceneNum );
	
	if( error )
	{
		DecodeError( error );
		fclose( mouvie );
		return;
	}

	for( unsigned char i = 0; i < sceneNum; ++i )
	{
		error = Scene( mouvie );
		
		if( error )
		{
			DecodeError( error );
			break;
		}
	}

	fclose(mouvie);
	return;
}
