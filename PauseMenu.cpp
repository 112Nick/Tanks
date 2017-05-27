#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "PauseMenu.h"
#include "MenuBase.h"

PauseMenu::PauseMenu(std::string _title, Controller* _c): MenuBase(_title, _c)
{
	items.push_back("CONTINUE");
	items.push_back("BACK TO MENU");
}

void PauseMenu::SelectMenuItem(int pos)
{
	switch(pos)
	{
		case 0:
			c->Continue();
			break;
		case 1:
			c->StopGame();
			break;
	}
}