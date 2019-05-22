#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState();
	~MenuState();

	void update();
	void render(RenderWindow * m_Window);
	void handleInputs();
	void onExit();

private:
	Font font;
	Text text;
};