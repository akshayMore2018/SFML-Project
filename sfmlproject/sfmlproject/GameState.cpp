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
#include "Quirk.h"
#include "Meteor.h"
#include "LevelManager.h"
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
		//TextureManager::getInstance()->loadTexture("bulletQuirk", "Assets/quirks/orbs.png");
		TextureManager::getInstance()->loadTexture("meteor", "Assets/meteor.png");
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
		AudioManager::getInstance()->loadSound("ouch", "Assets/sounds/ouch.wav");
		AudioManager::getInstance()->loadMusic("bg", "Assets/music/erased.wav");
	}
	else
	{
		std::cout << "Sounds already loaded" << std::endl;
	}

	bg.setTexture(TextureManager::getInstance()->textureMap["bg"]);

	player = new Player();
	delay = 0;
	
	levelManager = new LevelManager(&(this->EntityList));
	levelManager->setLevel(PlayerProfile::getInstance()->currentLevel++);
	
	pauseScreen = new PauseScreen(this);
	gameOver = new GameOverScreen(this);
	hud = new HUD(this);
	
	if (AudioManager::getInstance()->MusicMap["bg"].getStatus() != Music::Playing)
	{
		AudioManager::getInstance()->MusicMap["bg"].stop();
		AudioManager::getInstance()->MusicMap["bg"].setVolume(25);
		AudioManager::getInstance()->MusicMap["bg"].play();
	}
	
}

GameState::~GameState()
{
	std::cout << "Gamestate destructor" << std::endl;
	if(player)
	delete player;
	delete levelManager;
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

	levelManager->update();
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

				bulletList.push_back(player->playerWeapon());
				delay = 10;
			}
			delay--;
		}
	}
	

	//checking collision before entitiy's update as explosion sprite texture was being rendered before setting the texture rect. 
	for (auto eitr = EntityList.begin(); eitr != EntityList.end(); eitr++)
	{
		for (auto bitr = bulletList.begin(); bitr != bulletList.end(); bitr++)
		{
			if (checkCollision(*eitr, *bitr) && !((*eitr)->ignoreCollision))
			{
				(*eitr)->onCollision(*bitr);
			}
		}

		if (!player)
			continue;

		if (checkCollision(*eitr, player) && !((*eitr)->ignoreCollision))
		{
			hud->updatePlayerHP();
			(*eitr)->onCollision(player);
			(player)->onCollision(*eitr);
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

	if (EntityList.size() != 0)
	{
		for (auto i = EntityList.begin(); i != EntityList.end();)
		{
			(*i)->update();
			if ((*i)->remove)
			{
				/*if ((*i)->name == "Asteroid")
					spawnCollectibles(Quirk::PINK_LASER,(*i)->position.x, (*i)->position.y);*/
				delete (*i);
				i = EntityList.erase(i);
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
				PlayerProfile::getInstance()->playerState = PlayerProfile::DIED;
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

	if (EntityList.size() != 0)
	{
		for (auto i = EntityList.begin(); i != EntityList.end(); i++)
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
		(b->radius + a->radius)*(b->radius + a->radius);
}



void GameState::onExit(const std::string& nextStateID)
{
	if (AudioManager::getInstance()->MusicMap["bg"].getStatus() == Music::Playing)
	{
		if (nextStateID == "MenuState")
		{
			AudioManager::getInstance()->MusicMap["bg"].stop();
		}
		
	}
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

void GameState::spawnCollectibles(short unsigned int  value, float x, float y)
{
	switch (value)
	{
	case Quirk::BLUE_LASER:
		EntityList.push_back(new Quirk(Quirk::BLUE_LASER, x, y));
		break;
	case Quirk::RED_LASER:
		EntityList.push_back(new Quirk(Quirk::RED_LASER, x, y));
		break;
	case Quirk::PINK_LASER:
		EntityList.push_back(new Quirk(Quirk::PINK_LASER, x, y));
		break;
	case Quirk::LIFE:
		EntityList.push_back(new Quirk(Quirk::LIFE, x, y));
		break;
	default:
		break;
	}
}
