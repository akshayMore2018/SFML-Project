#pragma once
#include "State.h"
#include "Button.h"
class MenuState : public State
{
public:
	MenuState(RenderWindow* m_Window);
	~MenuState();

	void update();
	void render();
	
	void onExit();

private:
	void handleInputs();
	Text text;
	Button* button;
}; 