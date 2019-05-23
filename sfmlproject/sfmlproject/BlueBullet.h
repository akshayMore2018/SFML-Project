#pragma once
#include "Bullet.h"
class BlueBullet : public Bullet
{
public:
	BlueBullet(Vec2 pos, float rot);
	~BlueBullet();

	void update();
	void render(RenderWindow* window);

};