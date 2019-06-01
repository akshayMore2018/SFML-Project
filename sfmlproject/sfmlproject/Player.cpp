#include "Player.h"
#include <iostream>
#include "Timer.h"
#include "PlayerProfile.h"
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
	radius = 20;
	explosion.setTexture(TextureManager::getInstance()->textureMap["explosion"]);
	explosionAnim = Animation(explosion, 50, 0, 50, 50, 20, 0.4f, 1);
	explosionAnim.sprite->setOrigin(25, 25);
	explosionAnim.sprite->setPosition(position.x,position.y);
	explosionAnim.sprite->setScale(2, 2);
	maxHP = 30;
	currentHP = maxHP;
	damage = 0;
	immune = false;
	timer = new Timer(0.3);
	PlayerProfile::getInstance()->playerLives = 2;
	PlayerProfile::getInstance()->playerHP = currentHP;
	PlayerProfile::getInstance()->playerScore = 0;
}

Player::~Player()
{
	std::cout << "Player destructor" << std::endl;
	delete timer;
}

void Player::update()
{

	if (remove)
	{
		explosionAnim.sprite->setPosition(position.x, position.y);
		explosionAnim.update();
	}
	else
	{

		if (timer->update())
		{
			immune = false;
			timer->deactivate();
			this->sprite.setColor(Color(255,255,255));
		}
		
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
		else if (sprite.getPosition().x < -15)
		{
			position.x = SCREEN_WIDTH + 15;
		}
		if (sprite.getPosition().y > SCREEN_HEIGHT + 15)
		{
			position.y = -15;
		}
		else if (sprite.getPosition().y < -15)
		{
			position.y = SCREEN_HEIGHT + 15;
		}
		rotation += angle;
		position.x = position.x + cos((rotation)*0.017453f) * speed;
		position.y = position.y + sin((rotation)*0.017453f) * speed;

		sprite.setPosition(position.x, position.y);
		sprite.setRotation(rotation + 90);

	}
	sprite.setPosition(position.x, position.y);
	animation.update();

	
}

void Player::render(RenderWindow * window)
{
	if (!remove)
	{
		window->draw(this->sprite);
	}
	else
	{
		window->draw(*(this->explosionAnim.sprite));
	}
}


void Player::thrust(float acceleration)
{
	this->acceleration = acceleration;
}

void Player::takeDamage(int damage)
{
	if (this->immune)
		return;

	if (currentHP > 0)
	{
		currentHP -= damage;
		immune = true;
		timer->activate();
		this->sprite.setColor(Color::Red);
		PlayerProfile::getInstance()->playerHP = currentHP;
	}
	if(currentHP<=0)
	{
		this->remove = true;
	}
		
}

void Player::rotate(float angle)
{
	this->angle = angle;
}

