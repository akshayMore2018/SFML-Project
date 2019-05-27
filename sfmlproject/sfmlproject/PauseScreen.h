#pragma once
#include "Screen.h"
class Button;

class PauseScreen : public Screen
{
public:
	PauseScreen(State* state);
	~PauseScreen();
	
	void enter();
	void update();
	void render(RenderWindow* window);
	void MouseButtonPressed(const Vector2f& mouseViewPosition);
	void MouseButtonReleased(const Vector2f& mouseViewPosition);
	void KeyPressed(const Keyboard::Key& code);
	void KeyReleased(const Keyboard::Key& code);
	void exit();

	Sprite panel;
	Sprite header;
	Text text;
	Button* resumeButton;
	Button* closeButton;
	Button* restartButton;
};