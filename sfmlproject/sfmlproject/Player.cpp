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
		velocity =  Vec2(0.0f, 0.0f);
		size = Vec2(texture.getSize().x, texture.getSize().y);

		sprite.setOrigin(size.x/2, size.y/2);
		sprite.setPosition(position.x,position.y);
	}

}

Player::~Player()
{
	std::cout << "Player destroyed" << std::endl;
}

void Player::update()
{
	if (position.x + size.x/2 + velocity.x > SCREEN_WIDTH || position.x - size.x/2 + velocity.x < 0)
	{
		velocity.x = 0.0f;
	}

	if (position.y + size.y / 2 + velocity.y > SCREEN_HEIGHT || position.y - size.y / 2 + velocity.y < 0)
	{
		velocity.y = 0.0f;
	}
	
	position.x = position.x + velocity.x;
	position.y = position.y + velocity.y;

	sprite.setPosition(position.x, position.y);
}

void Player::events(const Event& event)
{
	
	if(event.type==Event::KeyPressed)
	{
		switch (event.key.code)
		{
		case Keyboard::Up:
			velocity.y = -1.5f;
			break;
		case Keyboard::Down:
			velocity.y = 1.5f;
			break;
		case Keyboard::Left:
			velocity.x = -1.5f;
			break;
		case Keyboard::Right:
			velocity.x = 1.5f;
			break;
		}
	}
	else if(event.type==Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Up:
			velocity.y = 0.0f;
			break;
		case Keyboard::Down:
			velocity.y = 0.0f;
			break;
		case Keyboard::Left:
			velocity.x = 0.0f;
			break;
		case Keyboard::Right:
			velocity.x = 0.0f;
			break;
		}
	}
}
