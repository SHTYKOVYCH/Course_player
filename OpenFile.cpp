#include <stdio.h>
#include <string.h>

#include "Check.h"
#include "OpenFile.h"
#include "Errors.h"

int OpenFile(int argc, char** argv, FILE** mouvie)
{
	//�������� 256 ���� ��� ��� � � ��� ���������� �����
	//����� ����� � �����-����� �������� �������
	char filename[256];

	//���� ��� �������� � ���������� ������, �� ���������
	//��� �� ��� ����� � �����������. ����� ��������
	if (argc > 1)
	{
		strcpy(filename, argv[1]);
	}
	else
	{
		printf("Welcome to simple media player!\nPlease, enter the name of file with your mouvie: ");
		scanf("%s", filename);
	}

	//�������� ������� ����
	*mouvie = fopen(filename, "rb");

	//���� �� ���������, ���������� ������
	//�������� �����
	if (*mouvie == NULL)
	{
		return OPEN_ERROR;
	}

	//��������� "�������" �����
	//��� ������ �������������� ������ "FILM"
	int error = Check(*mouvie, "FILM");

	//���� ��������� ������, �� ����������� �� ���
	if (error)
	{
		fclose(*mouvie);
		return error;
	}

	return NO_ERRORS;
}
