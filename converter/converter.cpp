#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void stop( FILE* in, FILE* out )
{
	fclose( in );
	fclose( out );
}

int main( int argc, char** argv )
{
	
	if( argc < 2 )
	{
		printf( "where the file?\n" );
		return 0;
	}

	FILE* in = fopen( argv[1], "r" );
	
	if( in == NULL )
	{
		printf( "Can't open the file\n");
		return 1;
	}

	FILE* out = fopen( "out.film", "wb" );

	if( out == NULL )
	{
		printf( "Can't create the file\n");
		fclose( in );
		return 1;
	}

	char str[100], substr[100];
	memset( str, 0, 100 );

	if( fscanf( in, "%s\t#%*[a-zA-Z \t0-9]", str ) != 1)
	{
		printf( "Error on reading FILE\n" );
		stop( in, out );
		return 1;
	}
printf( "%s\n", str);
	if( strcmp( str, "FILM" ) )
	{
		printf( "Wrong file structure: FILE\n" );
		stop( in, out );
		return 1;
	}

	if( fwrite( str, 1, 4, out ) != 4 )
	{
		printf( "Error on writing FILE\n" );
		stop( in, out );
		return 1;
	}
	
	int tmp_int;

	if( fscanf( in, "%s\t%d\t#%*[a-zA-Z \t0-9]", str, &tmp_int ) != 2 )
	{
		printf( "Error on reading SCENENUM", str );
		stop( in, out );
		return 1;
	}
printf( "%s\n", str);
	if( strcmp( str, "SCENENUM" ) )
	{
		printf( "Wrong file structure: SCENENUM\n" );
		stop( in, out );
		return 1;
	}

	if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
	{
		printf( "Error on writing SCENENUM\n" );
		stop( in, out );
		return 1;
	}

	if( tmp_int > 255 || tmp_int < 0)
	{
		printf( "Wrong file structure: scenenum char\n" ); 
		stop( in, out );
		return 1;
	}

	unsigned char scenenum = (char)tmp_int;

	if( !fwrite( &scenenum, 1, 1, out ) )
	{
		printf( "Error on writing SCENENUM char\n" );
		stop( in, out );
		return 1;
	}

	for( unsigned char i = 0; i < scenenum; ++i )
	{
		if( fscanf( in, "%s\t#%*[a-zA-Z \t0-9]", str ) != 1 )
		{
			printf( "Error on reading SCENE\n");
			stop( in, out );
			return 1;
		}
printf( "%s\n", str);
	
		if( strcmp( str, "SCENE" ) )
		{
			printf( "Wrong file structure: SCENE\n" );
			stop( in, out );
			return 1;
		}
	
		if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
		{
			printf( "Error on writing SCENE\n" );
			stop( in, out );
			return 1;
		}
		
		unsigned int fieldsnum;
		if( fscanf( in, "%s\t%d\t#%*[a-zA-Z \t0-9]", str, &fieldsnum ) != 2)
		{
			printf( "Error on reading SCENEFIELD\n");
			stop( in, out );
			return 1;
		}
printf( "%s\n", str);
		if( strcmp( str, "SCENEFIELDS" ) )
		{
			printf( "Wrong filestructure: SCENEFIELDS\n" );
			stop( in, out );
			return 1;
		}

		if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
		{
			printf( "Error on writing SCENEFIELDS\n" );
			stop( in, out );
			return 1;
		}

		if( fwrite( &fieldsnum, 4, 1, out ) != 1 )
		{
			printf( "Error on writing fields num\n" );
			stop( in, out );
			return 1;
		}

		for( int j = 0; j < fieldsnum; ++j )
		{
			if( fscanf( in, "\t%s\t#%*[a-zA-Z \t0-9]", str ) != 1 ) 
			{
				printf( "Error on reading field\n" );
				stop( in, out );
				return 1;
			}
printf( "%s\n", str);

			if( !strcmp( str, "BGCLR" ) || !strcmp( str, "COLOR" ) )
			{
				unsigned char color;

				if( fscanf( in, "\t\t%d\t#%*[a-zA-Z \t0-9]", &tmp_int ) != 1 )
				{
					printf( "Error on reading color of %s\n", str );
					stop( in, out );
					return 1;
				}

				if( tmp_int > 15 || tmp_int < 0 )
				{
					printf( "Wrong file structure: colors type" );
					stop( in, out );
					return 1;
				}

				color = tmp_int;

				if( fwrite( str, 1, strlen(str), out) != strlen(str))
				{
					printf( "Error on writing color: Color\n");
					stop(in,out);
					return 1;
				}

				if( fwrite( &color, 1, 1, out ) != 1 )
				{
					printf( "Error on writing color of %s\n", str );
					stop( in, out );
					return 1;
				}

				continue;
			}
			
			if( !strcmp( str, "SHAPE" ) )
			{
				if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing %s\n", str );
					stop( in, out );
					return 1;
				}

				char type;

				if( fscanf( in, "\t\t%d\t#%*[a-zA-Z \t0-9]", &tmp_int ) == EOF )
				{
					printf( "Error on reading type of shape\n" );
					stop( in, out );
					return 1;
				}

				if( tmp_int > 7 )
				{
					printf( "Wrong structure of file: type of shape %d not defined\n", tmp_int);
					stop( in, out );
					return 1;

				}

				type = tmp_int;

				if( fwrite( &type, 1, 1, out ) != 1 )
				{
					printf( "Erro on writing type of %s\n", str );
					stop( in, out );
					return 1;
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
						if( fscanf( in, "\t\t%d%d\t#%*[a-zA-Z \t0-9]", &( x ), &( y ) ) == EOF )
						{
							printf( "Error on reading points for %d\n", type );
							stop( in, out );
							return 1;
						}

						if( fwrite( &x, sizeof(int), 1, out ) != 1 )
						{
							printf( "Error on writing x for %s\n", str );
							stop( in, out );
							return 1;
						}

						if( fwrite( &y, sizeof(int), 1, out ) != 1 )
						{
							printf( "Error on writing y for %s\n", str );
							stop( in, out );
							return 1;
						}
					}

				}
				else
				{
					int x, y, rad;

					if( fscanf( in, "\t\t%d%d%d\t#%*[a-zA-Z \t0-9]", &x, &y, &rad ) == EOF )
					{
						printf( "Error on reading fields of %s\n", str );
						stop( in, out );
						return 1;
					}

					if( fwrite( &x, sizeof(int), 1, out ) != 1 )
					{
						printf( "error on writing x for %s\n", str );
						stop( in, out );
						return 1;
					}

					if( fwrite( &y, sizeof(int), 1, out ) != 1 )
					{
						printf( "error on writing y for %s\n", str );
						stop( in, out );
						return 1;
					}
					
					if( fwrite( &rad, sizeof(int), 1, out ) != 1 )
					{
						printf( "error on writing rad for %s\n", str );
						stop( in, out );
						return 1;
					}
				}

				continue;
			}

			if( !strcmp( str, "SOUND" ) )
			{
				float freq;
				int dur;

				if( fscanf( in, "\t\t%f%d\t#%*[a-zA-Z \t0-9]", &freq, &dur ) != 2 )
				{
					printf( "Error on reading fields of %s\n", str );
					stop( in, out );
					return 1;
				}

				if( freq > 20000 || freq < 0 )
				{
					printf( "Sound Wrong file structure: %d type is not defined\n", tmp_int );
					stop( in, out );
					return 1;
				}

				if( dur < 0 )
				{
					printf( "Wrong file structure: duration cannot be negative\n" );
					stop (in, out );
					return 1;
				}

				if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing %s\n", str );
					stop( in, out );
					return 1;
				}
				
				if( fwrite( &freq, 4, 1, out ) != 1 )
				{
					printf( "Error on writing type of %s\n", str );
					stop( in, out );
					return 1;
				}
				
				if( fwrite( &dur, sizeof(int), 1, out ) != 1 )
				{
					printf( "Error on writing dur of %s\n", str );
					stop( in, out );
					return 1;
				}
				
				continue;
			}

			if( !strcmp( str, "FRAME" ) )
			{
				if( fwrite( str, 1, strlen( str ), out ) != strlen( str ) )
				{
					printf( "Error on writing %s\n", str );
					stop( in, out );
					return 1;
				}

				continue;
			}

			printf( "Wrong file structure %d: Field type %s\n", j,  str );
			stop( in, out );
			return 1;
		}
	}

	printf( "Work done!\n" );

	stop( in, out );
	return 1;
}	
