#ifndef BLOCK_H
#define BLOCK_H
#include "GameObject.h"
#include "Rectangle.h"
#include "Color.h"

extern const int SCALE;

class Block : public GameObject, public Rectangle
{
public:
	Block(float, float, float, float, Color, bool, int _hp = 0);
	void Tick();
	void Render();
	void Keyboard(int);
	void SpecialKeyboard(int);
	bool IsDestructible() const;
	int GetHp() const;
	void SetHp(int);
private:
	Color color;
	bool destructible;
	int hp;
};
#endif