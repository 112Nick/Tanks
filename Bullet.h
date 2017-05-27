#ifndef BULLET_H
#define BULLET_H
#include "GameObject.h"
#include "Rectangle.h"
#include "Dir.h"

extern const int SCALE;

class Bullet: public GameObject, public Rectangle
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