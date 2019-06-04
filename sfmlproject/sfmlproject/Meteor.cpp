#include "Meteor.h"

Meteor::Meteor(float x, float y)
{
	this->name = "Meteor";
	position = Vec2(x, y);
	TextureManager::getInstance()->textureMap["meteor"].setSmooth(true);
	sprite.setTexture(TextureManager::getInstance()->textureMap["meteor"]);
	animation = Animation(this->sprite, 75, 0, 75, 128, 10, 0.4, -1);
	animation.sprite->setOrigin(75 / 2, 64);
	animation.sprite->setScale(0.6, 0.6);
	sprite.setPosition(this->position.x, this->position.y);
	this->rotation = 0;
	speed = 4.0f;
	remove = false;
	int low  = 0;
	int high = 7;
	float velArray[16] = {5.5, -5, 4.5, -4, 3.5, -3, 2.5, -2, 2, -2.5, 3, -3.5, 4, -4.5, 5, -5.5};
	velocity.x = velArray[(low + (rand() / (RAND_MAX / (high - low))))];
	velocity.y = velArray[(low + (rand() / (RAND_MAX / (high - low))))];
	rotation = atan2(velocity.y, velocity.x) * 180 / 3.14;
	maxHP = 30;
	currentHP = maxHP;
	damage = 10;
}

Meteor::~Meteor()
{
}

void Meteor::update()
{
	position.x = position.x + velocity.x;
	position.y = position.y + velocity.y;
	if (sprite.getPosition().x > SCREEN_WIDTH + sprite.getTextureRect().width / 2)
	{
		position.x = -sprite.getTextureRect().width / 2;
	}
	else if (sprite.getPosition().x < -sprite.getTextureRect().width / 2)
	{
		position.x = SCREEN_WIDTH + sprite.getTextureRect().width / 2;
	}
	if (sprite.getPosition().y > SCREEN_HEIGHT + sprite.getTextureRect().height / 2)
	{
		position.y = -sprite.getTextureRect().height / 2;
	}
	else if (sprite.getPosition().y < -sprite.getTextureRect().height / 2)
	{
		position.y = SCREEN_HEIGHT + sprite.getTextureRect().height / 2;
	}


	sprite.setPosition(position.x, position.y);
	sprite.setRotation(rotation - 90);
	this->animation.update();
}

void Meteor::render(RenderWindow * window)
{
	window->draw(this->sprite);
}

void Meteor::kill()
{
}

void Meteor::onCollision(Entity * obj)
{
}
