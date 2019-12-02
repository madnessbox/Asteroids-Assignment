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
bool playerAcceleratePressed = false;
bool playerCWPressed = false;
bool playerCCWPressed = false;

int numAsteroids = 5;
Asteroid asteroids[5];

std::vector<Bullet> bulletVector;

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
		engInputUpdate(event);
		
		/*if (playerCWPressed)
			player.RotateCW();
		else if (playerCCWPressed)
			player.RotateCCW();
		
		if (playerAcceleratePressed)
			player.Accelerate();
		else
			player.Deaccelerate();*/
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
			
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_UP)
					playerAcceleratePressed = true;
				if (event.key.keysym.sym == SDLK_LEFT)
					playerCCWPressed = true;
				if (event.key.keysym.sym == SDLK_RIGHT)
					playerCWPressed = true;
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					Bullet bullet;
					bulletVector.push_back(bullet);
					bullet.Spawn(player.position, player.forward);
				}
			}

			if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_UP)
					playerAcceleratePressed = false;
				if (event.key.keysym.sym == SDLK_LEFT)
					playerCCWPressed = false;
				if (event.key.keysym.sym == SDLK_RIGHT)
					playerCWPressed = false;
			}
		}

		SDL_Delay(.5f);
	}

	engClose();

	return 0;
}