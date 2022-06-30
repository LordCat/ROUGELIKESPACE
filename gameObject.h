#pragma once
#include "Game_Loop.h"


class gameObject
{
public:
	gameObject(const char* texturesheet, SDL_Renderer* ren);
	~gameObject();

	void Update();
	void Render();

private:

	int xpos, ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};