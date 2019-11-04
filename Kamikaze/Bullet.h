//Blake Sullivan - Bullet Class
#ifndef BULLET_H
#define BULLET_H
#include "SDL.h"
#include "SDL_gfXPrimitives.h" 
#include <math.h>
extern SDL_Surface *screen;

class Bullet
{
private:
	float fXo, fYo, fRad;
	float fDir;
	bool bAlive;
	float fMov;
	int iRed, iGreen, iBlue;

public:
	Bullet();

	void Create(float, float, float, float);
	void Draw();
	void DrawHUD(int, int, int, int, int, int);
	void Move(float);
	void Kill();

	float GetX();
	float GetY();
	bool GetAlive();
	float GetSize();
	
	void SetColours(int, int, int);
	void SetAlive(bool);
};
#endif