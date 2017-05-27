#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include "GameObject.h"
#include "Controller.h"
#include "Tank.h"
#include "Bot.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "LoseMenu.h"

const int DELAY = 30;
const int WIDTH = 800, HEIGHT = 600;
const int SCALE = 10;

Controller c;

void Render() {
	glFlush();
	glClear(GL_COLOR_BUFFER_BIT);
	c.Render();
}

void Tick(int = 0)
{
	c.Tick();
	Render();
	glutTimerFunc(DELAY, Tick, 0);
}

void Keyboard(unsigned char key, int a, int b)
{
	c.Keyboard(key);
}

void SpecialK(int key, int a, int b)
{
	c.SpecialKeyboard(key);
}

int main(int argc, char** argv)
{
    srand(time(0));
    c.SetPlayer(new Tank(10, 10, "Tank", c, false, 3));
    c.SetMap(new Map("map", 0, 1));
    c.SetMenu(new Menu("TANKS ELITE", &c));
    c.SetPauseMenu(new PauseMenu("PAUSE", &c));
    c.SetLoseMenu(new LoseMenu("YOU LOSE", &c));
    c.AddBot(Bot(Tank(40, 40, "Enemy", c, true, 3)));
    c.AddBot(Bot(Tank(50, 40, "Enemy", c, true, 3)));
	c.AddBot(Bot(Tank(60, 40, "Enemy", c, true, 3)));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT+20);
    glutCreateWindow("TanksElite");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT+20);
    glutDisplayFunc(Render);
    glutTimerFunc(DELAY, Tick, 0);
    glutSpecialFunc(SpecialK);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
}
