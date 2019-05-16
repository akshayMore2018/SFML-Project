#include "Game.h"
#include "Player.h"

float frames = 0;
float animSpeed = 0.5f;

Game::Game(const std::string name, unsigned int height, unsigned int width)
{	
	m_Window.create(VideoMode(width, height), name);
	m_Window.setFramerateLimit(60);

	TextureManager::getInstance()->load("bg","Assets/space.jpg");
	TextureManager::getInstance()->load("ship","Assets/player.png");
	TextureManager::getInstance()->load("bullet", "Assets/laserGreen.png");
	TextureManager::getInstance()->load("explosion", "Assets/type_A.png");
	bg.setTexture(TextureManager::getInstance()->textureMap["bg"]);
	player = new Player();

	explosion.setTexture(TextureManager::getInstance()->textureMap["explosion"]);

	explosion.setPosition(300, 300);
	explosion.setScale(2, 2);
	animation = Animation(explosion, 50, 0, 50, 50, 20, 0.4f);

}

Game::~Game()
{
	clear();
}


void Game::update()
{
	if (bulletList.size() != 0)
	{
		for (auto i = bulletList.begin(); i != bulletList.end();)
		{

			(*i)->update();
			if ((*i)->remove)
			{
				std::cout << bulletList.size() << std::endl;
				delete (*i);
				i=bulletList.erase(i);
			}
			else
			{
				i++;
			}

		}
	}

	animation.update();
	player->update();
}

void Game::render()
{

	m_Window.clear(Color(0, 0, 0, 255));
	m_Window.draw(bg);
	if (bulletList.size() != 0)
	{
		for (auto i = bulletList.begin(); i != bulletList.end(); i++)
		{
			if(!((*i)->remove))
			m_Window.draw((*i)->sprite);
		}
	}
	m_Window.draw(player->sprite);
	m_Window.draw(explosion);
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
		case Event::KeyReleased:
			if(m_Event.key.code==Keyboard::LAlt)
			bulletList.push_back(new Bullet(player->position, player->rotation));
		default:
			player->events(m_Event);
			break;
		}
	}
}

void Game::clear()
{
	delete player;
}

