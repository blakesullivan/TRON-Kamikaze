//Blake Sullivan - Bullet.cpp
#include "Bullet.h"

Bullet::Bullet()
{
	SetColours(255, 255, 255);
}

void Bullet::Create(float x, float y, float dir, float move)
{
	fXo=x;
	fYo=y;
	fRad=5;
	fDir=dir;
	fMov=move;
	bAlive=true;
}

void Bullet::Draw()
{
	circleRGBA(screen, fXo, fYo, fRad-1, iRed, iGreen, iBlue, 255);
	circleRGBA(screen, fXo, fYo, fRad, iRed, iGreen, iBlue, 255);
	circleRGBA(screen, fXo, fYo, fRad+1, 255, 255, 255, 255);
}

void Bullet::DrawHUD(int iType, int x, int y, int icn, int ocn, int size)
{
	filledCircleRGBA(screen, x, y, size + icn+ocn, 255, 255, 255, 255);
	filledCircleRGBA(screen, x, y, size + icn, iRed, iGreen, iBlue, 255);
	filledCircleRGBA(screen, x, y, size, 0, 0, 0, 255);
}

void Bullet::SetColours(int r, int g, int b)
{
	iRed=r;
	iGreen=g;
	iBlue=b;
}

void Bullet::Move(float fDeltaTime)
{
	float dx=(fMov * fDeltaTime)*sin(fDir);
	float dy=(fMov * fDeltaTime)*cos(fDir);
	fXo+=dx;
	fYo-=dy;
}
void Bullet::Kill()
{
	bAlive=false;
}

float Bullet::GetX()
{
	return fXo;
}
float Bullet::GetY()
{
	return fYo;
}
float Bullet::GetSize()
{
	return fRad;
}
bool Bullet::GetAlive()
{
	return bAlive;
}

void Bullet::SetAlive(bool bTemp)
{
	bAlive=bTemp;
}