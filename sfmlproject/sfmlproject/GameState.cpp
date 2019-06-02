#include "GameState.h"
#include "Player.h"
#include "Asteroid.h"
#include "BlueBullet.h"
#include "RedBullet.h"
#include "PinkBullet.h"
#include "PauseScreen.h"
#include "GameOverScreen.h"
#include "Game.h"
#include "HUD.h"
#include "AudioManager.h"
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
		TextureManager::getInstance()->loadTexture("window", "Assets/gui/pauseScreen/Window.png");
		TextureManager::getInstance()->loadTexture("pauseHeader", "Assets/gui/pauseScreen/Header.png");
		TextureManager::getInstance()->loadTexture("playButton", "Assets/gui/pauseScreen/play.png");
		TextureManager::getInstance()->loadTexture("playButtonSelected", "Assets/gui/pauseScreen/play2.png");
		TextureManager::getInstance()->loadTexture("closeButton", "Assets/gui/pauseScreen/close.png");
		TextureManager::getInstance()->loadTexture("closeButtonSelected", "Assets/gui/pauseScreen/close2.png");
		TextureManager::getInstance()->loadTexture("restartButton", "Assets/gui/pauseScreen/restart.png");
		TextureManager::getInstance()->loadTexture("restartButtonSelected", "Assets/gui/pauseScreen/restart2.png");
		TextureManager::getInstance()->loadTexture("scoreImg", "Assets/gui/pauseScreen/score.png");
		TextureManager::getInstance()->loadTexture("clock", "Assets/gui/hud/Clock_Icon.png");
		TextureManager::getInstance()->loadTexture("life", "Assets/gui/hud/life.png");
		TextureManager::getInstance()->loadTexture("hp", "Assets/gui/hud/hpBar.png");
		TextureManager::getInstance()->loadTexture("hpFill", "Assets/gui/hud/Health_Dot.png");
		TextureManager::getInstance()->loadTexture("gameOverHeader", "Assets/gui/gameOverScreen/Header.png");
	}
	else
	{
		std::cout << "Textures already loaded" << std::endl;
	}
	
	if (!AudioManager::getInstance()->soundBuffer.count("pewpew") == 1)
	{
		std::cout << "loading sounds...." << std::endl;
		AudioManager::getInstance()->loadSound("pewpew", "Assets/sounds/pewpew.wav");
		AudioManager::getInstance()->loadSound("blast", "Assets/sounds/blast.wav");
	}
	else
	{
		std::cout << "Sounds already loaded" << std::endl;
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
	gameOver = new GameOverScreen(this);
	hud = new HUD(this);
	
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
	delete gameOver;
	delete hud;
}

void GameState::update()
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->update();
		return;
	}

	hud->update();

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
				player->playPewPewSound();
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
			if (checkCollision(*aitr, *bitr) && !((*aitr)->ignoreCollision))
			{
				(*aitr)->kill();
				(*bitr)->remove = true;
				PlayerProfile::getInstance()->playerScore++;
			}
		}

		if (!player)
			continue;

		if (checkCollision(*aitr, player) && !((*aitr)->ignoreCollision))
		{
			player->takeDamage((*aitr)->damage);	
			hud->updatePlayerHP();
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
			if ((*i)->remove)
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
			if (PlayerProfile::getInstance()->playerLives > 0)
			{
				PlayerProfile::getInstance()->playerLives--;
				player->currentHP = player->maxHP;
				PlayerProfile::getInstance()->playerHP=player->currentHP;
				player->position.x = SCREEN_W / 2;
				player->position.y = SCREEN_H / 2;
				player->remove = false;
				player->explosionAnim.reset();
				hud->updatePlayerHP();
				hud->updatePlayerLives();
			}
			else
			{
				delete player;
				player = nullptr;
				this->setScreen(this->gameOver);
			}
			
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
	
	hud->render(m_Window);
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
		hud->pauseTimer();
	}
}

void GameState::setGameOverScreen()
{
	this->setScreen(this->gameOver);
}
