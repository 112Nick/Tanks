#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "Menu.h"
#include "MenuBase.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

Menu::Menu(std::string _title, Controller* _c): MenuBase(_title, _c)
{
	items.push_back("NEW GAME");
	items.push_back("EXIT");
}

void Menu::SelectMenuItem(int pos)
{
	switch(pos)
	{
		case 0:
			c->NewGame();
			break;
		case 1:
			exit(0);
			break;
	}
}