//Blake Sullivan - HUD.cpp
#include "HUD.h"

HUD::HUD()
{
	iY1 = 19;
	iY2 = 51;

	fHealthBox[0].x=19;
	fHealthBox[0].y=iY1;
	fHealthBox[1].x=271;
	fHealthBox[1].y=iY2;

	fHealth[0].x=20;
	fHealth[0].y=iY1+1;
	fHealth[1].x=270;
	fHealth[1].y=iY2-1;

	fShieldBox[0].x=529;
	fShieldBox[0].y=iY1;
	fShieldBox[1].x=781;
	fShieldBox[1].y=iY2;

	fShield[0].x=530;
	fShield[0].y=iY1+1;
	fShield[1].x=780;
	fShield[1].y=iY2-1;

	pIcon.Init(300, 35, 0, 255, 255, 0);
	pIcon.SetShieldAlive(false);
	pIcon.SetModSize(0.6);
	pIcon.SetPlayerArr();
	pIcon.SetCurDeg(0);
	pIcon.Rotate(0);
	bIcon.SetColours(0, 255, 255);
}

void HUD::Draw(int iH, int iS, float fT, int pl, int bt, int bm, int iL)
{
	SetupHealth(iH);
	SetupShield(iS);
	DrawHealth();
	DrawShield();
	DrawTimer(fT);
	DrawPlayerLives(pl);
	DrawBullets(bt, bm);
	DrawLevel(iL);
}

void HUD::SetupHealth(int iH)
{
	fHealth[1].x = fHealth[0].x + iH * 5;
}

void HUD::SetupShield(int iS)
{
	fShield[1].x = fShield[0].x + iS * 2.5;
}

void HUD::DrawHealth()
{
	rectangleRGBA(screen, fHealthBox[0].x, fHealthBox[0].y, fHealthBox[1].x, fHealthBox[1].y, 255, 255, 255, 255);
	boxRGBA(screen, fHealth[0].x, fHealth[0].y, fHealth[1].x, fHealth[1].y, 0, 0, 255, 255);
}
void HUD::DrawShield()
{
	rectangleRGBA(screen, fShieldBox[0].x, fShieldBox[0].y, fShieldBox[1].x, fShieldBox[1].y, 255, 255, 255, 255);
	boxRGBA(screen, fShield[0].x, fShield[0].y, fShield[1].x, fShield[1].y, 0, 255, 0, 255);
}

void HUD::DrawTimer(float fTimer)
{
	char cTimer[10];
	sprintf_s(cTimer, "%d", (int)fTimer);
	stringRGBA(screen, 400, 30, cTimer, 255, 255, 255, 255);
	rectangleRGBA(screen, 390, iY1, 430, iY2, 255, 255, 255, 255);
}

void HUD::DrawPlayerLives(int iLives)
{
	char cLives[10];
	pIcon.Draw(0);
	sprintf(cLives, "x%d", (int)iLives);
	stringRGBA(screen, pIcon.GetX1() + 5, 30, cLives, 255, 255, 255, 255);
	rectangleRGBA(screen, 280, iY1, 340, iY2, 255, 255, 255, 255);
}

void HUD::DrawBullets(int iBulType, int iBulMax)
{
	char cBull[10];
	bIcon.SetColours(0, 255, 255);
	bIcon.DrawHUD(iBulType, 485, 35, 5, 2, 7);
	sprintf_s(cBull, "x%d", (int)iBulMax);
	stringRGBA(screen, 502, 30, cBull, 255, 255, 255, 255);
	rectangleRGBA(screen, 465, iY1, 520, iY2, 255, 255, 255, 255);
}

void HUD::DrawCountDown(int iTime)
{
	char cTime[20];
	sprintf_s(cTime, "Countdown: %d", iTime);
	stringRGBA(screen, 350, 200, cTime, 0, 255, 255, 255);
}

void HUD::DrawLevel(int iLevel)
{
	char cLevel[3];
	string sLevel = "Level";
	stringRGBA(screen, 345, iY1 + 5, sLevel.c_str(), 255, 255, 255, 255);
	sprintf_s(cLevel, "%d", iLevel);
	stringRGBA(screen, 360, iY1 + 20, cLevel, 255, 255, 255, 255);
}