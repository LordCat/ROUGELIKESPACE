/*
Map object that has two functions.
LoadMap takes an integer array of 20 by 25 //todo: make this more abstract so I can load diffrent size maps
DrawMap() takes no arguments but loads textures according to the ID in the array, Water = 0, Grass = 1, Dirt = 2, etc //todo, figure out how to do this better

*/

#pragma once

#include "Game_Loop.h"

class Map
{
public: 

	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};