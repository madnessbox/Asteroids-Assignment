#include "Asteroid.h"
#include "Engine.h"
#include "Vector.h"
#include <math.h>
#include <cstdlib>
#include <ctime>

void Asteroid::Spawn()
{
	SetRandomPosition();
	SetRandomVelocity();
	SetRandomShape();
}

void Asteroid::SetRandomPosition()
{
	int randX = rand() % engGetWidth();
	int randY = rand() % engGetHeight();

	position = { (float)randX , (float)randY };
}

void Asteroid::SetRandomVelocity()
{
	Vector2 newVelocityDir;
	newVelocityDir.x = 1.f;

	float s = sin(rand() % 20);
	float c = cos(rand() % 20);

	float newX = newVelocityDir.x * c - newVelocityDir.y * s;
	float newY = newVelocityDir.x * s + newVelocityDir.y * c;

	newVelocityDir.x = newX;
	newVelocityDir.y = newY;

	velocity = Normalize(newVelocityDir) * speed;
}

void Asteroid::SetRandomShape()
{
	float shapePointsSpread = (2.f * PI) / shapeResloution;
	
	for (int i = 0; i < shapeResloution; i++)
	{
		// Rotate point at random distance from center, around center by shapePointSpread angle
		// + 20 to avoid small numbers
		float randomDistance = (rand() % maxSize) + 20;

		Vector2 pointToRotate;
		pointToRotate.x = randomDistance;
		pointToRotate.y = 0.f;

		float s = sin(shapePointsSpread * i);
		float c = cos(shapePointsSpread * i);

		float newX = pointToRotate.x * c - pointToRotate.y * s;
		float newY = pointToRotate.x * s + pointToRotate.y * c;

		drawPoints[i].x = newX;
		drawPoints[i].y = newY;
	}
}

void Asteroid::Update()
{
	position += velocity;
}

void Asteroid::Draw()
{
	engSetColor(0, 255, 0);

	for (int i = 1; i < shapeResloution; i++)
	{
		engDrawLine( position.x + drawPoints[i - 1].x, position.y + drawPoints[i - 1].y, position.x + drawPoints[i].x, position.y + drawPoints[i].y);	
	}
	engDrawLine(position.x + drawPoints[0].x, position.y + drawPoints[0].y, position.x + drawPoints[shapeResloution - 1].x, position.y + drawPoints[shapeResloution - 1].y);

	engSetColor(0, 0, 0);
}