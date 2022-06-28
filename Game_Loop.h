
#ifndef Game_Loop_h
#define Game_Loop_h

#include "SDL.h"
#include <iostream>

class Game_Loop
{
public:
	GameLoop();
	~GameLoop();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void update();
	void handleEvents();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif /* GameLoop_h*/