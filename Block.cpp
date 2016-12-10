#include "Block.h"

Block::Block(float x, float y): Point(x*20, y*20) {}

void Block::Render()
{
	glColor3ub( 0, 0, 0);
	glRectf(x - 8, y - 8, x + 8, y + 8);
}
