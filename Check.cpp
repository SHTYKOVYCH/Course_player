#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Check.h"
#include "Errors.h"

int Check( FILE* file, const char* str )
{
	//��������� ���-�� ���� ��� ��������
	int length = strlen(str);
	
	//�������� ������ ��� ������
	//�� ��������� ��� ������, � � �������� VS
	//�� ��������� �������� ������ � ����� � ������� ����������
	char* check = ( char* ) malloc( length + 1 );
	check[length] = 0;//������ ���� ���� ��� ����� ������

	//��������� ���-�� ����, ������� ���������� ���������
	if(fread(check, 1, length, file) != length)
	{
		//���� ��������� ������ ������
		free(check);
		return READ_ERROR;
	}

	//���������� ���������� ������
	if( strcmp( check, str ) )
	{
		//���� ��������� � ���������� ������ �� �������,
		//�� ���������� ������ ��������� �����
		free( check );
		return STRUCT_ERROR;
	}

	//���� ��� ������, �� ���������� ��������� ������
	free( check );
	return NO_ERRORS;
}

