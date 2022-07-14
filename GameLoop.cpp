#define SDL_MAIN_HANDLED

#include "Game_Loop.h"
#include "TextureManager.h"
#include "SDL.h"
#include "gameObject.h"
#include "Map.h"

#include "ecsManager.h"
#include "compPosition.h"


//instantiate A single render
SDL_Renderer* Game_Loop::renderer = nullptr;


gameObject* player;
gameObject* enemy;
Map* map;

Manager manager;
auto& newPlayer(manager.addEntity());

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

	player = new gameObject("assets//DrP.png", 0, 0);
	enemy = new gameObject("assets//BennyG.png", 50, 50);
	map = new Map();

	newPlayer.addComponent<compPosition>();
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
	player->Update();
	enemy->Update();
	manager.update();

	//map->DrawMap();
	//std::cout << count << std::endl;
	std::cout << newPlayer.getComponent<compPosition>().x() << "," <<
		newPlayer.getComponent<compPosition>().y() << std::endl;
}

void Game_Loop::render()
{
	SDL_RenderClear(renderer);

	//render map
	map->DrawMap();
	// Add Stuff to render
	//Render Dr. PlaceHolder
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game_Loop::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Data Cleared." << std::endl;
}
