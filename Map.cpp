/* 
This initilises the integer array that will get passed into Map::LoadMap(int[x, y]);
Then the constructer has each texture loaded via TextureManager::LoadTexture(filename)
which then calls Map::LoadMap(int[x,y]) and variables for pixalsize of SDL_Rect x,y. looping trough the arrays rows and colums
and assign a texture depending on the id in the array. 

// This can certainly be made better but it's just a basic implementation
I don't think it scales well when I have lots of textures to load.

The destructor obviously destorys the loaded textures when the Map object is destoryed.

*/

#include "Map.h"
#include "TextureManager.h"


int level1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,2,0,0,2,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,2,0,0,2,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,2,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,2,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,2,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,2,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,2,0,0,0},
	{0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0},
	{0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

};


Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/earth.png");
	grass = TextureManager::LoadTexture("assets/grass.png");
	water = TextureManager::LoadTexture("assets/water.png");

	LoadMap(level1);

	src.x = 0;
	src.y = 0;
	src.w = dest.w = 32;
	src.h = dest.h = 32;

	dest.x = 0;
	dest.y = 0;
}

Map::~Map()
{
	SDL_DestroyTexture(grass);
	SDL_DestroyTexture(water);
	SDL_DestroyTexture(dirt);
}


void  Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			map[row][column] = arr[row][column];

			
		}
	}
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 25; column++)
		{
			type = map[row][column];

			dest.x = column * 32;
			dest.y = row * 32;


			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			default:
				break;
			}
		}
	}
}