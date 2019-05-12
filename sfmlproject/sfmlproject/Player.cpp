#include "Player.h"
#include <iostream>


Player::Player()
{
	if (!texture.loadFromFile("Assets/pacman.png"))
	{
		std::cout << "Could not load asset";
	}
	else
	{
		sprite.setTexture(texture);
		position = new Vec2(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		velocity = new Vec2(1.5f, 1.5f);
		sprite.setOrigin(64, 64);
		sprite.setPosition(position->x,position->y);
		
		
	}

}

Player::~Player()
{
	std::cout << "Player destroyed" << std::endl;
	delete velocity;
	delete position;
}

void Player::update()
{
	
	if (position->x + 64 > SCREEN_WIDTH || position->x - 64 < 0)
	{
		velocity->x = -velocity->x;
	}

	if (position->y + texture.getSize().y / 2 > SCREEN_HEIGHT || position->y - texture.getSize().y / 2 < 0)
	{
		velocity->y = -velocity->y;
	}
	
	position->x = position->x + velocity->x;
	position->y = position->y + velocity->y;

	sprite.setPosition(position->x, position->y);
}
