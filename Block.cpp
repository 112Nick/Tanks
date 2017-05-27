#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Block.h"
#include "Rectangle.h"
#include "Color.h"
#include <iostream>
#include <ctime>
#include <random>

Block::Block(float x, float y, float width, float height, Color c, bool destr, int _hp): GameObject(x, y), 
									Rectangle(x, y, width, height),  Point(x, y), color(c), destructible(destr), hp(_hp)
{

}

void Block::Tick()
{
	
}

void Block::Keyboard(int key)
{

}

void Block::SpecialKeyboard(int key)
{
	
}


void Block::Render()
{
	glColor3f(color.r, color.g, color.b);
	glRectf(x*SCALE, y*SCALE, (x+width)*SCALE, (y+height)*SCALE);
}


bool Block::IsDestructible() const
{
	return destructible;
}

int Block::GetHp() const
{
	return hp;
}

void Block::SetHp(int _hp)
{
	hp = _hp;
}