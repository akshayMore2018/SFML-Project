#include "State.h"
#include "Screen.h"
State::State()
{
}

State::~State()
{
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



