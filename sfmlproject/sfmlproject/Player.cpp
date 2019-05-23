#include "Player.h"
#include <iostream>


Player::Player()
{
	texture = &(TextureManager::getInstance()->textureMap["ship"]);
	texture->setSmooth(true);
	sprite.setTexture(*texture);
	position =  Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	size = Vec2(texture->getSize().x, texture->getSize().y);
	sprite.setOrigin(size.x/2, size.y/2);
	sprite.setPosition(position.x,position.y);
	sprite.setScale(0.6f, 0.6f);
	speed = 0;
	acceleration = 0;
	rotation = -90;
	angle = 0;
	
}

Player::~Player()
{
	std::cout << "Player destructor" << std::endl;
}

void Player::update()
{
	speed += acceleration;

	if (speed > 4)
	{
		speed = 4;
	}
	else if (speed < 0)
	{
		speed = 0;
	}

	if (sprite.getPosition().x > SCREEN_WIDTH + 15)
	{
		position.x = -15;
	}
	else if(sprite.getPosition().x<-15)
	{
		position.x = SCREEN_WIDTH + 15;
	}
	if (sprite.getPosition().y>SCREEN_HEIGHT+15)
	{
		position.y = -15;
	}
	else if (sprite.getPosition().y<-15)
	{
		position.y = SCREEN_HEIGHT + 15;
	}
	rotation += angle;
	position.x = position.x + cos((rotation)*0.017453f) * speed;
	position.y = position.y + sin((rotation)*0.017453f) * speed;

	sprite.setPosition(position.x, position.y);
	sprite.setRotation(rotation+90);
}

void Player::render(RenderWindow * window)
{
	window->draw(this->sprite);
}


void Player::thrust(float acceleration)
{
	this->acceleration = acceleration;
}

void Player::rotate(float angle)
{
	this->angle = angle;
}

