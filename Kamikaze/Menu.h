//Blake Sullivan - Menu.h
#ifndef MENU_H
#define MENU_H
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
extern SDL_Surface *screen;

class Menu
{
private:
	SDL_Surface *image;
	SDL_Rect sclip, dclip;
	int iRed, iGreen, iBlue;

public:
	Menu(char);
	~Menu();
	void DrawMenu();
	void DrawSplash(char);
	void DrawWin();
	void DrawLose();
	void DrawStory();
	void DrawOptions(bool, bool);
	void DrawHighScore();

	void OutputString(string, int, int);
	void SetStringColours(int, int, int);

	string LoadHighScore(int);
};
#endif