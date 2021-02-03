#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void stop( FILE* in, FILE* out )
{
	fclose( in );
	fclose( out );
}

void main( int argc, char** argv )
{
	if( argc < 2 )
	{
		printf( "where the file?\n" );
		return;
	}

	FILE* in = fopen( argv[1], "r" );
	
	if( in == NULL )
	{
		printf( "Can't open the file\n");
		return;
	}

	FILE* out = fopen( "out.film", "wb" );

	if( out == NULL )
	{
		printf( "Can't create the file\n");
		fclose( in );
		return;
	}

	char str[100], substr[100];
	memset( str, 0, 100 );

	if( fscanf( in, "%s", str ) == EOF)
	{
		printf( "Error on reading FILE\n" );
		stop( in, out );
		return;
	}

	if( strcmp( str, "FILM" ) )
	{
		printf( "Wrong file structure: FILE\n" );
		stop( in, out );
		return;
	}

	if( fwrite( str, 1, 4, out ) != 4 )
	{
		printf( "Error on writing FILE\n" );
		stop( in, out );
		return;
	}
	
	int tmp_int;
	if( fscanf( in, "%s\t%d", str, &tmp_int ) == EOF)
	{
		printf( "Error on reading SCENENUM\n" );
		stop( in, out );
		return;
	}

	if( strcmp( str, "SCENENUM" ) )
	{
		printf( "Wrong file structure: SCENENUM\n" );
		stop( in, out );
		return;
	}

	if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
	{
		printf( "Error on writing SCENENUM\n" );
		stop( in, out );
		return;
	}

	if( tmp_int > 255 || tmp_int < 0)
	{
		printf( "Wrong file structure: scenenum char\n" ); 
		stop( in, out );
		return;
	}

	unsigned char scenenum = (char)tmp_int;

	if( !fwrite( &scenenum, 1, 1, out ) )
	{
		printf( "Error on writing SCENENUM char\n" );
		stop( in, out );
		return;
	}

	for( unsigned char i = 0; i < scenenum; ++i )
	{
		if( fscanf( in, "%s", str ) == EOF )
		{
			printf( "Error on reading SCENE\n");
			stop( in, out );
			return;
		}

	
		if( strcmp( str, "SCENE" ) )
		{
			printf( "Wrong file structure: SCENE\n" );
			stop( in, out );
			return;
		}
	
		if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
		{
			printf( "Error on writing SCENE\n" );
			stop( in, out );
			return;
		}


		unsigned char soundnum;
		if( fscanf( in, "%s\t%d", str, &tmp_int ) == EOF )
		{
			printf( "Error on reading soundnum\n" );
			stop( in, out );
			return;
		}

		if( strcmp( str, "SOUNDNUM" ) )
		{
			printf( "Wrong file structure: SOUNDNUM\n" );
			stop( in, out );
			return;
		}

		if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
		{
			printf( "Error on writing SCENENUM\n" );
			stop( in, out );
			return;
		}
		
		soundnum = tmp_int;
		if( !fwrite( &soundnum, 1, 1, out ) )
		{
			printf( "Error on writing soundnum char\n" );
			stop( in, out );
			return;
		}

		for( unsigned char j = 0; i < soundnum; ++i )
		{
			char type;
			float freq;

			if( fscanf( in, "\t\t%d\t%f", &tmp_int, &freq ) != 2 )
			{
				printf( "Error on reading wave\n" );
				stop( in, out );
				return;
			}

			if( tmp_int > 3 || tmp_int < 0 )
			{
				printf( "Error on type of wave\n" );
				stop( in, out );
				return;
			}

			type = tmp_int;

			if( fwrite( &type, 1, 1, out ) != 1 )
			{
				printf( "Error on writing sound type\n" );
				stop( in, out );
				return;
			}

			if( fwrite( &freq, sizeof(float), 1, out ) != 1 )
			{
				printf( "Error on writing sound freq\n" );
				stop( in, out );
				return;
			}
		}

		unsigned int fieldsnum;
		if( fscanf( in, "%s%d", str, &fieldsnum ) == EOF )
		{
			printf( "Error on reading SCENEFIELD\n");
			stop( in, out );
			return;
		}

		if( strcmp( str, "SCENEFIELDS" ) )
		{
			printf( "Wrong filestructure: SCENEFIELDS\n" );
			stop( in, out );
			return;
		}

		if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
		{
			printf( "Error on writing SCENEFIELDS\n" );
			stop( in, out );
			return;
		}

		if( fwrite( &fieldsnum, sizeof( int ), 1, out ) != 1 )
		{
			printf( "Error on writing fields num\n" );
			stop( in, out );
			return;
		}

		for( int j = 0; j < fieldsnum; ++j )
		{
			if( fscanf( in, "\t%s", str ) == EOF ) 
			{
				printf( "Error on reading field\n" );
				stop( in, out );
				return;
			}


			if( !strcmp( str, "BGCLR" ) || !strcmp( str, "COLOR" ) )
			{
				unsigned char red, green, blue;

				if( fscanf( in, "%d", &tmp_int ) != 1 )
				{
					printf( "Error on reading red of %s\n", str );
					stop( in, out );
					return;
				}

				if( tmp_int > 255 || tmp_int < 0 )
				{
					printf( "Wrong file structure: colors of %s\n", str );
					stop( in, out );
					return;
				}

				red = tmp_int;

				if( fscanf( in, "%d", &tmp_int ) == EOF )
				{
					printf( "Error on reading green of %s\n", str );
					stop( in, out );
					return;
				}

				if( tmp_int > 255 || tmp_int < 0 )
				{
					printf( "Wrong file structure: colors of %s\n", str );
					stop( in, out );
					return;
				}

				green = tmp_int;
				
				if( fscanf( in, "%d", &tmp_int ) == EOF )
				{
					printf( "Error on reading blue of %s\n", str );
					stop( in, out );
					return;
				}

				if( tmp_int > 255 || tmp_int < 0 )
				{
					printf( "Wrong file structure: colors of %s\n", str );
					stop( in, out );
					return;
				}

				blue = tmp_int;
				
				if( fwrite( &str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing: %s\n", str );
					stop( in, out );
					return;
				}

				if( fwrite( &red, 1, 1, out ) != 1 )
				{
					printf( "Error on writing red of %s\n", str );
					stop( in, out );
					return;
				}

				if( fwrite( &green, 1, 1, out ) != 1 )
				{
					printf( "Error on writing green of %s\n", str );
					stop( in, out );
					return;
				}
				
				if( fwrite( &blue, 1, 1, out ) != 1 )
				{
					printf( "Error on writing blue of %s\n", str );
					stop( in, out );
					return;
				}

				continue;
			}
			
			if( !strcmp( str, "SHAPE" ) )
			{
				if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing %s\n", str );
					stop( in, out );
					return;
				}

				char type;

				if( fscanf( in, "\t\t%d", &tmp_int ) == EOF )
				{
					printf( "Error on reading type of shape\n" );
					stop( in, out );
					return;
				}

				if( tmp_int > 7 )
				{
					printf( "Wrong structure of file: type of shape %d not defined\n", tmp_int);
					stop( in, out );
					return;

				}

				type = tmp_int;

				if( fwrite( &type, 1, 1, out ) != 1 )
				{
					printf( "Erro on writing type of %s\n", str );
					stop( in, out );
					return;
				}
				
				int pointsnum;

				switch( type )
				{
					case( 0 ):
						pointsnum = 1;
						break;
					case( 1 ):
						pointsnum = 2;
						break;
					case( 2 ):
					case( 5 ):
						pointsnum = 4;
						break;
					case( 3 ):
					case( 6 ):
						pointsnum = 3;
						break;
					default:
						break;
				}

				if( type != 4 && type != 7 )
				{
					for( int k = 0; k < pointsnum; ++k )
					{
						int x, y;
						if( fscanf( in, "\t\t%d%d", &( x ), &( y ) ) == EOF )
						{
							printf( "Error on reading points for %d\n", type );
							stop( in, out );
							return;
						}

						if( fwrite( &x, sizeof(int), 1, out ) != 1 )
						{
							printf( "Error on writing x for %s\n", str );
							stop( in, out );
							return;
						}

						if( fwrite( &y, sizeof(int), 1, out ) != 1 )
						{
							printf( "Error on writing y for %s\n", str );
							stop( in, out );
							return;
						}
					}

				}
				else
				{
					int x, y, rad;

					if( fscanf( in, "\t\t%d%d%d", &x, &y, &rad ) == EOF )
					{
						printf( "Error on reading fields of %s\n", str );
						stop( in, out );
						return;
					}

					if( fwrite( &x, sizeof(int), 1, out ) != 1 )
					{
						printf( "error on writing x for %s\n", str );
						stop( in, out );
						return;
					}

					if( fwrite( &y, sizeof(int), 1, out ) != 1 )
					{
						printf( "error on writing y for %s\n", str );
						stop( in, out );
						return;
					}
					
					if( fwrite( &rad, sizeof(int), 1, out ) != 1 )
					{
						printf( "error on writing rad for %s\n", str );
						stop( in, out );
						return;
					}
				}

				continue;
			}

			if( !strcmp( str, "SOUND" ) )
			{
				char type;
				int dur;

				if( fscanf( in, "\t\t%d%d", &tmp_int, &dur ) != 2 )
				{
					printf( "Error on reading fields of %s\n", str );
					stop( in, out );
					return;
				}

				if( tmp_int > 255 || tmp_int < 0 )
				{
					printf( "Sound Wrong file structure: %d type is not defined\n", tmp_int );
					stop( in, out );
					return;
				}

				type = tmp_int;
				
				if( dur < 0 )
				{
					printf( "Wrong file structure: duration cannot be negative\n" );
					stop (in, out );
					return;
				}

				if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing %s\n", str );
					stop( in, out );
					return;
				}
				
				if( fwrite( &type, 1, 1, out ) != 1 )
				{
					printf( "Error on writing type of %s\n", str );
					stop( in, out );
					return;
				}
				
				if( fwrite( &dur, sizeof(int), 1, out ) != 1 )
				{
					printf( "Error on writing dur of %s\n", str );
					stop( in, out );
					return;
				}
				
				continue;
			}

			if( !strcmp( str, "FRAME" ) )
			{
				if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing %s\n", str );
					stop( in, out );
					return;
				}

				char bool;

				if( fscanf( in, "\t\t%i", &tmp_int ) != 1 )
				{
					printf( "Error on bool\n");
							stop( in, out );
							return;
				}

				if( tmp_int != 0 && tmp_int != 1 )
				{
					printf( "Wrong SRAME\n");
					stop( in, out );
					return;
				}

				bool = tmp_int;

				if( fwrite( &bool, 1, 1, out ) != 1 )
				{
					printf( "Error on writing bool\n" );
					stop( in, out );
					return;
				}

				continue;
			}

			printf( "Wrong file structure: Field type %s\n", str );
			stop( in, out );
			return;
		}
	}

	printf( "Work done!\n" );

	stop( in, out );
	return;
}	
