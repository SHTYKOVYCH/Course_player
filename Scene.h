#pragma once

#include <stdio.h>

int Scene(FILE* mouvie);

int GraphicsInit();

void GraphicsDeinit();

int ReadSceneParams( FILE* file, unsigned int* num);

int WorkWithField(FILE* file);

int PlaySound(FILE* file);

