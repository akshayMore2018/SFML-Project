#include "Asteroid.h"

Asteroid::Asteroid(float x , float y)
{
	sprite.setTexture(TextureManager::getInstance()->textureMap["asteroid"]);
	position = Vec2(x, y);
	animation = Animation(sprite,64,0,64,64,16,0.4f);
	float low = -4;
	float high = 4;
	velocity.x = static_cast<float>(low + (rand() / static_cast<float>(RAND_MAX/(high - low))));
	velocity.y = static_cast<float>(low + (rand() / static_cast<float>(RAND_MAX/(high - low))));
}

Asteroid::~Asteroid()
{
}

void Asteroid::update()
{
	position.x += velocity.x;
	position.y += velocity.y;

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
