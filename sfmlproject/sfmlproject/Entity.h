#pragma once
#include "SFML/Graphics.hpp"
#include "Vec2.h"
#include "TextureManager.h"
#include "Animation.h"
using namespace sf;
const static int SCREEN_WIDTH = 915;
const static int SCREEN_HEIGHT = 720;
class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update();
	virtual void events(const Event& event);
	void clear();

	Sprite sprite;
	Texture *texture;
	Vec2 position;
	Vec2 size;
	float acceleration;
	float speed;
	float rotation;
	bool remove;
	float radius;
	Animation animation;
};