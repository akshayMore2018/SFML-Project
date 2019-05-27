#pragma once
#include "State.h"
#include "Button.h"
class MenuState : public State
{
public:
	MenuState(RenderWindow* m_Window, std::stack<State*>* states);
	~MenuState();

	void update();
	void render();
	
	void onExit();
	void MouseButtonPressed(const Vector2f& mouseViewPosition);
	void MouseButtonReleased(const Vector2f& mouseViewPosition);
	void KeyPressed(const Keyboard::Key& code);
	void KeyReleased(const Keyboard::Key& code);

private:
	Text text;
	Button* startButton;
	Button* exitButton;
}; 