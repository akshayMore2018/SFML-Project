#include "GameState.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"


GameState::GameState()
{
	TextureManager::getInstance()->load("bg", "Assets/space.jpg");
	TextureManager::getInstance()->load("ship", "Assets/player.png");
	TextureManager::getInstance()->load("bullet", "Assets/laserGreen.png");
	TextureManager::getInstance()->load("explosion", "Assets/type_A.png");
	TextureManager::getInstance()->load("asteroid", "Assets/rock.png");
	bg.setTexture(TextureManager::getInstance()->textureMap["bg"]);
	player = new Player();

	float N = 5;
	while (N--)
	{
		asteroidList.push_back(new Asteroid(rand() % 400, rand() % 400));
	}
}

GameState::~GameState()
{
	std::cout << "Gamestate destructor" << std::endl;
	delete player;
	for (auto i = asteroidList.begin(); i != asteroidList.end();i++)
	{
		delete (*i);
	}
	asteroidList.clear();

	for (auto j = bulletList.begin(); j != bulletList.end(); j++)
	{
		delete (*j);
	}
	bulletList.clear();

}

void GameState::update()
{
	//checking collision before entitiy's update as explosion sprite texture was being rendered before setting the texture rect. 
	for (auto aitr = asteroidList.begin(); aitr != asteroidList.end(); aitr++)
	{
		for (auto bitr = bulletList.begin(); bitr != bulletList.end(); bitr++)
		{
			if (checkCollision(*aitr, *bitr) && !((*aitr)->remove))
			{
				(*aitr)->remove = true;
				(*bitr)->remove = true;
			}
		}
	}


	if (bulletList.size() != 0)
	{
		for (auto i = bulletList.begin(); i != bulletList.end();)
		{

			(*i)->update();
			if ((*i)->remove)
			{
				std::cout << bulletList.size() << std::endl;
				delete (*i);
				i = bulletList.erase(i);
			}
			else
			{
				i++;
			}

		}
	}

	if (asteroidList.size() != 0)
	{
		for (auto i = asteroidList.begin(); i != asteroidList.end();)
		{
			(*i)->update();
			if ((*i)->remove && (*i)->explosionAnim.isAnimComplete())
			{
				delete (*i);
				i = asteroidList.erase(i);
				std::cout << " asteroids left :" << asteroidList.size() << std::endl;
			}
			else
			{
				i++;
			}
		}
	}
	player->update();
}



void GameState::render(RenderWindow * m_Window)
{
	m_Window->draw(bg);
	if (bulletList.size() != 0)
	{
		for (auto i = bulletList.begin(); i != bulletList.end(); i++)
		{
			if (!((*i)->remove))
				m_Window->draw((*i)->sprite);
		}
	}

	if (asteroidList.size() != 0)
	{
		for (auto i = asteroidList.begin(); i != asteroidList.end(); i++)
		{
			if (!((*i)->remove)) {
				m_Window->draw((*i)->sprite);
			}
			else
			{
				m_Window->draw(*((*i)->explosionAnim.sprite));
			}

		}
	}

	m_Window->draw(player->sprite);
}

bool GameState::checkCollision(Entity * a, Entity * b)
{
	return (b->position.x - a->position.x)*(b->position.x - a->position.x) +
		(b->position.y - a->position.y)*(b->position.y - a->position.y) <
		(b->radius + a->radius)*(b->radius + a->radius);;
}

void GameState::events(const Event& m_Event)
{
	switch (m_Event.type)
	{
		case Event::KeyReleased:
		if (m_Event.key.code == Keyboard::LAlt)
			bulletList.push_back(new Bullet(player->position, player->rotation));
	default:
		player->events(m_Event);
		break;
	}
	
}