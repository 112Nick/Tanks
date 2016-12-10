#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

const int DELAY = 300;
const int N = 30, M = 20;
const int SCALE = 25;
const int W = N*SCALE;
const int H = M*SCALE;

enum Direction
{
	LEFT, UP, RIGHT, RUBEN
};

class Tank
{
private:
	int x, y;
	Direction dir;
public:
	Tank(): x(0), y(0), dir(LEFT){}
	Tank(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Draw()
	{
		switch(dir)
		{
			case LEFT:
				glRectf((x+0.1)*SCALE, (y+0.1)*SCALE, (x+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y+0.1)*SCALE, (x-1+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+0.1)*SCALE, (y+1+0.1)*SCALE, (x+0.9)*SCALE, (y+1+0.9)*SCALE);
				glRectf((x+0.1)*SCALE, (y-1+0.1)*SCALE, (x+0.9)*SCALE, (y-1+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y+1+0.1)*SCALE, (x+1+0.9)*SCALE, (y+1+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y-1+0.1)*SCALE, (x+1+0.9)*SCALE, (y-1+0.9)*SCALE);
				break;
			case RIGHT:
				glRectf((x+0.1)*SCALE, (y+0.1)*SCALE, (x+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y+0.1)*SCALE, (x+1+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+0.1)*SCALE, (y+1+0.1)*SCALE, (x+0.9)*SCALE, (y+1+0.9)*SCALE);
				glRectf((x+0.1)*SCALE, (y-1+0.1)*SCALE, (x+0.9)*SCALE, (y-1+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y+1+0.1)*SCALE, (x-1+0.9)*SCALE, (y+1+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y-1+0.1)*SCALE, (x-1+0.9)*SCALE, (y-1+0.9)*SCALE);
				break;
			case UP:
				glRectf((x+0.1)*SCALE, (y+0.1)*SCALE, (x+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+0.1)*SCALE, (y+1+0.1)*SCALE, (x+0.9)*SCALE, (y+1+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y+0.1)*SCALE, (x-1+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y+0.1)*SCALE, (x+1+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y-1+0.1)*SCALE, (x-1+0.9)*SCALE, (y-1+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y-1+0.1)*SCALE, (x+1+0.9)*SCALE, (y-1+0.9)*SCALE);
				break;
			case RUBEN:
				glRectf((x+0.1)*SCALE, (y+0.1)*SCALE, (x+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+0.1)*SCALE, (y-1+0.1)*SCALE, (x+0.9)*SCALE, (y-1+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y+0.1)*SCALE, (x-1+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y+0.1)*SCALE, (x+1+0.9)*SCALE, (y+0.9)*SCALE);
				glRectf((x-1+0.1)*SCALE, (y+1+0.1)*SCALE, (x-1+0.9)*SCALE, (y+1+0.9)*SCALE);
				glRectf((x+1+0.1)*SCALE, (y+1+0.1)*SCALE, (x+1+0.9)*SCALE, (y+1+0.9)*SCALE);
				break;
		}
	}
	void Keyboard(int key)
	{
		switch(key)
		{
			case GLUT_KEY_UP: dir = UP; break;
			case GLUT_KEY_RIGHT: dir = RIGHT; break;
			case GLUT_KEY_LEFT: dir = LEFT; break;
			case GLUT_KEY_DOWN: dir = RUBEN; break;
		}
	}

	void Tick()
	{
		
	}
};

Tank t(10, 10);

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	t.Draw();
	glFlush();
}

void Timer(int = 0)
{
	Display();
	glutTimerFunc(DELAY, Timer, 0);
}

void Keyboard(int key, int x, int y)
{
	t.Keyboard(key);
}

int main(int argc, char** argv)
{
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