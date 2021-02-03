#include <stdio.h>

#include "DecodeError.h"
#include "Errors.h"

void DecodeError( int error )
{
	//Выводим заголовок
	printf( "Error: " );
	switch( error )
	{
		case( NO_ERRORS )://Если ошибок не произошло
						  //то начинаем вывод с начала строки
						  //затирая заголовок
			printf( "\rMultimedia played\n" );
			break;
		case( OPEN_ERROR )://Ошибка открытия файла
			printf( "couldn't open file\n" );
			break;
		case( READ_ERROR )://Ошибка чтения
			printf( "couldn't read from file\n" );
			break;
		case( STRUCT_ERROR )://Ошибка структуры входного файла
			printf( "wrong file structure\n" );
			break;
		case( INIT_ERROR )://Ошибка инициализации графики
			printf( "can't initiate graphics\n" );
			break;
		case( GRAPH_ERROR )://Ошибка при выводе графики
			printf( "graphics error\n" );
			break;
		case( SOUND_ERROR )://Ошибка при выводе звука
			printf( "sound error\n" );
			break;
	}
	//Справочное сообщение
	printf( "Press enter to close programm\n");
}

