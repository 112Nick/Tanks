#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>
#include "Controller.h"
#include "MenuBase.h"

class Controller;

extern const int WIDTH;
extern const int HEIGHT;

class PauseMenu : public MenuBase
{
public:
	PauseMenu(std::string title, Controller* c);
private:
	void SelectMenuItem(int);
};
#endif
