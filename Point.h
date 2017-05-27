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
	float GetX() const;
	float GetY() const;
	void Translate(float x, float y);
protected:
	float x, y;
};
#endif