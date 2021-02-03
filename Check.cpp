#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Check.h"
#include "Errors.h"

int Check( FILE* file, const char* str )
{
	//Вычисляем кол-во байт для проверки
	int length = strlen(str);
	
	//Выделяем память под строку
	//Мы вынуждены так делать, т к стандарт VS
	//Не позволяет выделить память в стеке с помощью переменной
	char* check = ( char* ) malloc( length + 1 );
	check[length] = 0;//Задаем нуть байт как конец строки

	//Считываем кол-во байт, которое необходимо проверить
	if(fread(check, 1, length, file) != length)
	{
		//Если произошла ошибка чтения
		free(check);
		return READ_ERROR;
	}

	//Сравниваем полученную строку
	if( strcmp( check, str ) )
	{
		//Если считанная и полученная строка не совпали,
		//то возвращаем ошибку структуры файла
		free( check );
		return STRUCT_ERROR;
	}

	//Если все удачно, то возвращаем отсутсвие ошибок
	free( check );
	return NO_ERRORS;
}

