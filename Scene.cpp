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
	//��������� ������� ������ "SCENE" � �����
	int error = Check(mouvie, "SCENE");

	//���� ��������� ������, �� ���������� �� ���
	if (error != NO_ERRORS)
	{
		return error;
	}
	
	//��������� ���-�� ����� �����
	unsigned int scenefields;
	
	error = ReadSceneParams(mouvie, &scenefields);

	//���� ��������� ������, �� ���������� �� ���
	if (error != NO_ERRORS)
	{
		return error;
	}
	
	//�������������� �������
	error = GraphicsInit();
	
	//���� ��������� ������, �� ���������� �� ���
	if (error != NO_ERRORS)
	{
		return error;
	}
	
	//�������� ��������������� �������� ����
	for (unsigned int i = 0; i < scenefields; ++i)
	{
		//���� �� ����� ���������� ���� ������ �������
		//Escape, ��� ������� �� ���, �� ��������� ������
		if( kbhit() )
		{
			if( getch() == 27 )
			{
				break;
			}
		}
		
		//������������ ����
		error = WorkWithField(mouvie);

		//���� ��������� ������, �� ���������� �� ���
		if (error != NO_ERRORS)
		{
			break;
		}
	}

	//���������������� �������
	GraphicsDeinit();
	
	return error;
}

int WorkWithField( FILE* file )
{
	//��������� ����
	char check[6];
	check[5] = 0;

	if( fread( check, 1, 5, file ) != 5 )
	{
		return READ_ERROR;
	}

	//�������� ���������� ��� � �����������
	if( !strcmp( check, "BGCLR" ) )//���� ����
	{
		int error = SetBGCLR(file);

		return error;
	}

	if( !strcmp( check, "COLOR" ) )//���� ���������
	{
		int error = SetColor(file);

		return error;
	}

	if( !strcmp( check, "SOUND" ) )//����� �����
	{
		int error = PlaySound( file );
		return error;
	}

	if( !strcmp( check, "SHAPE" ) )//����� ������
	{
		int error = DrawShape( file );

		return error;
	}

	if( !strcmp( check, "FRAME" ) )//������� ������
	{
		int error = ClearScreen();

		return error;
	}

	//���� ��������� �� ������������ �� ������ ����
	//������� ������ ��������� �����
	return STRUCT_ERROR;
}

int PlaySound(FILE* file)//������������ ����
{
	//��������� ������� �����
	float freq;

	if (fread(&freq, 4, 1, file) != 1)
	{
		return READ_ERROR;
	}

	//� � float ������ ��������, ��������� �� ���������������
	if (freq < 0)
	{
		return STRUCT_ERROR;
	}

	//��������� �����������������
	unsigned int dur;

	if (fread(&dur, 4, 1, file) != 1)
	{
		return READ_ERROR;
	}

	//������� ����
	int error = !Beep(freq, dur);

	//���� ��� ������ ��������� ������
	//�� ���������� ��� ������ �����
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
	//�������������� ������� � ������������ �����������
	int dm=DETECT, ds;
	
	initgraph( &dm, &ds, "" );
	
	//��������� ����������
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
	
	//��������� ������� ������ "SCENEFIELDS"
	error = Check(file, "SCENEFIELDS");

	if (error != NO_ERRORS)
	{
		return error;
	}

	//��������� ���-�� ����� �����
	if (fread(num, 4, 1, file) != 1)
	{
		return READ_ERROR;
	}

	return NO_ERRORS;
}

