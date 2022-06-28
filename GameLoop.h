
#ifndef GameLoop_h
#define GameLoop_h

#include "SDL.h"
#include <iostream>

class Game_Loop
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void render();
	void clean();
};
