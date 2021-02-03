#include <stdio.h>
#include <graphics.h>

#include "Graphics_funcs.h"
#include "Errors.h"
#include "shapes.h"

int SetBGCLR( FILE* file )//Устанавливаем цвет фона
{
	//Считываем код цвета
	unsigned char color;
	
	if( fread( &color, 1, 1, file ) != 1 )
	{
		return READ_ERROR;
	}
	
	//Проверяем его на коректность
	if( color > 15 )
	{
		return STRUCT_ERROR;
	}
	
	//Устанавливаем цвет
	setbkcolor( color );
	
	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	setfillstyle( 1, color );
	
	error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int SetColor( FILE* file )//Устанавливаем цвет отрисовки
{
	//Считываем код цвета
	unsigned char color;
	
	if( fread( &color, 1, 1, file ) != 1 )
	{
		return READ_ERROR;
	}
	
	//Проверяем его на корректность
	if( color > 15 )
	{
		return STRUCT_ERROR;
	}
	
	//Устанавливаем цвет
	setcolor( color );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	//Устанавливаем цвет заливки для заполеный фигур
	setfillstyle( 1, color );
	
	error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	return NO_ERRORS;
}

int DrawShape( FILE* file )//Рисуем фигуру
{
	//Считываем код фигуры
	unsigned char type;
	
	if( fread( &type, 1, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	int error;
	switch ( type )//Проверяем все возможные случаи
	{
		case( LINE )://Линия
			error = DrawLine( file );
			return error;
		case( QUAD )://Заполненый квадрат
			error = DrawQuad( file );
			return error;
		case( TRIANGLE )://Заполеный треугольник
			error = DrawTriangle( file );
			return error;
		case( CIRCLE )://Круг
			error = DrawCircle( file );
			return error;
		case( WQUAD )://Не заполненый квадрат
			error = DrawWQuad( file );
			return error;
		case( WTRIANGLE )://Не заполненый треугольник
			error = DrawWTriangle( file );
			return error;
		case( WCIRCLE )://Окружность
			error = DrawWCircle( file );
			return error;
		default://Неверный код фигуры
			return STRUCT_ERROR;
	}
}

int DrawLine( FILE* file ) //Рисуем линию
{
	//Считываем координаты
	int points[4];

	for (int i = 0; i < 4; ++i)
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}
	
	//Рисуем линию
	//Рисуем так, т к таким образом мы може передать
	//число и указатель на массив
	//2 аргумента против 4-х
	drawpoly( 2, points );

	//Проверяем успешность вывода
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawQuad( FILE* file )//Рисуем квадрат
{
	//Считываем координаты
	//Координат на одну точку больше чем нужно,
	//ибо drawpoly заполняет фигуру только если
	//отрисовка закончилась там же где и началась
	int points[10];

	for( int i = 0; i < 8; ++i )
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}
	
	//Приравниваем координаты последней точки
	//к координатам первой
	points[8] = points[0];
	points[9] = points[1];
	
	//Отрисовываем квадрат
	fillpoly( 5, points );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawTriangle( FILE* file )//Рисуем заполненый треугольник
{
	//Считываем координаты
	//Координат на одну точку больше чем нужно,
	//ибо drawpoly заполняет фигуру только если
	//отрисовка закончилась там же где и началась
	int points[8];

	for (int i = 0; i < 6; ++i)
	{
		if( fread ( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}

	//Приравниваем координаты последней точки
	//к координатам первой
	points[6] = points[0];
	points[7] = points[1];

	//Отрисовываем треугольник
	fillpoly( 4, points );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawCircle( FILE* file )
{
	//Считываем координаты центра и радиус круга
	unsigned int X, Y, RAD;

	if( fread( &X, 4, 1, file ) != 1)
	{
		return READ_ERROR;
	}

	if( fread( &Y, 4, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	if( fread( &RAD, 4, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	//Отрисовываем круг
	fillellipse( X, Y, RAD, RAD );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawWQuad( FILE* file )
{
	//Считываем координаты
	//Координат на одну точку больше чем нужно,
	//ибо drawpoly заполняет фигуру только если
	//отрисовка закончилась там же где и началась
	int points[10];

	for( int i = 0; i < 8; ++i )
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}
	
	//Приравниваем координаты последней точки
	//к координатам первой
	points[8] = points[0];
	points[9] = points[1];

	//Отрисовываем квадрат
	drawpoly( 5, points );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}

	return NO_ERRORS;
}

int DrawWCircle( FILE* file )
{
	//Считываем координаты центра и радиус окружности
	int X, Y, RAD;

	if( fread( &X, 4, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	if( fread( &Y, 4, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	if( fread( &RAD, 4, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	//Отрисовываем окружность
	circle( X, Y, RAD );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}

	return NO_ERRORS;
}

int DrawWTriangle( FILE* file )
{
	//Считываем координаты
	//Координат на одну точку больше чем нужно,
	//ибо drawpoly заполняет фигуру только если
	//отрисовка закончилась там же где и началась
	int points[8];

	for( int i = 0; i < 6; ++i )
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}

	//Приравниваем координаты последней точки
	//к координатам первой
	points[6] = points[0];
	points[7] = points[1];

	//Отрисовываем треугольник
	drawpoly( 4, points );

	//Проверяем успешность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}

	return NO_ERRORS;
}

int ClearScreen()
{	
	//Очищаем экран
	cleardevice();
	
	//Проверяем успшность
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

