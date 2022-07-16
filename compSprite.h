#pragma once

#include"ecsManager.h"
#include "SDL.h"
#include "TextureManager.h"



class compSprite : public Component
{
private:
	compTransform *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

public:

	compSprite() = default;

	compSprite(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	~compSprite()
	{
		SDL_DestroyTexture(texture);
	}

	void init() override
	{
		transform = &Entity->getComponent<compTransform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
	}

	void update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};