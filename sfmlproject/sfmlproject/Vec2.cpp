#include "Vec2.h"
#include <iostream>

Vec2::Vec2()
{
}

Vec2::Vec2(float a, float b):x(a), y(b)
{
	
}



std::ostream & operator<<(std::ostream & stream, const Vec2 & other)
{
	stream << "("<<other.x << "," << other.y<<")";
	return stream;
}
