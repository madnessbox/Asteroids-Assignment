#include "World.h"
#include "Engine.h"
#include "Vector.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include <math.h>
#include <vector>

void World::Update()
{
	player.Update();

	for (int i = 0; i < NUM_ASTEROIDS; i++)
	{
		if (asteroids[i].destroyed == false)
		{
			asteroids[i].Update();
		}
	}

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		bullets[i].Update();
	}

	CheckCollisions();
}

void World::Draw()
{
	player.Draw();

	for (int i = 0; i < NUM_ASTEROIDS; i++)
	{
		if (asteroids[i].destroyed == false)
		{
			asteroids[i].Draw();
		}
	}

	for (int i = 0; i < NUM_BULLETS; i++)
	{
		bullets[i].Draw();
	}
}

void World::SpawnPlayer()
{
	player.Spawn(worldSize / 2);
}

void World::SpawnAsteroid()
{
	if (NUM_ASTEROIDS < MAX_NUM_ASTEROIDS)
	{
		for (int i = 0; i < MAX_NUM_ASTEROIDS; i++)
		{
			if (asteroids[i].destroyed)
			{
				asteroids[i].destroyed = false;
				asteroids[i].index = i;
				asteroids[i].Spawn();
				NUM_ASTEROIDS++;
				return;
			}
		}
	}
}

void World::DestroyAsteroid(int index)
{

}

void World::SpawnBullet()
{
	if (NUM_BULLETS < MAX_NUM_BULLETS)
	{
		for (int i = 0; i < MAX_NUM_BULLETS; i++)
		{
			if (bullets[i].destroyed)
			{
				bullets[i].destroyed = false;
				bullets[i].index = i;
				bullets[i].Spawn(player.position, player.forward);
				NUM_BULLETS++;
				return;
			}
		}
	}
}

void World::DestroyBullet(int index)
{

}

void World::CheckCollisions()
{
	// TODO: Check player-asteroid collision
	// TODO: Check bullet-asteroid collision

	for (int i = 0; i < NUM_ASTEROIDS; i++)
	{
		asteroids[i].CheckIfCollide(player.position);
	}

}
