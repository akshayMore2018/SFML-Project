#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Bullet.h";
#include "Asteroid.h"
#include <stack>
class State;
using namespace sf;

class Game
{

public:
	Game(const std::string name, unsigned int height, unsigned int width);
	~Game();

	bool isRunning();
	void update();
	void render();
	void event();
	Vector2i mouseScreenPosition;
	Vector2i mouseWindowPosition;
	Vector2f mouseViewPosition;
private:
	RenderWindow m_Window;
	Event m_Event;
	std::stack<State*>states;
};

inline bool Game::isRunning()
{
	return m_Window.isOpen();
}
