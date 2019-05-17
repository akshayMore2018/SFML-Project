#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Vec2 pos, float rot);
	~Bullet();
	void update();
};