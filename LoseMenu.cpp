#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "LoseMenu.h"
#include "MenuBase.h"

LoseMenu::LoseMenu(std::string _title, Controller* _c): MenuBase(_title, _c)
{
	items.push_back("TO MENU");
	originalTitle = _title;
}

void LoseMenu::SelectMenuItem(int pos)
{
	switch(pos)
	{
		case 0:
			c->StopGame();
			break;
	}
}

void LoseMenu::SetScore(int score)
{
	title = originalTitle + " | Your Score: " + std::to_string(score);
}