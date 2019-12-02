#pragma once
#include "Vector.h"

class Entity
{
public:
	Vector2 position;
	short tag;

	virtual void Update(){};
	virtual void Draw(){};
};