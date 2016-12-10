#include "Point.h"

Point::Point(): x(0.0f), y(0.0f) {}

Point::Point(float _x, float _y): x(_x), y(_y) {}

float Point::GetX()
{
	return x;
}

float Point::GetY()
{
	return y;
}