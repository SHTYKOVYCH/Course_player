#pragma once

#include <stdio.h>

#include "Scene.h"

int SetBGCLR(FILE* file);

int SetColor(FILE* file);

int DrawShape(FILE* file);

int DrawPoint(FILE* file);

int DrawLine(FILE* file);

int DrawQuad(FILE* file);

int DrawTriangle(FILE* file);

int DrawCircle(FILE* file);

int DrawWQuad(FILE* file);

int DrawWCircle(FILE* file);

int DrawWTriangle(FILE* file);

int SwapBuffer(FILE* file);

int ClearScreen();
