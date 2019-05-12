#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	
}

Entity::~Entity()
{
	clear();
	std::cout << "Entity destroyed" << std::endl;
}

void Entity::update()
{
}


void Entity::events()
{
}

void Entity::clear()
{
	std::cout << "clearing entity" << std::endl;
}
