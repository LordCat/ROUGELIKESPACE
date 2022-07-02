#pragma once
#include "Game_Loop.h"


class gameObject
{
public:

	gameObject(const char* texturesheet, int x, int y);

	~gameObject();

	void Update();
	void Render();

private:

	int xpos, ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

};