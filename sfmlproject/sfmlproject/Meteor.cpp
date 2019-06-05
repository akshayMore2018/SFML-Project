#include "Meteor.h"
#include "PlayerProfile.h"
#include "AudioManager.h"

Meteor::Meteor(float x, float y)
{
	this->name = "Meteor";
	position = Vec2(x, y);
	TextureManager::getInstance()->textureMap["meteor"].setSmooth(true);
	sprite.setTexture(TextureManager::getInstance()->textureMap["meteor"]);
	animation = Animation(this->sprite, 75, 0, 75, 128, 10, 0.4, -1);
	animation.sprite->setOrigin(75 / 2, 64);
	animation.sprite->setScale(0.85, 0.85);
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

	explosion.setTexture(TextureManager::getInstance()->textureMap["explosion"]);
	explosionAnim = Animation(explosion, 50, 0, 50, 50, 20, 0.4f, 1);
	explosionAnim.sprite->setOrigin(25, 25);
	explosionAnim.sprite->setPosition(x, y);
	explosionAnim.sprite->setScale(2, 2);

	maxHP = 20;
	currentHP = maxHP;
	damage = 10;
	this->sound.setBuffer(AudioManager::getInstance()->soundBuffer["blast"]);
	this->ignoreCollision = false;
}

Meteor::~Meteor()
{
}

void Meteor::update()
{
	if (this->ignoreCollision)
	{
		explosionAnim.sprite->setPosition(position.x, position.y);
		explosionAnim.update();
		if (explosionAnim.isAnimComplete() && this->sound.getStatus() == this->sound.Stopped)
		{
			this->remove = true;
		}
	}
	else
	{
		position.x = position.x + velocity.x;
		position.y = position.y + velocity.y;
	}
	
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
	if (!this->ignoreCollision)
	{
		window->draw(this->sprite);
	}
	else
	{
		if (!this->explosionAnim.isAnimComplete())
			window->draw(*(this->explosionAnim.sprite));
	}

}

void Meteor::kill()
{
	this->sound.play();
	this->ignoreCollision = true;
}

void Meteor::onCollision(Entity * obj)
{
	if (obj->name == "PinkBullet" || obj->name == "BlueBullet" || obj->name == "RedBullet")
	{
		this->takeDamage(obj->damage);
		obj->remove = true;
	}
}

void Meteor::takeDamage(int damage)
{
	if (currentHP > 0)
	{
		currentHP -= damage;
		this->sprite.setScale(this->sprite.getScale().x*0.9, this->sprite.getScale().y*0.9);
	}
	if (currentHP <= 0)
	{
		this->kill();
		PlayerProfile::getInstance()->playerScore++;
	}
}
