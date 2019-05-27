#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
class State;
class Screen
{
public:
	Screen();
	virtual ~Screen();

	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual void update() = 0;
	virtual void render(RenderWindow* window) = 0;
	virtual void MouseButtonPressed(const Vector2f& mouseViewPosition);
	virtual void MouseButtonReleased(const Vector2f& mouseViewPosition);
	virtual void KeyPressed(const Keyboard::Key& code);
	virtual void KeyReleased(const Keyboard::Key& code);
	
protected:
	std::string name;
	State* currentState;
};