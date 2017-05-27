#ifndef MENU_H
#define MENU_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>
#include "Controller.h"
#include "MenuBase.h"

class Controller;

extern const int WIDTH;
extern const int HEIGHT;

class Menu : public MenuBase
{
public:
	Menu(std::string title, Controller* c);
private:
	void SelectMenuItem(int);
};
#endif
