#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	
}

Entity::~Entity()
{
	std::cout << "Entity destructor" << std::endl;
}

void Entity::update()
{
}


void Entity::events(const Event& event)
{
}

