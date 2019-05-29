#pragma once
#include "State.h"
class Entity;
class Bullet;
class Asteroid;
class Player;
class Game;
class HUD;
class GameState :public State
{
public:
	GameState(RenderWindow* m_Window, Game* game);
	~GameState();

	void update();
	void render();
	bool checkCollision(Entity * a, Entity * b);
	void onExit();
	void MouseButtonPressed(const Vector2f& mouseViewPosition);
	void MouseButtonReleased(const Vector2f& mouseViewPosition);
	void KeyPressed(const Keyboard::Key& code);
	void KeyReleased(const Keyboard::Key& code);


private:
	Player* player = nullptr;
	std::vector<Bullet*> bulletList;
	std::vector<Asteroid*> asteroidList;
	float delay;
	Screen* pauseScreen;
	HUD* hud;
};