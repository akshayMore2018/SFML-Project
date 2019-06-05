#pragma once
#include "State.h"
class Entity;
class Bullet;
class Asteroid;
class Player;
class Game;
class HUD;
class LevelManager;
class GameState :public State
{
public:
	GameState(RenderWindow* m_Window, Game* game);
	~GameState();

	void update();
	void render();
	bool checkCollision(Entity * a, Entity * b);
	void onExit(const std::string& nextStateID);
	void MouseButtonPressed(const Vector2f& mouseViewPosition);
	void MouseButtonReleased(const Vector2f& mouseViewPosition);
	void KeyPressed(const Keyboard::Key& code);
	void KeyReleased(const Keyboard::Key& code);
	void setGameOverScreen();
	void spawnCollectibles(short unsigned int value, float x, float y);

private:
	Player* player = nullptr;
	std::vector<Bullet*> bulletList;
	std::vector<Asteroid*> asteroidList;
	std::vector<Entity*> EntityList;
	float delay;
	Screen* pauseScreen;
	Screen* gameOver;
	HUD* hud;
	LevelManager* levelManager;
};