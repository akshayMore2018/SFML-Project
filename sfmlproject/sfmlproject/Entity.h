#pragma once
#include "SFML/Graphics.hpp"
#include "Vec2.h"
using namespace sf;
const static int SCREEN_WIDTH = 640;
const static int SCREEN_HEIGHT = 480;
class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update();
	void events();
	void clear();

	Sprite sprite;
	Texture texture;
	Vec2 *position;
	Vec2 *velocity;

};