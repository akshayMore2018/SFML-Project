#pragma once
#include "State.h"
class Entity;
class Bullet;
class Asteroid;
class Player;
class GameState :public State
{
public:
	GameState(RenderWindow* m_Window);
	~GameState();

	void update();
	void render();
	bool checkCollision(Entity * a, Entity * b);
	void onExit();
private:
	void handleInputs();
	Player* player = nullptr;
	std::vector<Bullet*> bulletList;
	std::vector<Asteroid*> asteroidList;
	float delay;
};