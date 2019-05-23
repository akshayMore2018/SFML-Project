#pragma once
#include "Bullet.h"
class RedBullet : public Bullet
{
public:
	RedBullet(Vec2 pos, float rot);
	~RedBullet();

	void update();
	void render(RenderWindow* window);
};