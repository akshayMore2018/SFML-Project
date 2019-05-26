#pragma once
#include "Screen.h"

class PauseScreen : public Screen
{
public:
	PauseScreen();
	~PauseScreen();
	
	void enter();
	void update();
	void render(RenderWindow* window);
	void exit();

	Sprite panel;
	Sprite header;
};