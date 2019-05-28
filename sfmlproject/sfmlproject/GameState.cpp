#include "GameState.h"
#include "Player.h"
#include "Asteroid.h"
#include "BlueBullet.h"
#include "RedBullet.h"
#include "PinkBullet.h"
#include "PauseScreen.h"
#include "Game.h"
GameState::GameState(RenderWindow* m_Window, Game* game)
{
	this->stateName = "GameState";
	this->m_Window = m_Window;
	this->game = game;
	if (!TextureManager::getInstance()->textureMap.count("bg") == 1)//novice method of checking whether the texture is already loaded. 
	{
		std::cout << "loading textures...." << std::endl;
		TextureManager::getInstance()->loadTexture("bg", "Assets/space.jpg");
		TextureManager::getInstance()->loadTexture("ship", "Assets/player.png");
		TextureManager::getInstance()->loadTexture("blueBullet", "Assets/bullets/blueFlame.png");
		TextureManager::getInstance()->loadTexture("redBullet", "Assets/bullets/redFlame.png");
		TextureManager::getInstance()->loadTexture("pinkBullet", "Assets/bullets/pinkFlame.png");
		TextureManager::getInstance()->loadTexture("explosion", "Assets/type_A.png");
		TextureManager::getInstance()->loadTexture("asteroid", "Assets/rock.png");
		TextureManager::getInstance()->loadTexture("pauseWindow", "Assets/gui/pauseScreen/Window.png");
		TextureManager::getInstance()->loadTexture("pauseHeader", "Assets/gui/pauseScreen/Header.png");
		TextureManager::getInstance()->loadTexture("playButton", "Assets/gui/pauseScreen/play.png");
		TextureManager::getInstance()->loadTexture("playButtonSelected", "Assets/gui/pauseScreen/play2.png");
		TextureManager::getInstance()->loadTexture("closeButton", "Assets/gui/pauseScreen/close.png");
		TextureManager::getInstance()->loadTexture("closeButtonSelected", "Assets/gui/pauseScreen/close2.png");
		TextureManager::getInstance()->loadTexture("restartButton", "Assets/gui/pauseScreen/restart.png");
		TextureManager::getInstance()->loadTexture("restartButtonSelected", "Assets/gui/pauseScreen/restart2.png");

	}
	else
	{
		std::cout << "Textures already loaded" << std::endl;
	}
	
	bg.setTexture(TextureManager::getInstance()->textureMap["bg"]);

	player = new Player();
	float N = 5;
	while (N--)
	{
		asteroidList.push_back(new Asteroid(rand() % 400, rand() % 400));
	}
	delay = 0;

	
	pauseScreen = new PauseScreen(this);
	
}

GameState::~GameState()
{
	std::cout << "Gamestate destructor" << std::endl;
	if(player)
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
	delete pauseScreen;
}

void GameState::update()
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->update();
		return;
	}

	if (player)
	{
		player->rotate(0);
		player->thrust(-0.2f);
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player->rotate(-3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player->rotate(3);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			player->thrust(1);
		}
		if (Keyboard::isKeyPressed(Keyboard::LAlt))
		{
			if (delay == 0)
			{
				bulletList.push_back(new BlueBullet(player->position, player->rotation));
				delay = 10;
			}
			delay--;
		}
	}
	

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

		if (!player)
			continue;

		if (checkCollision(*aitr, player))
		{
			player->takeDamage((*aitr)->damage);	
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
	

	if (player)
	{
		player->update();
		if (player->remove && player->explosionAnim.isAnimComplete())
		{
			delete player;
			player = nullptr;
		}
	}
	
}



void GameState::render()
{
	m_Window->draw(bg);
	if (bulletList.size() != 0)
	{
		for (auto i = bulletList.begin(); i != bulletList.end(); i++)
		{
			(*i)->render(this->m_Window);
		}
	}

	if (asteroidList.size() != 0)
	{
		for (auto i = asteroidList.begin(); i != asteroidList.end(); i++)
		{
				(*i)->render(this->m_Window);
		}
	}

	if (player)
	{
		player->render(this->m_Window);
	}
	

	if (currentrScreen != nullptr)
		currentrScreen->render(this->m_Window);
}

bool GameState::checkCollision(Entity * a, Entity * b)
{
	return (b->position.x - a->position.x)*(b->position.x - a->position.x) +
		(b->position.y - a->position.y)*(b->position.y - a->position.y) <
		(b->radius + a->radius)*(b->radius + a->radius);;
}



void GameState::onExit()
{

}

void GameState::MouseButtonPressed(const Vector2f& mouseViewPosition)
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->MouseButtonPressed(mouseViewPosition);
		return;
	}
}

void GameState::MouseButtonReleased(const Vector2f& mouseViewPosition)
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->MouseButtonReleased(mouseViewPosition);
		return;
	}
}

void GameState::KeyPressed(const Keyboard::Key& code)
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->KeyPressed(code);

		return;
	}
/*
	if (code==Keyboard::Left)
	{
		player->rotate(-3);
	}
	if (code == Keyboard::Right)
	{
		player->rotate(3);
	}
	if (code == Keyboard::Up)
	{
		player->thrust(1);
	}
	if (code == Keyboard::LAlt)
	{
		bulletList.push_back(new BlueBullet(player->position, player->rotation));
	}*/

}

void GameState::KeyReleased(const Keyboard::Key& code)
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->KeyReleased(code);

		return;
	}

	if (code == Keyboard::Escape)
	{
		setScreen(pauseScreen);
	}
}
