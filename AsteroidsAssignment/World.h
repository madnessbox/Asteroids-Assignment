#pragma once
#include "Entity.h"
#include <vector>

class World
{
public:
	std::vector<Entity*> entities;

	void Update();
	void Draw();
	
	void SpawnEntity(Entity* entity);
	void DestroyEntity(Entity* entity);
};
