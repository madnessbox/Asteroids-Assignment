#pragma once
#include "Vector.h"
#include "Entity.h"

class Asteroid : public Entity
{
public:
	void Spawn();
	void SetRandomPosition();
	void SetRandomVelocity();
	void SetRandomShape();
	void Update() override;
	void Draw() override;

	Vector2 position;
	Vector2 velocity;
	float speed = 0.01f;
	
	const int shapeResloution = 5;
	int maxSize = 50;
	Vector2 drawPoints[5];
};