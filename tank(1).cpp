#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

const int DELAY = 50;
const int N = 60, M = 40;
const int SCALE = 25;
const int W = N*SCALE;
const int H = M*SCALE;

class Block {
 public:
  int x, y; 
  Block() : x(0), y(0) {
  
  }
  Block(int a, int b) : x(a), y(b) {
 
  }
  void set(int a,int b) {
    x = a;
    y = b;
  }
  void Draw() {
    glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
  }
  void Clear() {
   glColor3ub( 255, 255, 255);
   glRectf((x-0.4)*SCALE,(y-0.4)*SCALE,(x+0.4)*SCALE,(y+0.4)*SCALE);
  }
};

Block buff;

enum Direction { LEFT, UP, RIGHT, DOWN };

class Tank {
 public:
  Tank(): x(0), y(0), dir(LEFT){}
  Tank(int x, int y) {
    this->x = x;
    this->y = y;
  }
  void Draw() {
    switch(dir) {
      case LEFT:
        glColor3ub( 6, 0, 176);
	buff.set(x,y); buff.Draw();
        buff.set(x-1,y); buff.Draw();
	buff.set(x,y+1); buff.Draw();
	buff.set(x,y-1); buff.Draw();
	buff.set(x+1,y+1); buff.Draw();
        buff.set(x+1,y-1); buff.Draw();
	break;
      case RIGHT:
	glColor3ub( 6, 0, 176);
        buff.set(x,y); buff.Draw();
        buff.set(x+1,y); buff.Draw();
	buff.set(x,y+1); buff.Draw();
	buff.set(x,y-1); buff.Draw();
        buff.set(x-1,y+1); buff.Draw();
	buff.set(x-1,y-1); buff.Draw();
        break;  
      case UP:
        glColor3ub( 6, 0, 176);
	buff.set(x,y); buff.Draw();
	buff.set(x+1,y); buff.Draw();
	buff.set(x-1,y); buff.Draw();
	buff.set(x,y+1); buff.Draw();
	buff.set(x+1,y-1); buff.Draw();
	buff.set(x-1,y-1); buff.Draw();
	break;
      case DOWN:
	glColor3ub( 6, 0, 176);
	buff.set(x,y); buff.Draw();
	buff.set(x,y-1); buff.Draw();
	buff.set(x+1,y); buff.Draw();
	buff.set(x-1,y); buff.Draw();
	buff.set(x+1,y+1); buff.Draw();
	buff.set(x-1,y+1); buff.Draw();
        break;
    }
  }
  void Keyboard(int key) {
    switch(key) {
      case GLUT_KEY_UP: 
        dir = UP; 
        y++; 
        break;
      case GLUT_KEY_RIGHT: 
        dir = RIGHT;
        x++; 
        break;
      case GLUT_KEY_LEFT:
        dir = LEFT;
        x--; 
        break;
      case GLUT_KEY_DOWN: 
        dir = DOWN;
        y--;
        break;
      case GLUT_KEY_F1: 
        //Shoot();
        break;
    }
  }
  void Shoot() {
     switch(dir) {
      case LEFT:
        glColor3ub( 6, 0, 176);
	for(float i=x; i>0; i-=0.5) {
           buff.set(i,y); buff.Draw(); buff.Clear();
        }
	break;
      case RIGHT:
	glColor3ub( 6, 0, 176);
        for(float i=x; i<N; i+=0.5) {
           buff.set(i,y); buff.Draw(); buff.Clear();
        }
        break;  
      case UP:
        glColor3ub( 6, 0, 176);
	for(float i=y; i>0; i-=0.5) {
           buff.set(x,i); buff.Draw(); buff.Clear();
        }
	break;
      case DOWN:
	glColor3ub( 6, 0, 176);
	for(float i=y; i<M; i+=0.5) {
           buff.set(x,i); buff.Draw(); buff.Clear();
        }
        break;
    }
  }
  void Tick() {
       
  }
 private:
  int x, y;
  Direction dir;
}; 

class World {
 public:
  World() {};
  void Draw() {
    glColor3ub( 59, 23, 5);
    for(float i = 0.5; i< N;i+=0.5) { 
      buff.set(i,5); buff.Draw();
      buff.set(i,M); buff.Draw();
    }
    for(float i = 5; i< M;i+=0.5) { 
      buff.set(0.5,i); buff.Draw();
      buff.set(N-1,i); buff.Draw();
    }
  }
};

Tank t(10, 10);
World world;
void Display() {
  glClearColor(255,255,255,1);
  glClear(GL_COLOR_BUFFER_BIT);
  world.Draw();
  t.Draw();
  
  //glFlush();
}
 
void Timer(int = 0) {
  Display();
  glutTimerFunc(DELAY, Timer, 0);
}
 
void Keyboard(int key, int x, int y) {
  t.Keyboard(key);
}
 
int main(int argc, char** argv) {
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("Test");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, W, 0, H);
    glutDisplayFunc(Display);
    glutTimerFunc(DELAY, Timer, 0);
    glutSpecialFunc(Keyboard);
    glutMainLoop();
}
