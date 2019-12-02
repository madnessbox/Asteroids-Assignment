#pragma once
#include "Vector.h"
#include "Entity.h"

class Bullet : public Entity
{
public:
	void Spawn(Vector2 position, Vector2 direction);
	void CheckCollisions();
	void Update() override;
	void Draw() override;

	Vector2 position;
	Vector2 velocity;
	float speed = 0.1f;
};