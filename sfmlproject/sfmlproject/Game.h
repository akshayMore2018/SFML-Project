#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Entity.h"
#include "Bullet.h";
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
	void clear();

private:
	RenderWindow m_Window;
	Event m_Event;
	Entity* player = nullptr;
	Sprite bg;
	Bullet* bullet = nullptr;
	std::vector<Bullet*> bulletList;
};

inline bool Game::isRunning()
{
	return m_Window.isOpen();
}