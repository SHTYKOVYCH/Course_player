#include <stdio.h>
#include <string.h>

#include "Check.h"
#include "OpenFile.h"
#include "Errors.h"

int OpenFile(int argc, char** argv, FILE** mouvie)
{
	//Выделяем 256 байт под имя т к это наибольшая длина
	//имени файла в какой-либой файловой системе
	char filename[256];

	//Если имя передали в коммандной строке, то принимаем
	//его за имя файла с мультимедиа. Иначе считваем
	if (argc > 1)
	{
		strcpy(filename, argv[1]);
	}
	else
	{
		printf("Welcome to simple media player!\nPlease, enter the name of file with your mouvie: ");
		scanf("%s", filename);
	}

	//Пытаемся открыть файл
	*mouvie = fopen(filename, "rb");

	//Если не открылось, возвращаем ошибку
	//открытия файла
	if (*mouvie == NULL)
	{
		return OPEN_ERROR;
	}

	//Проверяем "подпись" файла
	//Она болжна соответсвовать строке "FILM"
	int error = Check(*mouvie, "FILM");

	//Если произошла ошибка, то возрвращаем ее код
	if (error)
	{
		fclose(*mouvie);
		return error;
	}

	return NO_ERRORS;
}
