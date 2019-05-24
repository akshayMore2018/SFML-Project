#include "State.h"

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


