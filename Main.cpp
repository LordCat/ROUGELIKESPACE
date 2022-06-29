#include "Game_Loop.h"

Game_Loop* game = nullptr;

int main(int argc,char *argv[]) 
{
	//variables related to FPS limiting
	const int FPS = 59;
	const int frameDelay = 1000 / FPS;
	
	Uint32 frameStart;
	int frameTime;

	//Create Game_Loop Object
	game = new Game_Loop();
	// Initialize game loop window
	game->init("RougeEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	//Game Loop
	while (game->running())
	{
		//Managing Frame rate to 60FPS by checking SDL ticks from window initialization and using SDL_Delay to force game loop to keep a constant 60FPS ## I will need to understand this better.
		frameStart = SDL_GetTicks();

		//Get user inputs, Upate game states and the render to screen ##Gonna be spending alot of time updating these. 
		//TODO: Investigate game loop logic, rendering bitmaps, taking user input, displaying sprites, colission, essentially the whole game
		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();
	return 0;
}