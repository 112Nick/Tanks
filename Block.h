#ifndef BLOCK_H
#define BLOCK_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Point.h"
class Block : public Point
{
public:
	Block(float, float);
	void Render();
};
#endif
