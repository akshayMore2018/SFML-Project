#pragma once
#include "Entity.h"
class Asteroid : public Entity
{
public:
	Asteroid(float x, float y);
	~Asteroid();

	void update();
	void render(RenderWindow* window);
private:
	Vec2 velocity;
	Sprite explosion;
public:
	Animation explosionAnim;

};