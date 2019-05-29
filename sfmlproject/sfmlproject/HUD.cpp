#include "HUD.h"
#include "TextureManager.h"

HUD::HUD(RenderWindow * window)
{
	this->m_Window = window;
	this->lifeStr.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->lifeStr.setPosition(30, 680);
	this->lifeStr.setCharacterSize(20);
	
	this->hpStr.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->hpStr.setPosition(30, 20);
	this->hpStr.setCharacterSize(20);

	this->scoreStr.setFont(TextureManager::getInstance()->fontMap["title"]);
	this->scoreStr.setPosition(770, 20);
	this->scoreStr.setCharacterSize(20);



	updateScore();
	updatePlayerHP();
	updatePlayerLives();
}

HUD::~HUD()
{
}

void HUD::update()
{
	
}

void HUD::updateScore()
{
	ss.str("");
	ss << PlayerProfile::getInstance()->playerScore;
	this->scoreStr.setString("Score: " + ss.str());
}

void HUD::updatePlayerHP()
{
	ss.str("");
	ss << PlayerProfile::getInstance()->playerHP;
	this->hpStr.setString("HP: " + ss.str());
}

void HUD::updatePlayerLives()
{
	ss.str("");
	ss << PlayerProfile::getInstance()->playerLives;
	this->lifeStr.setString("Lives: " + ss.str());
}

void HUD::render()
{
	this->m_Window->draw(this->lifeStr);
	this->m_Window->draw(this->hpStr);
	this->m_Window->draw(this->scoreStr);
}
