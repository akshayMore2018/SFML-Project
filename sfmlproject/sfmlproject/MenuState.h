#pragma once
#include "State.h"
#include "Button.h"
class Game;
class MenuState : public State
{
public:
	MenuState(RenderWindow* m_Window, Game* game);
	~MenuState();

	void update();
	void render();
	
	void onExit(const std::string& nextStateID);
	void MouseButtonPressed(const Vector2f& mouseViewPosition);
	void MouseButtonReleased(const Vector2f& mouseViewPosition);
	void KeyPressed(const Keyboard::Key& code);
	void KeyReleased(const Keyboard::Key& code);

private:
	Text text;
	Sprite titlePanel;
	Button* startButton;
	Button* exitButton;
}; 