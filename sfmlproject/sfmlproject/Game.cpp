#include "Game.h"
#include "Player.h"

Game::Game(const std::string name, unsigned int height, unsigned int width)
{
	
	m_Window.create(VideoMode(width, height), name);
	m_Window.setFramerateLimit(60);
	obj = new Player();
}

Game::~Game()
{
	clear();
}


void Game::update()
{
	obj->update();
}

void Game::render()
{

	m_Window.clear(Color(0, 0, 0, 255));

	m_Window.draw(obj->sprite);

	m_Window.display();
}

void Game::event()
{
	while (m_Window.pollEvent(m_Event))
	{
		if (m_Event.type == Event::Closed)
		{
			m_Window.close();
		}
		else
		{
			obj->events();
		}
	}
}

void Game::clear()
{
	delete obj;
}

