#pragma once
#include "Entity.h"
class Bullet;
class Player : public Entity
{
public:
	Player();
	 ~Player();
	void update();
	void render(RenderWindow* window);
	void rotate(float angle);
	void thrust(float acceleration);
	float angle;
	Animation explosionAnim;
	void takeDamage(int damage);
	Bullet* playerWeapon();
private:
	Sprite explosion;
	Sound hurtSound;
};