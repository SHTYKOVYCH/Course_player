#include <stdio.h>
#include <stdlib.h>

#include "OpenFile.h"
#include "DecodeError.h"
#include "ReadSceneNum.h"
#include "Scene.h"

void Posibylity();//Вычисляем и выводим вероятность
				  //отсутствия медиа фильмов

int main(int argc, char** argv)
{
	Posibylity();//Вычисляем и выводим
	
	FILE* mouvie;

	//Открываем файл и проверяем его "подпись"
	int error = OpenFile(argc, argv, &mouvie);

	if (error)
	{
		DecodeError(error);//Декодируем ошибку
		return 1;
	}

	unsigned char sceneNum;

	//Считываем кол-во сцен во входном файле
	error = ReadSceneNum(mouvie, &sceneNum);

	if (error)
	{
		DecodeError(error);
		fclose(mouvie);//Т к программа заканчивает работу
					   //необходимо закрыть файл
		return 1;
	}

	//Выводим все сцены в файле
	for (unsigned char i = 0; i < sceneNum; ++i)
	{
		error = Scene(mouvie);

		if (error)
		{
			break;
		}
	}
	
	//Декодируем ошибку, если ничего не произошло,
	//то функция выведе соответствующее сообщение
	DecodeError(error);
	
	//Т к при вводе имени файла с клавиатуры
	//в буфере повисает один символ '\n'
	//то нужно его откинуть
	if( argc < 2 )
	{
		getchar();
	}
	
	//Останавиваем программу для тех,
	//кто запустил ее не из консоли
	getchar();
	
	fclose(mouvie);
	return 0;
}

void Posibylity()
{
	//Решение вероятносной задачи вы можете найти
	//в отчете по курсовой работе
	printf( "Posibylity of absence of films in file is P(0) = %d\n",
			100 - 84 );
}
