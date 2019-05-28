#include "Timer.h"

Timer::Timer(float seconds):duration(seconds*1000),start(false)
{

}

Timer::~Timer()
{
}

void Timer::activate()
{
	this->start = true;
}

bool Timer::update()
{
	if (this->start)
	{
		int timer = clock.getElapsedTime().asMilliseconds();
		if (timer >= this->duration)
		{
			clock.restart();
			return true;
		}		
	}
	return false;
	
}

void Timer::deactivate()
{
	this->start = false;

}
