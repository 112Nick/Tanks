#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
class Rectangle: public virtual Point
{
public:
	Rectangle();
	Rectangle(float, float, float, float);
	float GetWidth();
	float GetHeight();
	bool Intersects(const Rectangle& other);

protected:
	float width, height;
};
#endif