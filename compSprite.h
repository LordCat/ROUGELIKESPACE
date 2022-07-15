#pragma once

#include"ecsManager.h"
#include "SDL.h"


class compSprite : public Component
{
private:
	compPosition *position;
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
		position = &Entity->getComponent<compPosition>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = position->x();
		destRect.y = position->y();

	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}
};