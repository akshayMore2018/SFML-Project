#pragma once
#include <iostream>
class Vec2
{
public:
	float x, y;
	Vec2();
	Vec2(float a, float b);

	friend std::ostream& operator<<(std::ostream& stream,const Vec2& other);

};