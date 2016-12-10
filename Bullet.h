#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"
#include "Rectangle.h"
#include "Dir.h"


class Bullet: public GameObject, Rectangle
{
public:
	Bullet();
	Bullet(float x, float y, Direction dir);
	void Tick();
	void Render();
	void Keyboard(int);
	void SpecialKeyboard(int);
private:
	float speed;
	Direction dir;
};
#endif