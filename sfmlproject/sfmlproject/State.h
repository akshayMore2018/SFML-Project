#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
using namespace sf;
class State
{
public:
	State();
	virtual ~State();

	virtual void update()=0;
	virtual void render(RenderWindow * m_Window)=0;
	virtual void events(const Event& m_Event)=0;
};