#pragma once
#include "Entity.h"
class Quirk :public Entity
{
public:

	enum QUIRK_TYPE
	{
		LIFE,
		HEALTH,
		TIME,
		RED_LASER,
		BLUE_LASER,
		PINK_LASER
	};
	Quirk(QUIRK_TYPE value,float x, float y);
	~Quirk();

	void update();
	void render(RenderWindow* window);
	void kill();
	void onCollision(Entity* obj);

private:
	short unsigned int currentType;
	Animation meteor;
	Vec2 velocity;
};