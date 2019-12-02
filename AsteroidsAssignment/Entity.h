#pragma once
#include "Vector.h"

class Entity
{
public:
	Vector2 position;
	unsigned int index;
	short tag;

	virtual void Update(){};
	virtual void Draw(){};
};