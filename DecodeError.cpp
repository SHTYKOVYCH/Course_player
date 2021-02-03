#include <stdio.h>

#include "DecodeError.h"
#include "Errors.h"

void DecodeError( int error )
{
	//������� ���������
	printf( "Error: " );
	switch( error )
	{
		case( NO_ERRORS )://���� ������ �� ���������
						  //�� �������� ����� � ������ ������
						  //������� ���������
			printf( "\rMultimedia played\n" );
			break;
		case( OPEN_ERROR )://������ �������� �����
			printf( "couldn't open file\n" );
			break;
		case( READ_ERROR )://������ ������
			printf( "couldn't read from file\n" );
			break;
		case( STRUCT_ERROR )://������ ��������� �������� �����
			printf( "wrong file structure\n" );
			break;
		case( INIT_ERROR )://������ ������������� �������
			printf( "can't initiate graphics\n" );
			break;
		case( GRAPH_ERROR )://������ ��� ������ �������
			printf( "graphics error\n" );
			break;
		case( SOUND_ERROR )://������ ��� ������ �����
			printf( "sound error\n" );
			break;
	}
	//���������� ���������
	printf( "Press enter to close programm\n");
}

