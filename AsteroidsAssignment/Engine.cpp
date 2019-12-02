#include "Engine.h"
#include "Keys.h"
#include <SDL.h>
#undef main
#include <SDL_image.h>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unordered_map>
#include <array>

SDL_Renderer* renderer;
SDL_Window* window;

const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 720;


std::unordered_map<int, SDL_Scancode> keyMap = 
{
	{KeyPress::Up, SDL_SCANCODE_UP},
	{KeyPress::Down, SDL_SCANCODE_DOWN},
	{KeyPress::Right, SDL_SCANCODE_RIGHT},
	{KeyPress::Left, SDL_SCANCODE_LEFT},
	{KeyPress::Space, SDL_SCANCODE_SPACE},
};

std::array<bool, KeyPress::Size> keyPressed;

void engInit()
{
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if (!renderer)
		std::cout << SDL_Error << std::endl;
}

void engClose()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void engRender()
{
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

void engSetColor(unsigned char red, unsigned char green, unsigned char blue)
{
	SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
}

void engDrawRect(int width, int height, int x, int y)
{
	SDL_Rect rect;
	rect.h = height;
	rect.w = width;
	rect.x = x;
	rect.y = y;
	
	SDL_RenderFillRect(renderer, &rect);
}

void engDrawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

int engGetHeight()
{
	return WINDOW_HEIGHT;
}

int engGetWidth()
{
	return WINDOW_WIDTH;
}

void engInputUpdate(const uint8_t* const state)
{
	for (int i = 0; i < KeyPress::Size; ++i)
	{
		keyPressed[i] = state[keyMap[i]];
	}
}

bool engGetKey(KeyPress::Type key)
{
	return keyPressed[key];
}
