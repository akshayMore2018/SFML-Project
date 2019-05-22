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
	virtual void handleInputs()=0;
	inline const bool& canExit()const;
	virtual void onExit()=0;
	void setExit(const bool& flag);
	Sprite bg;
private:
	bool exit;
	
};

const bool & State::canExit() const
{
	return this->exit;
}