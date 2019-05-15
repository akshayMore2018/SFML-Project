#include "Bullet.h"

Bullet::Bullet(Vec2 pos, float rot)
{
	sprite.setTexture(TextureManager::getInstance()->textureMap["bullet"]);
	sprite.setOrigin(TextureManager::getInstance()->textureMap["bullet"].getSize().x/2, TextureManager::getInstance()->textureMap["bullet"].getSize().y/2);
	position.x = pos.x;
	position.y = pos.y;
	velocity = 9.0f;
	rotation = rot;
	
}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	position.x = position.x + cos((rotation)*0.017453f) * velocity;
	position.y = position.y + sin((rotation)*0.017453f) * velocity;

	sprite.setPosition(position.x, position.y);
	sprite.setRotation(rotation-90);
}
