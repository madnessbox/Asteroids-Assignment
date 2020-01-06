#pragma once
#include <vector>
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Vector.h"

class World
{
public:
	static const int MAX_NUM_BULLETS = 10;
	static const int MAX_NUM_ASTEROIDS = 10;
	int NUM_BULLETS = 0;
	int NUM_ASTEROIDS = 0;

	Ship player;
	Bullet bullets[MAX_NUM_BULLETS];
	Asteroid asteroids[MAX_NUM_ASTEROIDS];

	Vector2 worldSize;
	
	void Update();
	void Draw();

	void SpawnPlayer(World& worldptr);

	void SpawnAsteroid();
	void DestroyAsteroid(int index);

	void SpawnBullet(Vector2 position, Vector2 direction);
	void DestroyBullet(int index);

	void CheckCollisions();
	
};
