#pragma once
#include "Screen.h"
class Button;
class GameOverScreen : public Screen
{
public:
	GameOverScreen(State * state);
	~GameOverScreen();


	void enter();
	void update();
	void render(RenderWindow* window);
	void MouseButtonPressed(const Vector2f& mouseViewPosition);
	void MouseButtonReleased(const Vector2f& mouseViewPosition);
	void KeyPressed(const Keyboard::Key& code);
	void KeyReleased(const Keyboard::Key& code);
	void exit();

	Button* closeButton;
	Button* restartButton;
	Sprite panel;
	Text text;
};