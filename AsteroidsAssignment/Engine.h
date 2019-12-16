#pragma once
#include "Keys.h"
#include "SDL.h"
#include "Vector.h"

const float PI = 3.14f;

void engInit();
void engClose();
void engRender();

void engSetColor(unsigned char red, unsigned char green, unsigned char blue);

void engDrawRect(int width, int height, int x, int y);
void engDrawLine(int x1, int y1, int x2, int y2);
void engDrawLine(Vector2 pos1, Vector2 pos2);

int engGetHeight();
int engGetWidth();

// Input
void engInputUpdate(const uint8_t* const state);
bool engGetKey(KeyPress::Type key);
