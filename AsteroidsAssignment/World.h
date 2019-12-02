#pragma once
#include "Entity.h"
#include <vector>

class World
{
public:
	std::vector<Entity*> entities;
	unsigned int NUM_ENTITIES = 0;

	void Update();
	void Draw();
	
	void SpawnEntity(Entity* entity);
	void DestroyEntity(Entity* entity);
};
