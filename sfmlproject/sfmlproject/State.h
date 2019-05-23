#pragma once
#include "SFML/Graphics.hpp"
#include "TextureManager.h"
using namespace sf;
class State
{
public:
	State();
	virtual ~State();
	virtual void updateMousePosition();
	virtual void update()=0;
	virtual void render()=0;
	virtual void handleInputs()=0;
	inline const bool& canExit()const;
	virtual void onExit()=0;
	void setExit(const bool& flag);
	Sprite bg;
	Vector2i mouseScreenPosition;
	Vector2i mouseWindowPosition;
	Vector2f mouseViewPosition;

private:
	bool exit;
protected:
	RenderWindow* m_Window= nullptr;
};

const bool & State::canExit() const
{
	return this->exit;
}
