#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
using namespace sf;
class Screen
{
public:
	Screen();
	virtual ~Screen();

	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual void update() = 0;
	virtual void render(RenderWindow* window) = 0;
	
protected:
	std::string name;
};