#pragma once

#include "Game_Loop.h"
#include "ecsManager.h"
#include "Component.h"

class ecsController : public Component
{
public:
	compTransform* transform;

	void init() override
	{
		transform = &Entity->getComponent<compTransform>();
	}

	void update() override
	{
		if (Game_Loop::event.type == SDL_KEYDOWN)
		{ 
			switch(Game_Loop::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			default:
				break;
			}
		}

		if (Game_Loop::event.type == SDL_KEYUP)
		{
			switch (Game_Loop::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			default:
				break;
			}
		}

	}
};