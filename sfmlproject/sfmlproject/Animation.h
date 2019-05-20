#pragma once
#include "SFML/Graphics.hpp"
#include "Vec2.h"
using namespace sf;
class Animation
{
public:
	Animation();
	Animation(Sprite& sprite, float x, float y, float frameWidth, float frameHeight, float framecount,float animspeed , int animCycle);

	void update();
	
	bool isAnimComplete();
private:
	float x;
	float y;
	float frameWidth;
	float frameHeight;
	float frameCount;
	float animSpeed;
	float frames;
	bool animComplete;
	int animCycle;
public:
	Sprite* sprite;
};

inline bool Animation::isAnimComplete()
{
	return animComplete;
}