#include <stdlib.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "MenuState.h"
#include "LevelState.h"
#include "Globals.h"
#include <string>
using namespace std;
 int MenuState::screenHeight = 1;
 int MenuState::screenWidth = 1;
// init
MenuState::MenuState() {
	glShadeModel(GL_SMOOTH);				// GL_SMOOTH or GL_FLAT
	glClearDepth(1.0f);						// depth cleared to
	glEnable(GL_DEPTH_TEST);				// enable depth testing
	glEnable(GL_TEXTURE_2D);				// enable texturing
	glDepthFunc(GL_LEQUAL);					// lesser than or equal to depth
	glEnable(GL_BLEND);
}

void MenuState::resize(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	glOrtho(0.0, 1.0, 0.0, 1.0, 0.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	screenWidth = w;
	screenHeight = h;
}

void MenuState::update(int fps) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void MenuState::render() {
	glLoadIdentity();

	glutSwapBuffers();
}




void MenuItem::drawItem()
{
    texture->use();
	glBegin(GL_QUADS);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	if(current)
	{
	glColor4f(0.0, 1.0, 1.0,0.9);
	}
	else
	{
	glColor4f(1,1,1,1);
	}
		glTexCoord2f(bottomRightX,topLeftY);glVertex3f(bottomRightX, topLeftY, -1.0);
		glTexCoord2f(bottomRightX,bottomRightY);glVertex3f(bottomRightX,  bottomRightY, -1.0);
		glTexCoord2f(topLeftX,bottomRightY);glVertex3f( topLeftX, bottomRightY, -1.0);
		glTexCoord2f(topLeftX,topLeftY);glVertex3f(topLeftX,topLeftY,-1.0);
	glEnd();

	int textWidth = glutBitmapLength(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)description.c_str());
	int textHeight = glutBitmapHeight(GLUT_BITMAP_HELVETICA_18);

	glColor3f(1.0f, 1.0f, 1.0f);
	glRasterPos2f(bottomRightX/2-topLeftX/2, topLeftY/2+bottomRightY/2);
	glutBitmapString(GLUT_BITMAP_HELVETICA_18,(const unsigned char*)description.c_str());

}
void MenuItem::setTopLeft(float x, float y)
{
	topLeftX = x;
	topLeftY = y;
}

void MenuItem::setBottomRight(float x, float y)
{
	bottomRightX = x;
	bottomRightY = y;
}

void MenuItem::setDescription(string desc)
{
	description = desc;
}

void MenuItem::setButtonLink(GameState* link)
{
	buttonLink = link;
}

void MenuItem::switchState()
{
GAMESTATE = new LevelState();
}