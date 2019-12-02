#include <SDL.h>
#undef main
#include <SDL_image.h>
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

#include "Engine.h"
#include "Vector.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"

Ship player;

int numAsteroids = 5;
Asteroid asteroids[5];

std::vector<Bullet> bulletVector;

const Uint8* state = SDL_GetKeyboardState(NULL);

int main()
{
	srand(time(nullptr));
	
	engInit();
	SDL_Event event;

	player.Spawn({ 540, 360 });

	for (int i = 0; i < numAsteroids; i++)
	{
		asteroids[i].Spawn();
	}
	
	bool quit = false;
	while (!quit)
	{
		engRender();
		engInputUpdate(state);
		
		
		player.CheckInput();
		
		player.Draw();

		for (int i = 0; i < numAsteroids; i++)
		{
			asteroids[i].Update();
			asteroids[i].Draw();
		}

		for (int i = 0; i < bulletVector.size(); i++)
		{
			bulletVector[i].Update();
			bulletVector[i].Draw();
		}
		
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = true;

			if (event.key.keysym.sym == SDLK_ESCAPE)
				quit = true;
		}

		SDL_Delay(.5f);
	}

	engClose();

	return 0;
}