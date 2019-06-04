#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Vec2.h"
#include "TextureManager.h"
#include "Animation.h"
class Timer;
using namespace sf;
const static int SCREEN_WIDTH = 915;
const static int SCREEN_HEIGHT = 720;
class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update()=0;
	virtual void render(RenderWindow* window)=0;
	virtual void takeDamage(int damage);
	virtual void kill();
	virtual void onCollision(Entity* obj);

	Sprite sprite;
	Texture *texture;
	Vec2 position;
	Vec2 size;
	float acceleration;
	float speed;
	float rotation;
	float radius;
	Animation animation;
	bool remove;
	int damage;
	int maxHP;
	int currentHP;
	bool immune;
	bool ignoreCollision;
	std::string name;
protected:
	Timer* timer;
	Sound sound;
	
	
};