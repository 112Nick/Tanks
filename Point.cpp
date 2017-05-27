#include "Point.h"

Point::Point(): x(0.0f), y(0.0f) {}

Point::Point(float _x, float _y): x(_x), y(_y) {}

float Point::GetX() const
{
	return x;
}

float Point::GetY() const
{
	return y;
}

void Point::Translate(float _x, float _y)
{
	x += _x;
	y += _y;
}