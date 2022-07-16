#pragma once
#include "ecsManager.h"
#include "vector2D.h"

class compTransform : public Component
{

public:

	vector2D position;
	vector2D velocity;
	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;



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

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

};