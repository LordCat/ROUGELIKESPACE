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

	void init() override
	{
		transform = &Entity->getComponent<compTransform>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 64;
		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};