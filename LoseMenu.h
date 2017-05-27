#ifndef LOSEMENU_H
#define LOSEMENU_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>
#include "Controller.h"
#include "MenuBase.h"

class Controller;

extern const int WIDTH;
extern const int HEIGHT;

class LoseMenu : public MenuBase
{
public:
	LoseMenu(std::string title, Controller* c);
	void SetScore(int score);
private:
	std::string originalTitle;
	void SelectMenuItem(int);
};
#endif
