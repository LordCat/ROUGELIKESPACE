#include "gameObject.h"
#include "TextureManager.h"


gameObject::gameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;
}

void gameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 30;
	srcRect.w = 30;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}

void gameObject::Render()
{
	SDL_RenderCopy(Game_Loop::renderer, objTexture, &srcRect, &destRect);
}