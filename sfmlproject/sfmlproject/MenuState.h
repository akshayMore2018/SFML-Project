#pragma once
#include "State.h"
#include "Button.h"
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
	Text text;
	Button* button;
}; 