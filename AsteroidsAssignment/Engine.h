#pragma once
#include "Keys.h"
#include "SDL.h"

const float PI = 3.14f;

void engInit();
void engClose();
void engRender();

void engSetColor(unsigned char red, unsigned char green, unsigned char blue);

void engDrawRect(int width, int height, int x, int y);
void engDrawLine(int x1, int y1, int x2, int y2);

int engGetHeight();
int engGetWidth();

// Input
void engInputUpdate(const SDL_Event& event);
bool engGetKey(Keys key);