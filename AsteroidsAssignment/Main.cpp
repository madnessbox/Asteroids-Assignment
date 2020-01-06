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
#include "World.h"


World world;

const Uint8* state = SDL_GetKeyboardState(NULL);

int main()
{
	srand(time(nullptr));
	
	engInit();
	SDL_Event event;

	world.worldSize = {(float)engGetWidth(), (float)engGetHeight()};
	world.SpawnPlayer(world);
	world.SpawnAsteroid();
	world.SpawnAsteroid();
	world.SpawnAsteroid();
	world.SpawnAsteroid();
	
	
	bool quit = false;
	while (!quit)
	{
		engRender();
		engInputUpdate(state);
			
		world.Update();
		world.Draw();
		
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