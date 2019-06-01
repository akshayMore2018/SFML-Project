#pragma once
#include "SFML/Graphics.hpp"
#include "PlayerProfile.h"
#include <sstream>
class Timer;
class GameState;
class Screen;
using namespace sf;
class HUD
{
public:
	HUD(GameState* state);
	~HUD();
	void update();
	void updatePlayerHP();
	void updatePlayerLives();
	void pauseTimer();
	void render(RenderTarget* target);

private:
	Text timeStr;
	std::stringstream ss;
	Timer* timer;
	int duration;
	Sprite clock;
	Sprite lives;
	Sprite hpBar;
	Sprite hpFill;
	GameState* currentState;
	bool updateTimer();
	void updateTimeString();
};