#include "Player.h"
#include <iostream>


Player::Player()
{
	if (!texture.loadFromFile("Assets/player.png"))
	{
		std::cout << "Could not load asset";
	}
	else
	{
		texture.setSmooth(true);
		sprite.setTexture(texture);
		position =  Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		size = Vec2(texture.getSize().x, texture.getSize().y);
		sprite.setOrigin(size.x/2, size.y/2);
		sprite.setPosition(position.x,position.y);
		sprite.setScale(0.6f, 0.6f);
		velocity = 0;
		acceleration = 0;
		rotation = -90;
		angle = 0;
	}

}

Player::~Player()
{
	std::cout << "Player destroyed" << std::endl;
}

void Player::update()
{
	velocity += acceleration;

	if (velocity > 3)
	{
		velocity = 3;
	}
	else if (velocity < 0)
	{
		velocity = 0;
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
	position.x = position.x + cos((rotation)*0.017453f) * velocity;
	position.y = position.y + sin((rotation)*0.017453f) * velocity;

	sprite.setPosition(position.x, position.y);
	sprite.setRotation(rotation+90);
}

void Player::events(const Event& event)
{

	if(event.type==Event::KeyPressed)
	{
		if (event.key.code == Keyboard::Left)
		{
			angle = -3;
		}
		else if (event.key.code == Keyboard::Right)
		{
			angle = 3;
		}

		if (event.key.code == Keyboard::Up)
		{
			acceleration = 0.05f;
		}
		
	}
	else if (event.type==Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
		{
			angle = 0;
		}

		if (event.key.code == Keyboard::Up)
		{
			acceleration = -0.03f;
		}
	}

}
