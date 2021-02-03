#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Scene.h"

int SetBGCLR( FILE* file, scene_struct* scene );

int SetColor( FILE* file, scene_struct* scene );

int DrawShape( FILE* file, scene_struct* scene );

int DrawPoint( FILE* file, scene_struct* scene );

int DrawLine( FILE* file, scene_struct* scene );

int DrawQuad( FILE* file, scene_struct* scene );

int DrawTriangle( FILE* file, scene_struct* scene );

int DrawCircle( FILE* file, scene_struct* scene );

int DrawWQuad( FILE* file, scene_struct* scene );

int DrawWCircle( FILE* file, scene_struct* scene );

int DrawWTriangle( FILE* file, scene_struct* scene );

int SwapBuffer( FILE* file, scene_struct* scene );

#endif
