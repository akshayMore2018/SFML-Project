#include "HUD.h"
#include "TextureManager.h"
#include "Timer.h"
#include "GameState.h"


HUD::HUD(GameState* state)
{
	this->currentState = state;
	this->timeStr.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->timeStr.setPosition(845, 10);
	this->timeStr.setCharacterSize(18);

	TextureManager::getInstance()->textureMap["clock"].setSmooth(true);
	this->clock.setTexture(TextureManager::getInstance()->textureMap["clock"]);
	this->clock.setOrigin(TextureManager::getInstance()->textureMap["clock"].getSize().x/2, TextureManager::getInstance()->textureMap["clock"].getSize().y/2);
	this->clock.setPosition(this->timeStr.getPosition().x-20, this->timeStr.getPosition().y+13);
	this->clock.setScale(0.6, 0.6);
	updatePlayerHP();
	
	duration = 60;
	timer = new Timer(duration);
	timer->activate();

	TextureManager::getInstance()->textureMap["life"].setSmooth(true);
	TextureManager::getInstance()->textureMap["life"].setRepeated(true);
	lives.setTexture(TextureManager::getInstance()->textureMap["life"]);
	lives.setPosition(10, 680);
	updatePlayerLives();

	TextureManager::getInstance()->textureMap["hp"].setSmooth(true);
	hpBar.setTexture(TextureManager::getInstance()->textureMap["hp"]);
	hpBar.setOrigin(hpBar.getTexture()->getSize().x / 2, hpBar.getTexture()->getSize().y / 2);
	hpBar.setScale(0.5f, 0.5f);
	hpBar.setPosition(101,18);
	TextureManager::getInstance()->textureMap["hpFill"].setSmooth(true);
	TextureManager::getInstance()->textureMap["hpFill"].setRepeated(true);
	hpFill.setTexture(TextureManager::getInstance()->textureMap["hpFill"]);
	hpFill.setScale(0.5f, 0.5f);
	hpFill.setPosition(4, 4);
	hpFill.setTextureRect(IntRect(0,0,11*PlayerProfile::getInstance()->playerHP,58));
}

HUD::~HUD()
{
	delete timer;
}

void HUD::update()
{
	if (updateTimer())
	{
		PlayerProfile::getInstance()->playerState = PlayerProfile::LOST;
		this->currentState->setGameOverScreen();
	}
	else if (PlayerProfile::getInstance()->playerScore >= 5)
	{
		PlayerProfile::getInstance()->playerState = PlayerProfile::WON;
		//todo: level clear screen if all asteroids destroyed
		this->currentState->setGameOverScreen();
	}

}

bool HUD::updateTimer()
{
	if (timer->update())
	{
		updateTimeString();
		timer->deactivate();
		return true;
	}
	updateTimeString();
	return false;
}

void HUD::updateTimeString()
{
	ss.str("");
	int time = duration-(timer->getTimeElapsed()/1000);
	int sec = time % 60;
	int min = time / 60;
	if (min >= 10)
	{
		ss << min;
	}
	else
	{
		ss << "0" << min;
	}
	if (sec >= 10)
	{
		ss << ":"<<sec;
	}
	else
	{
		ss << ":0" << sec;
	}
	this->timeStr.setString(ss.str());	
}

void HUD::updatePlayerHP()
{
	hpFill.setTextureRect(IntRect(0, 0, 11 * PlayerProfile::getInstance()->playerHP, 58));
}

void HUD::updatePlayerLives()
{
	lives.setTextureRect(IntRect(0, 0, 43 * PlayerProfile::getInstance()->playerLives, 36));
}

void HUD::pauseTimer()
{
	this->timer->pause();
}

void HUD::render(RenderTarget* target)
{
	target->draw(this->hpBar);
	target->draw(this->hpFill);
	target->draw(this->timeStr);
	target->draw(this->clock);
	target->draw(this->lives);
	
}
