#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Tank.h"
#include "Rectangle.h"
#include "Bullet.h"
#include "Controller.h"
#include "GameObject.h"
#include "Dir.h"

Tank::Tank(): GameObject(), dir(LEFT){  }
Tank::Tank(float _x, float _y, Controller& _c): GameObject(_x, _y), dir(LEFT), c(&_c) 
{
	x = _x;
	y = _y;
}

void Tank::Render() 
    {
        switch(dir) 
        {
            case LEFT:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-0.4)*SCALE,(x-1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y+1-0.4)*SCALE,(x+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y-1-0.4)*SCALE,(x+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y+1-0.4)*SCALE,(x+1+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-1-0.4)*SCALE,(x+1+0.4)*SCALE,(y-1+0.4)*SCALE);
                break;
            case RIGHT:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-0.4)*SCALE,(x+1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y+1-0.4)*SCALE,(x+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y-1-0.4)*SCALE,(x+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y+1-0.4)*SCALE,(x-1+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-1-0.4)*SCALE,(x-1+0.4)*SCALE,(y-1+0.4)*SCALE);
                break;  
            case UP:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-0.4)*SCALE,(x+1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-0.4)*SCALE,(x-1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y+1-0.4)*SCALE,(x+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-1-0.4)*SCALE,(x+1+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-1-0.4)*SCALE,(x-1+0.4)*SCALE,(y-1+0.4)*SCALE);
                break;
            case DOWN:
                glColor3ub( 6, 0, 176);
                glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-0.4)*SCALE,(y-1-0.4)*SCALE,(x+0.4)*SCALE,(y-1+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y-0.4)*SCALE,(x+1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y-0.4)*SCALE,(x-1+0.4)*SCALE,(y+0.4)*SCALE);
                glRectf((x+1-0.4)*SCALE,(y+1-0.4)*SCALE,(x+1+0.4)*SCALE,(y+1+0.4)*SCALE);
                glRectf((x-1-0.4)*SCALE,(y+1-0.4)*SCALE,(x-1+0.4)*SCALE,(y+1+0.4)*SCALE);
                break;
        }
    }

    void Tank::SpecialKeyboard(int key) //Леня какого х** у нас танк тикает в кейборде?
    {
        switch(key) {
      case GLUT_KEY_UP: 
        if(dir == UP && !c->Check(x,y+2))
          y++; 
        dir = UP; 
        break;
      case GLUT_KEY_RIGHT: 
        if(dir == RIGHT && !c->Check(x+2,y))
          x++; 
        dir = RIGHT;
        break;
      case GLUT_KEY_LEFT:
        if(dir == LEFT && !c->Check(x-2,y))
          x--; 
        dir = LEFT;
        break;
      case GLUT_KEY_DOWN: 
        if(dir == DOWN && !c->Check(x,y-2))
          y--;
        dir = DOWN;
        break;
        }
    }

    void Tank::Keyboard(int key)
    {
        switch(key)
        {
            case 32:
                Shoot();
                break;
        }
    }

    void Tank::Shoot() 
    {
        c->AddOther(*(new Bullet(x, y, dir)));
    }

  void Tank::Tick() {
       
  }
