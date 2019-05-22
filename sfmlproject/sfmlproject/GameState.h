#pragma once
#include "State.h"
class Entity;
class Bullet;
class Asteroid;
class Player;
class GameState :public State
{
public:
	GameState();
	~GameState();

	void update();
	void render(RenderWindow * m_Window);
	bool checkCollision(Entity * a, Entity * b);
	void handleInputs();
	void onExit();
private:

	Player* player = nullptr;
	std::vector<Bullet*> bulletList;
	std::vector<Asteroid*> asteroidList;
};