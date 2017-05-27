#ifndef MENUBASE_H
#define MENUBASE_H
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Controller.h"

class Controller;

extern const int WIDTH;
extern const int HEIGHT;

class MenuBase
{
public:
	MenuBase(std::string title, Controller* c);
	void Keyboard(int key);
	void SpecialKeyboard(int key);
	void Render();
protected:
	virtual void SelectMenuItem(int) = 0;
	std::string title;
	std::vector<std::string> items;
	int position;
	Controller* c;
};

#endif