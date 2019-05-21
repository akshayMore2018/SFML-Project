#pragma once
#include "State.h"
class Entity;
class Bullet;
class Asteroid;
class GameState :public State
{
public:
	GameState();
	~GameState();

	void update();
	void render(RenderWindow * m_Window);
	bool checkCollision(Entity * a, Entity * b);
	void events(const Event& m_Event);
	void onExit();
private:

	Entity* player = nullptr;
	Sprite bg;
	std::vector<Bullet*> bulletList;
	std::vector<Asteroid*> asteroidList;
};