#include "Vec2.h"
#include <iostream>

Vec2::Vec2()
{
}

Vec2::Vec2(float a, float b):x(a), y(b)
{
	
}

Vec2::~Vec2()
{
	std::cout << "destroyed Vec2" << std::endl;
}

