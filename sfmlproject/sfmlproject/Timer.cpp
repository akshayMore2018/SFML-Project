#include "Timer.h"
#include <iostream>
Timer::Timer(float seconds):duration(seconds*1000),start(false)
{

}

Timer::~Timer()
{
}

void Timer::activate()
{
	timer = 0;
	this->start = true;
	//restart the clock as the first value of timer was greater than the duration and because of which immunity flag was set false in the first frame itself.
	clock.restart();
}

bool Timer::update()
{
	if (this->start)
	{
		timer = clock.getElapsedTime().asMilliseconds();
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

const int & Timer::getTimeElapsed() const
{
	return this->timer;
}
