#include "Bullet.h"

Bullet::Bullet(Vec2 pos, float rot)
{
	sprite.setTexture(TextureManager::getInstance()->textureMap["bullet"]);
	sprite.setOrigin(TextureManager::getInstance()->textureMap["bullet"].getSize().x/2, TextureManager::getInstance()->textureMap["bullet"].getSize().y/2);
	position.x = pos.x;
	position.y = pos.y;
	speed = 9.0f;
	rotation = rot;
	remove = false;
	radius = 6;
}

Bullet::~Bullet()
{
	std::cout << "Bullet destructor" << std::endl;
}

void Bullet::update()
{
	if (remove)
		return;

	if (position.x > SCREEN_WIDTH || position.x < 0 || position.y>SCREEN_HEIGHT || position.y<0)
	{
		remove = true;
	}

	position.x = position.x + cos((rotation)*0.017453f) * speed;
	position.y = position.y + sin((rotation)*0.017453f) * speed;

	sprite.setPosition(position.x, position.y);
	sprite.setRotation(rotation-90);
}
