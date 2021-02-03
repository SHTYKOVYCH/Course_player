#include <string.h>
#include <stdio.h>

#include "ReadSceneNum.h"
#include "OpenFile.h"
#include "Check.h"

int ReadSceneNum( FILE* file, unsigned char* num )
{
	int error = Check( file, "SCENENUM" );

	if( error )
	{
		return error;
	}

	if( fread( num, 1, 1, file) != 1 )
	{
		return 2;
	}

	return 0;
}
