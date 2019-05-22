#pragma once
#include "Entity.h"


class Player : public Entity
{
public:
	Player();
	 ~Player();
	void update();
	void rotate(float angle);
	void thrust(float acceleration);

	float angle;
};