#pragma once
#include "ecsManager.h"
#include "vector2D.h"

class compTransform : public Component
{

public:

	vector2D position;

	compTransform()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	compTransform(float x, float y)
	{
		position.x = x;
		position.y = y;
	}


	void update() override
	{
		
	}

};