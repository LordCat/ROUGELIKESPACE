#define SDL_MAIN_HANDLED

#include "Game_Loop.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Map.h"
#include "vector2D.h"

#include "ecsManager.h"



//instantiate A single render
SDL_Renderer* Game_Loop::renderer = nullptr;



Map* map;

Manager manager;
auto& player(manager.addEntity());
auto& enemy(manager.addEntity());

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

	
	map = new Map();

	player.addComponent<compTransform>(0, 0);
	player.addComponent<compSprite>("assets/DrP.png");

	enemy.addComponent<compTransform>(50, 50);
	enemy.addComponent<compSprite>("assets/BennyG.png");


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
	//Keep tra of frames
	manager.refresh();
	manager.update();
	player.getComponent<compTransform>().position.Add(vector2D(0, 5));
	enemy.getComponent<compTransform>().position.Add(vector2D(5, 5));

	
}

void Game_Loop::render()
{
	SDL_RenderClear(renderer);

	//render map
	map->DrawMap();

	manager.draw();

	SDL_RenderPresent(renderer);
}

void Game_Loop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Data Cleared." << std::endl;
}
