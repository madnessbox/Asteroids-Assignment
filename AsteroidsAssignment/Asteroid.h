#pragma once
#include "Vector.h"
#include "Entity.h"

class Asteroid
{
public:
	void Spawn();
	void SetRandomPosition();
	void SetRandomVelocity();
	void SetRandomShape();
	void Update();
	void Draw();

	Vector2 position;
	Vector2 velocity;
	float speed = 0.01f;
	
	const int shapeResloution = 5;
	int maxSize = 50;
	Vector2 drawPoints[5];

	short tag;
	int index;
	bool destroyed = true;
};