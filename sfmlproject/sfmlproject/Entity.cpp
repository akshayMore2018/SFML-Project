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


void Entity::events(const Event& event)
{
}

void Entity::clear()
{
	std::cout << "clearing entity" << std::endl;
}
