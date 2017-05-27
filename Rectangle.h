#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"
class Rectangle: public virtual Point
{
public:
	Rectangle();
	Rectangle(float, float, float, float);
	Rectangle(const Rectangle& other);
	float GetWidth();
	float GetHeight();
	bool Intersects(const Rectangle& other) const;
	Rectangle GetRect() const;
protected:
	float width, height;
};
#endif