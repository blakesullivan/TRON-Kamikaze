//Blake Sullivan - Pick.cpp
#include "Pickup.h"

void Pickup::Create(char t, int v, int p, float x, float y, float s)
{
	SetType(t);
	SetVaue(v);
	SetPoints(p);
	SetAlive(true);
	SetPos(x, y, s);
	SetColours(cType);
}

void Pickup::Draw()
{
	float fHalfSize = fSize / 2;
	rectangleRGBA(screen, fX - (fSize + 1), fY - (fHalfSize + 1), fX + (fSize + 1), fY + (fHalfSize + 1), 255, 255, 255, 255);
	rectangleRGBA(screen, fX - (fHalfSize + 1), fY - (fSize + 1), fX + (fHalfSize + 1), fY + (fSize + 1), 255, 255, 255, 255);

	boxRGBA(screen, fX - fSize, fY - fHalfSize, fX + fSize, fY + fHalfSize, iRed, iGreen, iBlue, 255);
	boxRGBA(screen, fX - fHalfSize, fY - fSize, fX + fHalfSize, fY + fSize, iRed, iGreen, iBlue, 255);
}

void Pickup::SetType(char t)
{
	cType = t;
}
void Pickup::SetVaue(int v)
{
	iValue = v;
}
void Pickup::SetPoints(int p)
{
	iPoints = p;
}
void Pickup::SetAlive(bool a)
{
	bAlive = a;
}
void Pickup::SetPos(float x, float y, float s)
{
	fX = x;
	fY = y;
	fSize = s;
}
void Pickup::SetColours(char type)
{
	switch (type)
	{
	case 'b':
		SetColourValues(255,255,255);
	break;
	case 'h':
		SetColourValues(0,0,255);
	break;
	case 'l':
		SetColourValues(0,200,200);
	break;
	case 's':
		SetColourValues(0,255,0);
	break;
	default:
		SetColourValues(0,0,255);
	}
}
void Pickup::SetColourValues(int r, int g, int b)
{
	iRed = r;
	iGreen = g;
	iBlue = b;
}

char Pickup::GetType()
{
	return cType;
}
int Pickup::GetValue()
{

	return iValue;
}
int Pickup::GetPoints()
{
	return iPoints;
}
bool Pickup::GetAlive()
{
	return bAlive;
}
float Pickup::GetX()
{
	return fX;
}
float Pickup::GetY()
{
	return fY;
}
float Pickup::GetSize()
{
	return fSize;
}
int Pickup::GetRed()
{
	return iRed;
}
int Pickup::GetGreen()
{
	return iGreen;
}
int Pickup::GetBlue()
{
	return iBlue;
}