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
	entities.push_back(entity);
	entities[NUM_ENTITIES]->index = NUM_ENTITIES;
	entity = entities[NUM_ENTITIES];
	NUM_ENTITIES += 1;
}

void World::DestroyEntity(Entity* entity)
{
	entities.erase(entities.begin() + entity->index);
	entities[entity->index] = nullptr;
	delete entity;
	NUM_ENTITIES -= 1;
}
