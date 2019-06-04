#include "Entity.h"
#include <iostream>

Entity::Entity():ignoreCollision(false)
{
	
}

Entity::~Entity()
{
	std::cout << "Entity destructor" << std::endl;
}

void Entity::takeDamage(int damage)
{
	if(currentHP>0)
	currentHP -= damage;
}

void Entity::kill()
{
}

void Entity::onCollision(Entity * obj)
{
}


