#pragma once
#include "SFML/Graphics.hpp"
#include "Vec2.h"
using namespace sf;
class Animation
{
public:
	Animation();
	Animation(Sprite& sprite, float x, float y, float frameWidth, float frameHeight, float framecount,float animspeed);

	void update();
private:
	float x;
	float y;
	float frameWidth;
	float frameHeight;
	float frameCount;
	float animSpeed;
	float frames;
	Sprite* sprite;
};