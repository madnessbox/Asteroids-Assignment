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
		if (bullets[i].destroyed == false)
		{
			bullets[i].Update();
		}
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
		if (bullets[i].destroyed == false)
		{
			bullets[i].Draw();
		}
	}
}

void World::SpawnPlayer(World& worldptr)
{
	player.Spawn(worldSize / 2, worldptr);
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

void World::SpawnBullet(Vector2 position, Vector2 direction)
{
	if (NUM_BULLETS < MAX_NUM_BULLETS)
	{
		for (int i = 0; i < MAX_NUM_BULLETS; i++)
		{
			if (bullets[i].destroyed)
			{
				bullets[i].destroyed = false;
				bullets[i].index = i;
				bullets[i].Spawn(position, direction);
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
	if (NUM_ASTEROIDS <= 0)
		return;

	for (int i = 0; i < NUM_ASTEROIDS; i++)
	{
		asteroids[i].CheckIfCollide(player.position);
	}

	if (NUM_BULLETS <= 0)
		return;

	for (int i = 0; i < NUM_ASTEROIDS; i++)
	{
		for (int j = 0; j < NUM_BULLETS; j++)
		{
			asteroids[i].CheckIfCollide(bullets[i].position);
		}
	}

}
