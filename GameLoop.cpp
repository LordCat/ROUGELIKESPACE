#define SDL_MAIN_HANDLED

#include "Game_Loop.h"
#include "TextureManager.h"
#include "SDL.h"

SDL_Texture* playerTex;
SDL_Rect scrR, destR;

Game_Loop::Game_Loop()
{}

Game_Loop::~Game_Loop()
{}


void Game_Loop::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised... " << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	playerTex = TextureManager::LoadTexture("DrPlaceHolder.png", renderer);
}

void Game_Loop::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Game_Loop::update()
{
	//Keep track of frames
	count++;
	//update texture positon
	destR.h = 64;
	destR.w = 64;
	destR.x = count;
	//output total frames since initialization
	std::cout << count << std::endl;
}

void Game_Loop::render()
{
	SDL_RenderClear(renderer);
	// Add Stuff to render
	//Render Dr. PlaceHolder
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game_Loop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Data Cleared." << std::endl;
}
