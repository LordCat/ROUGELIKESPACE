/*
* This is supposed to be a component that allows me to apply AABB colission detection??
* God I'm gonna need to remember this later
*/

#pragma once
#include <string>
#include "SDL.h"

#include "ecsManager.h"


class compCollider : public Component
{
public:
//using an SDL_Rect to draw a shape for colission detection?
	SDL_Rect collider;

	std::string tag;

	compTransform* transform;

	void init() override
	{
		if (!Entity->hasComponent<compTransform>())
		{
			Entity->addComponent<compTransform>();
		}
		transform = &Entity->getComponent<compTransform>();

	}

	void update() override
	{
		collider.x = transform->position.x;
		collider.y = transform-> position.y;
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};
