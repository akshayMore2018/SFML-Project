#include "State.h"

State::State()
{
	this->exit = false;
}

State::~State()
{
}

void State::updateMousePosition()
{
	this->mouseScreenPosition = Mouse::getPosition();
	this->mouseWindowPosition = Mouse::getPosition(*this->m_Window);
	this->mouseViewPosition = this->m_Window->mapPixelToCoords(Mouse::getPosition(*this->m_Window));
}


void State::setExit(const bool& flag)
{
	this->exit = flag;
}


