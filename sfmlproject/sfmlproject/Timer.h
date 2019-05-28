#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Timer
{
public:
	Timer(float seconds);
	~Timer();
	void activate();
	bool update();
	void deactivate();
private:
	Clock clock;
	float duration;
	bool start;
};