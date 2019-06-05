#include "Asteroid.h"
#include "AudioManager.h"
#include "PlayerProfile.h"
Asteroid::Asteroid(float x , float y)
{
	this->name = "Asteroid";
	sprite.setTexture(TextureManager::getInstance()->textureMap["asteroid"]);
	position = Vec2(x, y);
	radius = 20;
	animation = Animation(sprite,64,0,64,64,16,0.4f,-1);
	animation.sprite->setOrigin(32,32);
	float low = -4;
	float high = 4;
	velocity.x = static_cast<float>(low + (rand() / static_cast<float>(RAND_MAX/(high - low))));
	velocity.y = static_cast<float>(low + (rand() / static_cast<float>(RAND_MAX/(high - low))));
	explosion.setTexture(TextureManager::getInstance()->textureMap["explosion"]);
	explosionAnim = Animation(explosion, 50, 0, 50, 50, 20, 0.4f, 1);
	explosionAnim.sprite->setOrigin(25, 25);
	explosionAnim.sprite->setPosition(x, y);
	explosionAnim.sprite->setScale(2, 2);
	maxHP = 20;
	currentHP = maxHP;
	damage = 5;
	this->sound.setBuffer(AudioManager::getInstance()->soundBuffer["blast"]);
	this->ignoreCollision = false;
}

Asteroid::~Asteroid()
{
	std::cout << "Asteroid destructor" << std::endl;
}

void Asteroid::update()
{

	if(this->ignoreCollision)
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

		position.x += velocity.x;
		position.y += velocity.y;
	}
	if (sprite.getPosition().x > SCREEN_WIDTH + sprite.getTextureRect().width/2)
	{
		position.x = -sprite.getTextureRect().width/2;
	}
	else if (sprite.getPosition().x < -sprite.getTextureRect().width/2)
	{
		position.x = SCREEN_WIDTH + sprite.getTextureRect().width/2;
	}
	if (sprite.getPosition().y > SCREEN_HEIGHT + sprite.getTextureRect().height/2)
	{
		position.y = -sprite.getTextureRect().height/2;
	}
	else if (sprite.getPosition().y < -sprite.getTextureRect().height/2)
	{
		position.y = SCREEN_HEIGHT + sprite.getTextureRect().height/2;
	}

	sprite.setPosition(position.x, position.y);
	animation.update();
}

void Asteroid::render(RenderWindow * window)
{
	if (!this->ignoreCollision)
	{
		window->draw(this->sprite);
	}
	else
	{
		if(!this->explosionAnim.isAnimComplete())
		window->draw(*(this->explosionAnim.sprite));
	}

}

void Asteroid::kill()
{
	this->sound.play();
	this->ignoreCollision = true;
}

void Asteroid::onCollision(Entity * obj)
{
	if (obj->name == "PinkBullet" || obj->name == "BlueBullet" || obj->name == "RedBullet")
	{
		this->takeDamage(obj->damage);
		obj->remove = true;
	}
	
}

void Asteroid::takeDamage(int damage)
{

	if (currentHP > 0)
	{
		currentHP -= damage;
		this->sprite.setColor(Color::Red);
	}
	if (currentHP <= 0)
	{
		this->kill();
		PlayerProfile::getInstance()->playerScore++;
	}
}
