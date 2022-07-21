#define SDL_MAIN_HANDLED

#include "Game_Loop.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Map.h"
#include "vector2D.h"

#include "ecsManager.h"
#include "ecsController.h"
#include "Collision.h"


//instantiate A single render and pass it by reference ?
SDL_Renderer* Game_Loop::renderer = nullptr;
SDL_Event Game_Loop::event;



Map* map;

Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());
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

	player.addComponent<compTransform>(2);
	player.addComponent<compSprite>("assets/DrP.png");
	player.addComponent<ecsController>();
	player.addComponent<compCollider>("player");

	wall.addComponent<compTransform>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<compSprite>("assets/water.png");
	wall.addComponent<compCollider>("wall");

	enemy.addComponent<compTransform>(50, 50);
	enemy.addComponent<compSprite>("assets/BennyG.png");

}

void Game_Loop::handleEvents()
{

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

	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<compCollider>().collider,
		wall.getComponent<compCollider>().collider))
	{
		std::cout << "wall hit" << std::endl;
	}
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
