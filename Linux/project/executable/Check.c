#include <stdio.h>
#include <string.h>

#include "Check.h"

int Check( FILE* file, char* str )
{
	int length = strlen( str );
	char check[length+1];
	check[length] = 0;

	if( fread( check, 1, length, file ) != length )
	{
		return 2;
	}

	if( strcmp( check, str ) )
	{
		return 3;
	}

	return 0;
}
