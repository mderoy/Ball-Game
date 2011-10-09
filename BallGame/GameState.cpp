#include "GameState.h"
#include <stdlib.h>
#include <GL/glut.h>

GameState *GameState::GAMESTATE = 0;

void GameState::resize(int w, int h) {
	width = w;
	height = h;
}

void GameState::keyDown(unsigned char key, int xx, int yy)
{
	keys[key]=true;
}


void GameState::keyUp(unsigned char key, int xx, int yy)
{
	keys[key]=false;
}

void GameState::mousePress(int button, int state, int x, int y) 
{
	if (state == GLUT_DOWN)
		mouse[button]=true;
	else
		mouse[button]=false;
}

void GameState::mousePressedMove(int x, int y) 
{

}

void GameState::mouseReleasedMove(int x, int y) 
{

}