#include "Quirk.h"
#include "PlayerProfile.h"
Quirk::Quirk(QUIRK_TYPE value,float x, float y)
{
	this->name = "Quirk";
	this->radius = 15;
	this->position = Vec2(x, y);
	switch (value)
	{
	case RED_LASER:
		TextureManager::getInstance()->textureMap["meteor"].setSmooth(true);
		sprite.setTexture(TextureManager::getInstance()->textureMap["meteor"]);
		meteor = Animation(this->sprite, 75, 0, 75, 128, 10, 0.4, -1);
		meteor.sprite->setOrigin(75 / 2, 64);
		meteor.sprite->setScale(0.3, 0.3);
		meteor.sprite->setColor(Color::Red);
		break;
	case BLUE_LASER:
		TextureManager::getInstance()->textureMap["meteor"].setSmooth(true);
		sprite.setTexture(TextureManager::getInstance()->textureMap["meteor"]);
		meteor = Animation(this->sprite, 75, 0, 75, 128, 10, 0.4, -1);
		meteor.sprite->setOrigin(75 / 2, 64);
		meteor.sprite->setScale(0.3, 0.3);
		meteor.sprite->setColor(Color::Cyan);
		break;
	case PINK_LASER:
		TextureManager::getInstance()->textureMap["meteor"].setSmooth(true);
		sprite.setTexture(TextureManager::getInstance()->textureMap["meteor"]);
		meteor = Animation(this->sprite, 75, 0, 75, 128, 10, 0.4, -1);
		meteor.sprite->setOrigin(75 / 2, 64);
		meteor.sprite->setScale(0.3, 0.3);
		meteor.sprite->setColor(Color(204,0,204));
		break;
	}
	this->currentType = value;
	sprite.setPosition(this->position.x,this->position.y);
	this->rotation = 0;
	remove = false;
	this->ignoreCollision = false;
}

Quirk::~Quirk()
{
}

void Quirk::update()
{
	this->meteor.update();
}

void Quirk::render(RenderWindow * window)
{
	window->draw(this->sprite);
}

void Quirk::kill()
{
	switch (this->currentType)
	{
	case RED_LASER:
		PlayerProfile::getInstance()->currentPlayerWeapon = PlayerProfile::RED_FLAME;
		break;
	case BLUE_LASER:
		PlayerProfile::getInstance()->currentPlayerWeapon = PlayerProfile::BLUE_FLAME;
		break;
	case PINK_LASER:
		PlayerProfile::getInstance()->currentPlayerWeapon=PlayerProfile::PINK_FLAME;
		break;
	}
	this->remove = true;
}

void Quirk::onCollision(Entity * obj)
{
	if (obj->name == "Player")
	{
		this->kill();
	}
}
