#pragma once
#include "Entity.h"
class Meteor:public Entity
{
public:
	Meteor(float x, float y);
	~Meteor();

	void update();
	void render(RenderWindow* window);
	void kill();
	void onCollision(Entity* obj);
	void takeDamage(int damage);

private:
	Vec2 velocity;
	Sprite explosion;
public:
	Animation explosionAnim;

};