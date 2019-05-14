#pragma once
#include "Entity.h"


class Player : public Entity
{
public:
	Player();
	 ~Player();
	void update();
	void events(const Event& event);

	float angle;
};