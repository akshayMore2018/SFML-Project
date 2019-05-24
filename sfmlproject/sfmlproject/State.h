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
	virtual void render()=0;
	
	virtual void MouseButtonPressed(const Vector2f& mouseViewPosition) = 0;
	virtual void MouseButtonReleased(const Vector2f& mouseViewPosition) = 0;
	virtual void KeyPressed(const Keyboard::Key& code) = 0;
	virtual void KeyReleased(const Keyboard::Key& code) = 0;

	inline const bool& canExit()const;
	virtual void onExit()=0;
	void setExit(const bool& flag);
	
	Sprite bg;
	std::string stateName;
private:

	bool exit;
protected:
	RenderWindow* m_Window= nullptr;
	Event* m_Event = nullptr;
};

const bool & State::canExit() const
{
	return this->exit;
}
