#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerProfile.h"
#include <sstream>
class Timer;
using namespace sf;
class HUD
{
public:
	HUD(RenderWindow* window);
	~HUD();

	void update();
	void updateTimer();
	void updatePlayerHP();
	void updatePlayerLives();
	void render();

private:
	RenderWindow* m_Window;
	Text hpStr;
	Text timeStr;
	std::stringstream ss;
	Timer* timer;
	int duration;
	Sprite clock;
	Sprite lives;
};