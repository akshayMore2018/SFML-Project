#include "State.h"
#include "Screen.h"
State::State()
{
	this->exit = false;
}

State::~State()
{
}

void State::setExit(const bool& flag)
{
	this->exit = flag;
}

void State::setScreen(Screen * screen)
{
	if (currentrScreen != nullptr)
	{
		currentrScreen->exit();
		currentrScreen = nullptr;
	}
	currentrScreen = screen;
	if(currentrScreen!=nullptr)
	currentrScreen->enter();
}



