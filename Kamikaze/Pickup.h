//Blake Sullivan - Pickup.h
#ifndef PICKUP_H
#define PICKUP_H

#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
extern SDL_Surface *screen;

class Pickup
{
private:
	char cType;
	int iValue;
	int iPoints;
	bool bAlive;
	float fX, fY, fSize;
	int iRed, iGreen, iBlue;

public:
	void Create(char, int, int, float, float, float);

	void Draw();

	void SetType(char);
	void SetVaue(int);
	void SetPoints(int);
	void SetAlive(bool);
	void SetPos(float, float, float);
	void SetColours(char);
	void SetColourValues(int, int, int);

	char GetType();
	int GetValue();
	int GetPoints();
	bool GetAlive();
	float GetX();
	float GetY();
	float GetSize();
	int GetRed();
	int GetGreen();
	int GetBlue();
};
#endif