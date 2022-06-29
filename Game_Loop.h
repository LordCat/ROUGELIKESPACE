
#ifndef Game_Loop_h
#define Game_Loop_h

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game_Loop
{
public:
	Game_Loop();
	~Game_Loop();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int count = 0;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif /* Game_Loop_h*/