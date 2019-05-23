#pragma once
#include "Bullet.h"
class PinkBullet : public Bullet
{
public:
	PinkBullet(Vec2 pos, float rot);
	~PinkBullet();

	void update();

};