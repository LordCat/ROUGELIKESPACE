#include "gameObject.h"
#include "TextureManager.h"


gameObject::gameObject(const char* texturesheet, SDL_Renderer* ren)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

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
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}