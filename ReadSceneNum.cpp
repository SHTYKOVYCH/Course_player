#include <string.h>
#include <stdio.h>

#include "ReadSceneNum.h"
#include "OpenFile.h"
#include "Check.h"
#include "Errors.h"

int ReadSceneNum(FILE* file, unsigned char* num)
{
	//Проверяем наличие "SCENENUM" в файле
	int error = Check(file, "SCENENUM");

	//Еси не найдено, то возвращаем ошибку структуры файла
	if (error)
	{
		return error;
	}

	//Считываем беззнаковое однобайтное число, ко-во сцен
	if (fread(num, 1, 1, file) != 1)
	{
		return READ_ERROR;
	}

	return NO_ERRORS;
}

