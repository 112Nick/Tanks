#include "Rectangle.h"
#include "Point.h"

Rectangle::Rectangle(): Point(), width(0.0f), height(0.0f) {}

Rectangle::Rectangle(float x, float y, float w, float h): Point(x, y), width(w), height(h) {}

float Rectangle::GetWidth()
{
	return width;
}

float Rectangle::GetHeight()
{
	return height;
}

bool Rectangle::Intersects(const Rectangle& other)
{
	//return (((y < other.y && (y + height) > other.y) || (y > other.y && y < (other.y + other.height))
			//&& ((x < other.x && (x + width) > other.x) || (x > other.x && x < (other.x + other.width)));
	return true;
}
