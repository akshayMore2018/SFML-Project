#pragma once
#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet();
	virtual ~Bullet();
	virtual void update()=0;
};