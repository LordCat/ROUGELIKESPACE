
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game_Loop::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	std::cout << "Texture Loaded" << std::endl;
	return tex;
}