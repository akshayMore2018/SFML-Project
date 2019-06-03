#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
#include <stack>
class Game;
class Screen;
using namespace sf;
const float SCREEN_W =915;
const float SCREEN_H=720;

class State
{
public:
	State();
	virtual ~State();
	virtual void update()=0;
	virtual void render()=0;
	
	virtual void MouseButtonPressed(const Vector2f& mouseViewPosition) = 0;
	virtual void MouseButtonReleased(const Vector2f& mouseViewPosition) = 0;
	virtual void KeyPressed(const Keyboard::Key& code) = 0;
	virtual void KeyReleased(const Keyboard::Key& code) = 0;

	virtual void onExit(const std::string& nextStateID)=0;
	void setScreen(Screen* screen);
	Sprite bg;
	std::string stateName;
	Screen * currentrScreen;
	Game* game;

protected:
	RenderWindow* m_Window= nullptr;
	Event* m_Event = nullptr;
	
};

