#pragma once
#include "ecsManager.h"

class compPosition : public Component
{
private: 
	int xpos;
	int ypos;

public:
	compPosition()
	{
		xpos = 0;
		ypos = 0;
	}

	compPosition(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	int x() { return xpos; }
	void x(int x) { xpos = x; }

	int y() { return ypos; }
	void y(int y) { ypos = y; }

	
	void update() override
	{
		xpos++;
		ypos++;
	}

	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};