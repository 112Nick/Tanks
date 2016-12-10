#include "Bullet.h"
#include "Dir.h"
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

const int SCALE=20;

Bullet::Bullet(): GameObject(), Rectangle(), speed(0.0f), dir(LEFT)  {	}
Bullet::Bullet(float _x, float _y, Direction _dir) : GameObject(_x,_y), Rectangle(_x, _y, 1, 1), speed(1.0f), dir(_dir)
{ 
	x = _x;
	y = _y;
}
void Bullet::Tick() 
{

	switch(dir) 
    {
        case LEFT:
            x-=speed;
            break;
        case RIGHT:
            x+=speed;
            break;  
        case UP:
            y+=speed;
            break;
        case DOWN:
            y-=speed;
             break;
    }
 
} 
void Bullet::Render() 
{ 
	 glColor3ub( 6, 0, 176);
     glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);

}

void Bullet::Keyboard(int i){}
void Bullet::SpecialKeyboard(int i){}