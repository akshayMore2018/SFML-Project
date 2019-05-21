#include "Game.h"
#include "GameState.h"

Game::Game(const std::string name, unsigned int height, unsigned int width)
{
	m_Window.create(VideoMode(width, height), name);
	m_Window.setFramerateLimit(60);
	this->states.push(new GameState());
}

Game::~Game()
{
	
}

void Game::update()
{
	if (!this->states.empty())
	{
		this->states.top()->update();



	}
}


void Game::render()
{

	m_Window.clear(Color(0, 0, 0, 255));
	if (!this->states.empty())
	{
		this->states.top()->render(&m_Window);
	}
	m_Window.display();
}

void Game::event()
{
	while (m_Window.pollEvent(m_Event))
	{
		switch (m_Event.type)
		{
		case Event::Closed:
			m_Window.close();
			if (!this->states.empty())
			{
				delete this->states.top();
				this->states.pop();
			}
			break;
		default:
			if (!this->states.empty())
			{
				this->states.top()->events(m_Event);
			}
		}
	}
}


