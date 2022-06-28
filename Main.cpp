#include "Game_Loop.h"

Game_Loop* game = nullptr;

int main(int argc, const char *argv[]) 
{

	game = new Game_Loop();

	game->init("RougeEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}