#include <stdio.h>
#include <stdlib.h>

#include "OpenFile.h"
#include "DecodeError.h"
#include "ReadSceneNum.h"
#include "Scene.h"

void Posibylity();//��������� � ������� �����������
				  //���������� ����� �������

int main(int argc, char** argv)
{
	Posibylity();//��������� � �������
	
	FILE* mouvie;

	//��������� ���� � ��������� ��� "�������"
	int error = OpenFile(argc, argv, &mouvie);

	if (error)
	{
		DecodeError(error);//���������� ������
		return 1;
	}

	unsigned char sceneNum;

	//��������� ���-�� ���� �� ������� �����
	error = ReadSceneNum(mouvie, &sceneNum);

	if (error)
	{
		DecodeError(error);
		fclose(mouvie);//� � ��������� ����������� ������
					   //���������� ������� ����
		return 1;
	}

	//������� ��� ����� � �����
	for (unsigned char i = 0; i < sceneNum; ++i)
	{
		error = Scene(mouvie);

		if (error)
		{
			break;
		}
	}
	
	//���������� ������, ���� ������ �� ���������,
	//�� ������� ������ ��������������� ���������
	DecodeError(error);
	
	//� � ��� ����� ����� ����� � ����������
	//� ������ �������� ���� ������ '\n'
	//�� ����� ��� ��������
	if( argc < 2 )
	{
		getchar();
	}
	
	//������������ ��������� ��� ���,
	//��� �������� �� �� �� �������
	getchar();
	
	fclose(mouvie);
	return 0;
}

void Posibylity()
{
	//������� ������������ ������ �� ������ �����
	//� ������ �� �������� ������
	printf( "Posibylity of absence of films in file is P(0) = %d\n",
			100 - 84 );
}
