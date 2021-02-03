#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <graphics.h>

#include "Scene.h"
#include "Check.h"
#include "Graphics_Funcs.h"
#include "Errors.h"

int Scene(FILE* mouvie)
{
	//Проверяем наличие строки "SCENE" в файле
	int error = Check(mouvie, "SCENE");

	//Если произошла ошибка, то возвращаем ее код
	if (error != NO_ERRORS)
	{
		return error;
	}
	
	//Считываем кол-во полей сцены
	unsigned int scenefields;
	
	error = ReadSceneParams(mouvie, &scenefields);

	//Если произошла ошибка, то возвращаем ее код
	if (error != NO_ERRORS)
	{
		return error;
	}
	
	//Инициализируем графику
	error = GraphicsInit();
	
	//Если произошла ошибка, то возвращаем ее код
	if (error != NO_ERRORS)
	{
		return error;
	}
	
	//Начинаем последовательно выводить поля
	for (unsigned int i = 0; i < scenefields; ++i)
	{
		//Если во время выполнеиня была нажата клавиша
		//Escape, или получен ее код, то завершаем работу
		if( kbhit() )
		{
			if( getch() == 27 )
			{
				break;
			}
		}
		
		//Обрабатываем поле
		error = WorkWithField(mouvie);

		//Если произошла ошибка, то возвращаем ее код
		if (error != NO_ERRORS)
		{
			break;
		}
	}

	//Деинициализируем графику
	GraphicsDeinit();
	
	return error;
}

int WorkWithField( FILE* file )
{
	//Считываем поле
	char check[6];
	check[5] = 0;

	if( fread( check, 1, 5, file ) != 5 )
	{
		return READ_ERROR;
	}

	//Начинаем сравнивать его с допустимыми
	if( !strcmp( check, "BGCLR" ) )//Цвет фона
	{
		int error = SetBGCLR(file);

		return error;
	}

	if( !strcmp( check, "COLOR" ) )//Цвет отрисовки
	{
		int error = SetColor(file);

		return error;
	}

	if( !strcmp( check, "SOUND" ) )//Вывод звука
	{
		int error = PlaySound( file );
		return error;
	}

	if( !strcmp( check, "SHAPE" ) )//Вывод фигуры
	{
		int error = DrawShape( file );

		return error;
	}

	if( !strcmp( check, "FRAME" ) )//Очистка экрана
	{
		int error = ClearScreen();

		return error;
	}

	//Если считанное не соответсвует ни одному полю
	//Вернуть ошибку структуры файла
	return STRUCT_ERROR;
}

int PlaySound(FILE* file)//Проигрываеем звук
{
	//Считываем частоту звука
	float freq;

	if (fread(&freq, 4, 1, file) != 1)
	{
		return READ_ERROR;
	}

	//Т к float всегда знаковое, проверяем на отрицательность
	if (freq < 0)
	{
		return STRUCT_ERROR;
	}

	//Считываем продолжительность
	unsigned int dur;

	if (fread(&dur, 4, 1, file) != 1)
	{
		return READ_ERROR;
	}

	//Выводим звук
	int error = !Beep(freq, dur);

	//Если при выводе произошла ошибка
	//То возвращаем код ошибки звука
	if(error != 0)
	{
		error = SOUND_ERROR;
	}

	return error;
}

void GraphicsDeinit()
{
	closegraph();
}

int GraphicsInit()
{
	//Инициализируем графику с максимальным разрешением
	int dm=DETECT, ds;
	
	initgraph( &dm, &ds, "" );
	
	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return INIT_ERROR;
	}
	
	return NO_ERRORS;
}

int ReadSceneParams(FILE* file, unsigned int* num)
{
	int error;
	
	//Проверяем наличие строки "SCENEFIELDS"
	error = Check(file, "SCENEFIELDS");

	if (error != NO_ERRORS)
	{
		return error;
	}

	//Считываем кол-во полей сцены
	if (fread(num, 4, 1, file) != 1)
	{
		return READ_ERROR;
	}

	return NO_ERRORS;
}

