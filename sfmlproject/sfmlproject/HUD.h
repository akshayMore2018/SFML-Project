#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerProfile.h"
#include <sstream>
using namespace sf;
class HUD
{
public:
	HUD(RenderWindow* window);
	~HUD();

	void update();
	void updateScore();
	void updatePlayerHP();
	void updatePlayerLives();
	void render();

private:
	RenderWindow* m_Window;
	Text scoreStr;
	Text hpStr;
	std::stringstream ss;
};