#include <stdio.h>
#include <graphics.h>

#include "Graphics_funcs.h"
#include "Errors.h"
#include "shapes.h"

int SetBGCLR( FILE* file )//������������� ���� ����
{
	//��������� ��� �����
	unsigned char color;
	
	if( fread( &color, 1, 1, file ) != 1 )
	{
		return READ_ERROR;
	}
	
	//��������� ��� �� �����������
	if( color > 15 )
	{
		return STRUCT_ERROR;
	}
	
	//������������� ����
	setbkcolor( color );
	
	//��������� ����������
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

int SetColor( FILE* file )//������������� ���� ���������
{
	//��������� ��� �����
	unsigned char color;
	
	if( fread( &color, 1, 1, file ) != 1 )
	{
		return READ_ERROR;
	}
	
	//��������� ��� �� ������������
	if( color > 15 )
	{
		return STRUCT_ERROR;
	}
	
	//������������� ����
	setcolor( color );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	//������������� ���� ������� ��� ��������� �����
	setfillstyle( 1, color );
	
	error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	return NO_ERRORS;
}

int DrawShape( FILE* file )//������ ������
{
	//��������� ��� ������
	unsigned char type;
	
	if( fread( &type, 1, 1, file ) != 1 )
	{
		return READ_ERROR;
	}

	int error;
	switch ( type )//��������� ��� ��������� ������
	{
		case( LINE )://�����
			error = DrawLine( file );
			return error;
		case( QUAD )://���������� �������
			error = DrawQuad( file );
			return error;
		case( TRIANGLE )://��������� �����������
			error = DrawTriangle( file );
			return error;
		case( CIRCLE )://����
			error = DrawCircle( file );
			return error;
		case( WQUAD )://�� ���������� �������
			error = DrawWQuad( file );
			return error;
		case( WTRIANGLE )://�� ���������� �����������
			error = DrawWTriangle( file );
			return error;
		case( WCIRCLE )://����������
			error = DrawWCircle( file );
			return error;
		default://�������� ��� ������
			return STRUCT_ERROR;
	}
}

int DrawLine( FILE* file ) //������ �����
{
	//��������� ����������
	int points[4];

	for (int i = 0; i < 4; ++i)
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}
	
	//������ �����
	//������ ���, � � ����� ������� �� ���� ��������
	//����� � ��������� �� ������
	//2 ��������� ������ 4-�
	drawpoly( 2, points );

	//��������� ���������� ������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawQuad( FILE* file )//������ �������
{
	//��������� ����������
	//��������� �� ���� ����� ������ ��� �����,
	//��� drawpoly ��������� ������ ������ ����
	//��������� ����������� ��� �� ��� � ��������
	int points[10];

	for( int i = 0; i < 8; ++i )
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}
	
	//������������ ���������� ��������� �����
	//� ����������� ������
	points[8] = points[0];
	points[9] = points[1];
	
	//������������ �������
	fillpoly( 5, points );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawTriangle( FILE* file )//������ ���������� �����������
{
	//��������� ����������
	//��������� �� ���� ����� ������ ��� �����,
	//��� drawpoly ��������� ������ ������ ����
	//��������� ����������� ��� �� ��� � ��������
	int points[8];

	for (int i = 0; i < 6; ++i)
	{
		if( fread ( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}

	//������������ ���������� ��������� �����
	//� ����������� ������
	points[6] = points[0];
	points[7] = points[1];

	//������������ �����������
	fillpoly( 4, points );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawCircle( FILE* file )
{
	//��������� ���������� ������ � ������ �����
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

	//������������ ����
	fillellipse( X, Y, RAD, RAD );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

int DrawWQuad( FILE* file )
{
	//��������� ����������
	//��������� �� ���� ����� ������ ��� �����,
	//��� drawpoly ��������� ������ ������ ����
	//��������� ����������� ��� �� ��� � ��������
	int points[10];

	for( int i = 0; i < 8; ++i )
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}
	
	//������������ ���������� ��������� �����
	//� ����������� ������
	points[8] = points[0];
	points[9] = points[1];

	//������������ �������
	drawpoly( 5, points );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}

	return NO_ERRORS;
}

int DrawWCircle( FILE* file )
{
	//��������� ���������� ������ � ������ ����������
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

	//������������ ����������
	circle( X, Y, RAD );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}

	return NO_ERRORS;
}

int DrawWTriangle( FILE* file )
{
	//��������� ����������
	//��������� �� ���� ����� ������ ��� �����,
	//��� drawpoly ��������� ������ ������ ����
	//��������� ����������� ��� �� ��� � ��������
	int points[8];

	for( int i = 0; i < 6; ++i )
	{
		if( fread( &( points[i] ), 4, 1, file ) != 1 )
		{
			return READ_ERROR;
		}
	}

	//������������ ���������� ��������� �����
	//� ����������� ������
	points[6] = points[0];
	points[7] = points[1];

	//������������ �����������
	drawpoly( 4, points );

	//��������� ����������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}

	return NO_ERRORS;
}

int ClearScreen()
{	
	//������� �����
	cleardevice();
	
	//��������� ���������
	int error = graphresult();
	
	if( error )
	{
		return GRAPH_ERROR;
	}
	
	return NO_ERRORS;
}

