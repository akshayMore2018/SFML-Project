#include "Entity.h"
#include <iostream>

Entity::Entity()
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


