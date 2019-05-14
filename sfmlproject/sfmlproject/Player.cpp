#include "Player.h"
#include <iostream>


Player::Player()
{
	if (!texture.loadFromFile("Assets/casper.png"))
	{
		std::cout << "Could not load asset";
	}
	else
	{
		sprite.setTexture(texture);
		position =  Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		size = Vec2(texture.getSize().x, texture.getSize().y);
		sprite.setOrigin(size.x/2, size.y/2);
		sprite.setPosition(position.x,position.y);
		velocity = 0;
		acceleration = 0;
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

	position.x = position.x + cos((sprite.getRotation()-90)*0.017453f) * velocity;
	position.y = position.y + sin((sprite.getRotation()-90)*0.017453f) * velocity;

	sprite.setPosition(position.x, position.y);
}

void Player::events(const Event& event)
{

	if(event.type==Event::KeyPressed)
	{

		if (event.key.code == Keyboard::Left)
		{
			sprite.setRotation(sprite.getRotation() - 5);
		}

		if (event.key.code == Keyboard::Right)
		{
			sprite.setRotation(sprite.getRotation() + 5);
		}

		if (event.key.code == Keyboard::Up)
		{
			acceleration = 0.05f;
		}
		
	}
	else if (event.type==Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Up)
		{
			acceleration = -0.01f;
		}
	}

}
