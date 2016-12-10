/*
Класс объектов, которые имеют позицию в пространстве.т
*/
#ifndef POINT_H
#define POINT_H
class Point
{
public:
	Point();
	Point(float, float);
	float GetX();
	float GetY();
protected:
	float x, y;
};
#endif