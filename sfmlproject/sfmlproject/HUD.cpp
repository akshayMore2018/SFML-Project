#include "HUD.h"
#include "TextureManager.h"
#include "Timer.h"
HUD::HUD(RenderWindow * window)
{
	this->m_Window = window;
	this->hpStr.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->hpStr.setPosition(30, 20);
	this->hpStr.setCharacterSize(20);

	this->timeStr.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->timeStr.setPosition(830, 20);
	this->timeStr.setCharacterSize(20);

	TextureManager::getInstance()->textureMap["clock"].setSmooth(true);
	this->clock.setTexture(TextureManager::getInstance()->textureMap["clock"]);
	this->clock.setOrigin(TextureManager::getInstance()->textureMap["clock"].getSize().x/2, TextureManager::getInstance()->textureMap["clock"].getSize().y/2);
	this->clock.setPosition(this->timeStr.getPosition().x-20, this->timeStr.getPosition().y+13);
	this->clock.setScale(0.6, 0.6);
	updatePlayerHP();
	
	duration = 120;
	timer = new Timer(duration);
	timer->activate();
	updateTimer();

	TextureManager::getInstance()->textureMap["life"].setSmooth(true);
	TextureManager::getInstance()->textureMap["life"].setRepeated(true);
	lives.setTexture(TextureManager::getInstance()->textureMap["life"]);
	lives.setPosition(10, 680);
	updatePlayerLives();

}

HUD::~HUD()
{
	delete timer;
}

void HUD::update()
{
	if (timer->update())
	{
		timer->deactivate();
	}
	updateTimer();
}

void HUD::updateTimer()
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
	ss.str("");
	ss << PlayerProfile::getInstance()->playerHP;
	this->hpStr.setString("HP: " + ss.str());
}

void HUD::updatePlayerLives()
{
	lives.setTextureRect(IntRect(0, 0, 43 * PlayerProfile::getInstance()->playerLives, 36));
}

void HUD::render()
{
	this->m_Window->draw(this->hpStr);
	this->m_Window->draw(this->timeStr);
	this->m_Window->draw(this->clock);
	this->m_Window->draw(this->lives);
	
}
