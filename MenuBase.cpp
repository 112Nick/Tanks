#include "MenuBase.h"
#include "Controller.h"
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

MenuBase::MenuBase(std::string title, Controller* c)
{
	this->title = title;
	this->c = c;
}

void MenuBase::Keyboard(int key)
{
	switch(key) {
		case 13:
			SelectMenuItem(position);
		break;   
	}	
}

void MenuBase::SpecialKeyboard(int key) 
{
	switch(key) {
		case GLUT_KEY_UP:
			position = abs(position-1) % items.size();
		break;
		case GLUT_KEY_DOWN:
			position = abs(position+1) % items.size();
		break;   
	}
}

void MenuBase::Render()
{
	glColor3ub( 0, 0, 0);
    glRectf(0,0,800,600);

	glColor3ub( 0, 222, 18);
    glRasterPos3d(WIDTH/2-title.length()*4.5, HEIGHT - 30, 0);
    glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)title.c_str());

    int offset_y = 250;
    int i = 0;
    for(std::string& s: items)
    {
    	if(i == position)
    	{
    		glRasterPos3d(WIDTH/2-s.length()*4.5 - 40, HEIGHT - offset_y, 0);
    		glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)">");
    		glRasterPos3d(WIDTH/2+s.length()*3.5 + 40, HEIGHT - offset_y, 0);
    		glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)"<");
    	}
    	glRasterPos3d(WIDTH/2-s.length()*4.5, HEIGHT - offset_y, 0);
    	glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)s.c_str());
    	offset_y += 40;
    	i++;
    }
}