#include "Game.h"
#include "Player.h"

Game::Game(const std::string name, unsigned int height, unsigned int width)
{	
	m_Window.create(VideoMode(width, height), name);
	m_Window.setFramerateLimit(60);

	TextureManager::getInstance()->load("bg","Assets/space.jpg");
	TextureManager::getInstance()->load("ship","Assets/player.png");
	TextureManager::getInstance()->load("bullet", "Assets/laserGreen.png");
	bg.setTexture(TextureManager::getInstance()->textureMap["bg"]);
	player = new Player();
}

Game::~Game()
{
	clear();
}


void Game::update()
{
	if (bullet)
		bullet->update();
	player->update();
}

void Game::render()
{

	m_Window.clear(Color(0, 0, 0, 255));
	m_Window.draw(bg);
	if (bullet)
		m_Window.draw(bullet->sprite);
	m_Window.draw(player->sprite);

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
			break;
		default:
			if (Keyboard::isKeyPressed(Keyboard::LAlt))
			{
				bullet = new Bullet(player->position,player->rotation);
			}
			player->events(m_Event);
			break;
		}
	}
}

void Game::clear()
{
	delete player;
}

