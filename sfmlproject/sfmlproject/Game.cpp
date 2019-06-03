#include "Game.h"
#include "GameState.h"
#include "MenuState.h"

Game::Game(const std::string name, unsigned int height, unsigned int width)
{
	m_Window.create(VideoMode(width, height), name);
	m_Window.setFramerateLimit(60);
	
	this->states.push(new MenuState(&m_Window,this));
}

Game::~Game()
{
	
}

void Game::update()
{
	this->mouseScreenPosition = Mouse::getPosition();
	this->mouseWindowPosition = Mouse::getPosition(m_Window);
	this->mouseViewPosition = m_Window.mapPixelToCoords(Mouse::getPosition(m_Window));

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
		this->states.top()->render();
	}
	m_Window.display();
}

void Game::event()
{
	if (this->states.empty())
		return;

	while (m_Window.pollEvent(m_Event))
	{
		switch (m_Event.type)
		{
		case Event::Closed:
			m_Window.close();
			for (int i = 0; i < states.size(); i++)
			{
				delete this->states.top();
				this->states.pop();
			}
			break;
		case Event::MouseButtonPressed:
			this->states.top()->MouseButtonPressed(mouseViewPosition);
			break;
		case Event::MouseButtonReleased:
			this->states.top()->MouseButtonReleased(mouseViewPosition);
			break;
		case Event::KeyPressed:
			this->states.top()->KeyPressed(m_Event.key.code);
			break;
		case Event::KeyReleased:
			this->states.top()->KeyReleased(m_Event.key.code);
			break;

		}
	}
}

void Game::changeState(const std::string& stateName)
{
	if (!this->states.empty())
	{
		this->states.top()->onExit(stateName);
		delete this->states.top();
		this->states.pop();
	}

	if (stateName == "MenuState")
	{
		this->states.push(new MenuState(&m_Window, this));
	}
	else if (stateName=="GameState")
	{
		this->states.push(new GameState(&m_Window, this));
	}
	else if ("null")
	{
		m_Window.close();
	}
}


