#pragma once
#include "Engine.h"
#include "Vector.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "Entity.h"
#include <math.h>
#include <vector>

class World
{
public:
	std::vector<Entity> entities;
};
