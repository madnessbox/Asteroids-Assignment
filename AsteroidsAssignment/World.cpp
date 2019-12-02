#include "World.h"
#include "Engine.h"
#include "Vector.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Entity.h"
#include <math.h>
#include <vector>

void World::Update()
{
	for (int i = 0; i < entities.size(); ++i)
	{
		entities[i]->Update();
	}
}

void World::Draw()
{
	for (int i = 0; i < entities.size(); ++i)
	{
		entities[i]->Draw();
	}
}

void World::SpawnEntity(Entity* entity)
{
	unsigned int index = entities.size();
	
	entities.push_back(entity);
	entities[index]->index = index;
	entity = entities[index];
}

void World::DestroyEntity(Entity* entity)
{
	entities.erase(entities.begin() + entity->index);
	delete entity;
	entity = nullptr;
}
