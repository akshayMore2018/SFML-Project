#include "BlueBullet.h"

BlueBullet::BlueBullet(Vec2 pos, float rot)
{
	sprite.setTexture(TextureManager::getInstance()->textureMap["blueBullet"]);
	animation = Animation(sprite, 512, 0, 512, 197, 3, 0.4f, -1);
	animation.sprite->setOrigin(512 / 2, 197 / 2);
	animation.sprite->setScale(0.1f, 0.1f);
	position.x = pos.x;
	position.y = pos.y;
	speed = 9.0f;
	rotation = rot;
	remove = false;
	radius = 6;
}

BlueBullet::~BlueBullet()
{
}

void BlueBullet::update()
{
	if (remove)
		return;

	if (position.x > SCREEN_WIDTH || position.x < 0 || position.y>SCREEN_HEIGHT || position.y < 0)
	{
		remove = true;
	}

	position.x = position.x + cos((rotation)*0.017453f) * speed;
	position.y = position.y + sin((rotation)*0.017453f) * speed;

	sprite.setPosition(position.x, position.y);
	sprite.setRotation(rotation - 180);
	animation.update();
}

void BlueBullet::render(RenderWindow * window)
{
	window->draw(this->sprite);
}
