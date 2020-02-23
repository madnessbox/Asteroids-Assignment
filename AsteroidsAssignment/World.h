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
	/* TODO 1: 
		Bullets, Asteroids and Ship used to inherit from a class named Entity. 
		I did this so that I could easier use the Draw and Update functions of each entity at once in the World Update and Draw.
		This however led to the classes being more annoying to deal with when I only had 1 array of all the entities in the game.
		When I was doing collision between the different entities I didn't want to check collision between the bullets and the Ship,
		as well as between the asteroids and themselves. 
		To accomplish having different kinds of interactions during collision with different sets of Entities, I had to somehow categorize them.
		I did this by using a flag that each Entity had, which let me see what type of Entity they were. 
		However, since I now had to check the flag of each entity in the Update funcition, the whole purpose of having all the objects inherit
		from Entity was defeated. Since I now still had to make sure what type of Entity they were. 
		This also led to the program being slower since I now had to check their flag with and if-statement in the Update loop, creating a lot of extra checks.
		I realized that using a common class to inherit from, such as Entity, wasn't worth the hazzle when I knew that the game
		would only have 3 different types of Entities.
		So I instead removed all inheritance and made 2 seperate arrays for the bullets and the asteroids (as well as seperated the ship out since I would only
		ever have one ship at a time).
	*/
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
