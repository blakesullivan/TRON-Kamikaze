//Blake Sullivan - Player
#include "Player.h"

Player::~Player()
{
	//Mix_FreeChunk(phaser);
}

void Player::Init(float sx, float sy, int myR, int myG, int myB, float Mov)
{
	SetupAttr(50, 100, true, 1, 3, 10, 3, 0, true, 100);
	fXo=sx;
	fYo=sy;

	pos.x=fXo;
	pos.y=fYo;
	pos.size=15;
	
	fMov=Mov;
	fCurDeg=0;
	fDeg=0;
	iRed=myR;
	iGreen=myG;
	iBlue=myB;
	fSize=19;
	fModSize = 1;
	fExpC1 = 0;
	fExpC2 = 0;
	fExpC3 = 0;

	SetPlayerArr();
	//phaser = Mix_LoadWAV("zap.wav");
	//phaserChannel = -1;
	//phaserChannel = Mix_PlayChannel(-1, phaser, 0);
}

void Player::SetPlayerArr()
{
	fNose[0].x = fXo;
	fNose[0].y = fYo - (25 * fModSize);
	fNose[1].x = fXo - (5 * fModSize);
	fNose[1].y = fYo - (20 * fModSize);
	fNose[2].x = fXo + (5 * fModSize);
	fNose[2].y = fNose[1].y;

	fLine[0].x = fXo - (5 * fModSize);
	fLine[0].y = fYo + (5 * fModSize);
	fLine[1].x = fLine[0].x;
	fLine[1].y = fYo  -  (20 * fModSize);
	fLine[2].x = fXo + (5 * fModSize);
	fLine[2].y = fLine[1].y;
	fLine[3].x = fLine[2].x;
	fLine[3].y = fLine[0].y;
	fLine[4].x = fLine[0].x;
	fLine[4].y = fLine[0].y;

	fBox[0].x = fXo - (10 * fModSize);
	fBox[0].y = fYo + (5 * fModSize);
	fBox[1].x = fBox[0].x;
	fBox[1].y = fYo + (20 * fModSize);
	fBox[2].x = fXo + (10 * fModSize);
	fBox[2].y = fBox[1].y;
	fBox[3].x = fBox[2].x;
	fBox[3].y = fBox[0].y;
	fBox[4].x = fBox[0].x;
	fBox[4].y = fBox[0].y;

	fLWing[0].x = fXo - (10 * fModSize);
	fLWing[0].y = fYo - (10 * fModSize);
	fLWing[1].x = fLWing[0].x;
	fLWing[1].y = fYo + (15 * fModSize);
	fLWing[2].x = fLWing[0].x - (10 * fModSize);
	fLWing[2].y = fLWing[1].y;

	fRWing[0].x = fXo + (10 * fModSize);
	fRWing[0].y = fYo - (10 * fModSize);
	fRWing[1].x = fRWing[0].x;
	fRWing[1].y = fYo + (15 * fModSize);
	fRWing[2].x = fRWing[0].x + (10 * fModSize);
	fRWing[2].y = fRWing[1].y;

	fEngL[0].x=fXo;
	fEngL[0].y=fLWing[1].y;
	fEngL[1].x=fXo;
	fEngL[1].y=fBox[1].y;

	fUpFlame[0].x = fXo - (10 * fModSize);
	fUpFlame[0].y = fBox[1].y + (6 * fModSize);
	fUpFlame[1].x = fXo - 5 * fModSize;
	fUpFlame[1].y = fBox[1].y + (1 * fModSize);
	fUpFlame[2].x = fXo;
	fUpFlame[2].y = fUpFlame[0].y;

	fUpFlame[3].x = fXo;
	fUpFlame[3].y = fUpFlame[0].y;
	fUpFlame[4].x = fXo + (5 * fModSize);
	fUpFlame[4].y = fUpFlame[1].y;
	fUpFlame[5].x = fXo + (10 * fModSize);
	fUpFlame[5].y = fUpFlame[0].y;

	fDownFlame[0].x = fXo;
	fDownFlame[0].y = fNose[0].y - (1 * fModSize);
	fDownFlame[1].x = fXo - (5 * fModSize);
	fDownFlame[1].y = fDownFlame[0].y - (5 * fModSize);
	fDownFlame[2].x = fXo + (5 * fModSize);
	fDownFlame[2].y = fDownFlame[1].y;

	fLeftFlame[0].x = fLine[2].x + (1 * fModSize);
	fLeftFlame[0].y = fLine[2].y;
	fLeftFlame[1].x = fLeftFlame[0].x + (5 * fModSize);
	fLeftFlame[1].y = fLeftFlame[0].y + (5 * fModSize);
	fLeftFlame[2].x = fLeftFlame[1].x;
	fLeftFlame[2].y = fLeftFlame[0].y - (5 * fModSize);

	fRightFlame[0].x = fLine[0].x - (1 * fModSize);
	fRightFlame[0].y = fLine[1].y;
	fRightFlame[1].x = fRightFlame[0].x - (5 * fModSize);
	fRightFlame[1].y = fRightFlame[0].y + (5 * fModSize);
	fRightFlame[2].x = fRightFlame[1].x;
	fRightFlame[2].y = fRightFlame[0].y - (5 * fModSize);

	fShieldSize = 30;

//	sXarr[0]=fXo;
//	sYarr[0]=fYo-10;
//	sXarr[1]=fXo-5;
//	sYarr[1]=fYo+5;
//	sXarr[2]=fXo-10;
//	sYarr[2]=fYo+10;
//	sXarr[3]=fXo+10;
//	sYarr[3]=fYo+10;
//	sXarr[4]=fXo+5;
//	sYarr[4]=fYo+5;
//
//	sX[0]=fXo;
//	sY[0]=fYo-8;
//	sX[1]=fXo-3;
//	sY[1]=fYo+5;
//	sX[2]=fXo-8;
//	sY[2]=fYo+9;
//	sX[3]=fXo+8;
//	sY[3]=fYo+9;
//	sX[4]=fXo+3;
//	sY[4]=fYo+5;
//
//	/*sXarr[0]=fXo;
//	sYarr[0]=fYo-20;
//	sXarr[1]=fXo-5;
//	sYarr[1]=fYo-18;
//	sXarr[12]=fXo+5;
//	sYarr[12]=fYo-18;
//	sXarr[2]=fXo-5;
//	sYarr[2]=fYo-10;
//	sXarr[11]=fXo+5;
//	sYarr[11]=fYo-10;
//	sXarr[3]=fXo-15;
//	sYarr[3]=fYo-5;
//	sXarr[10]=fXo+15;
//	sYarr[10]=fYo-5;
//	sXarr[4]=fXo-5;
//	sYarr[4]=fYo-5;
//	sXarr[9]=fXo+5;
//	sYarr[9]=fYo-5;
//	sXarr[5]=fXo-5;
//	sYarr[5]=fYo+15;
//	sXarr[8]=fXo+5;
//	sYarr[8]=fYo+15;
//	sXarr[6]=fXo-10;
//	sYarr[6]=fYo+20;
//	sXarr[7]=fXo+10;
//	sYarr[7]=fYo+20;*/
}

void Player::Rotate(float fTemp)
{
	float fXNew = 0, fYNew = 0;
	//Sets variables around the points
	fCurDeg += fTemp;
	fDeg = fCurDeg;
	fDeg = (90*M_PI/180)-fDeg;
	
	SetPlayerArr();
	
	//Roatates here using a formula
	for (int i=0; i<5;i++)
	{
		fXNew = SetNewX(fLine[i].x, fLine[i].y); fYNew = SetNewY(fLine[i].x, fLine[i].y);
		fLine[i].x = fXNew; fLine[i].y = fYNew;

		fXNew = SetNewX(fBox[i].x, fBox[i].y); fYNew = SetNewY(fBox[i].x, fBox[i].y);
		fBox[i].x = fXNew; fBox[i].y = fYNew;

		if (i<3)
		{
			fXNew = SetNewX(fNose[i].x, fNose[i].y); fYNew = SetNewY(fNose[i].x, fNose[i].y);
			fNose[i].x = fXNew; fNose[i].y = fYNew;

			fXNew = SetNewX(fLWing[i].x, fLWing[i].y); fYNew = SetNewY(fLWing[i].x, fLWing[i].y);
			fLWing[i].x = fXNew; fLWing[i].y = fYNew;

			fXNew = SetNewX(fRWing[i].x, fRWing[i].y); fYNew = SetNewY(fRWing[i].x, fRWing[i].y);
			fRWing[i].x = fXNew; fRWing[i].y = fYNew;

			if (i<2)
			{
				fXNew = SetNewX(fEngL[i].x, fEngL[i].y); fYNew = SetNewY(fEngL[i].x, fEngL[i].y);
				fEngL[i].x = fXNew; fEngL[i].y = fYNew;
			}

			fXNew = SetNewX(fUpFlame[i].x, fUpFlame[i].y); fYNew = SetNewY(fUpFlame[i].x, fUpFlame[i].y);
			fUpFlame[i].x = fXNew; fUpFlame[i].y = fYNew;
			fXNew = SetNewX(fUpFlame[3+i].x, fUpFlame[3+i].y); fYNew = SetNewY(fUpFlame[3+i].x, fUpFlame[3+i].y);
			fUpFlame[3+i].x = fXNew; fUpFlame[3+i].y = fYNew;
	
			fXNew = SetNewX(fDownFlame[i].x, fDownFlame[i].y); fYNew = SetNewY(fDownFlame[i].x, fDownFlame[i].y);
			fDownFlame[i].x = fXNew; fDownFlame[i].y = fYNew;

			fXNew = SetNewX(fLeftFlame[i].x, fLeftFlame[i].y); fYNew = SetNewY(fLeftFlame[i].x, fLeftFlame[i].y);
			fLeftFlame[i].x = fXNew; fLeftFlame[i].y = fYNew;

			fXNew = SetNewX(fRightFlame[i].x, fRightFlame[i].y); fYNew = SetNewY(fRightFlame[i].x, fRightFlame[i].y);
			fRightFlame[i].x = fXNew; fRightFlame[i].y = fYNew;
		}
	}
}

float Player::SetNewX(float pX, float pY)
{
	float fTemp = 0;
	fTemp = fXo + ((pX - fXo) * cos(fDeg)) - ((pY - fYo) * sin(fDeg));
	return fTemp;
}

float Player::SetNewY(float pX, float pY)
{
	float fTemp = 0;
	fTemp = fYo + ((pY - fYo) * cos(fDeg)) + ((pX - fXo) * sin(fDeg));
	return fTemp;
}

void Player::Move(char cMove, float fDeltaTime)
{
	float dx, dy, fTurnDeg = 2.5;
	switch (cMove)
	{
	case 'u':
		//fYo-=fMov;
		dx=(fMov * fDeltaTime)*sin(fDeg);
		dy=(fMov * fDeltaTime)*cos(fDeg);
		fXo+=dx;
		fYo-=dy;
		for(int i=0; i<5;i++)
		{
			fLine[i].x+=dx;
			fLine[i].y-=dy;
			fBox[i].x+=dx;
			fBox[i].y-=dy;
			if (i<3)
			{
				fNose[i].x+=dx;
				fNose[i].y-=dy;
				fLWing[i].x+=dx;
				fLWing[i].y-=dy;
				fRWing[i].x+=dx;
				fRWing[i].y-=dy;

				if (i<2)
				{
					fEngL[i].x+=dx;
					fEngL[i].y-=dy;
				}

				fUpFlame[i].x+=dx;
				fUpFlame[i].y-=dy;
				fUpFlame[3+i].x+=dx;
				fUpFlame[3+i].y-=dy;
				fDownFlame[i].x+=dx;
				fDownFlame[i].y-=dy;
				fLeftFlame[i].x+=dx;
				fLeftFlame[i].y-=dy;
				fRightFlame[i].x+=dx;
				fRightFlame[i].y-=dy;
			}
			/*sXarr[i]+=dx;
			sYarr[i]-=dy;
			sX[i]+=dx;
			sY[i]-=dy;*/
		}
	break;
	case 'v':
		//fYo+=fMov;
		dx=((fMov / 2) * fDeltaTime)*sin(fDeg);
		dy=((fMov / 2) * fDeltaTime)*cos(fDeg);
		fXo-=dx;
		fYo+=dy;
		for(int i=0; i<5;i++)
		{
			fLine[i].x-=dx;
			fLine[i].y+=dy;
			fBox[i].x-=dx;
			fBox[i].y+=dy;
			if (i<3)
			{
				fNose[i].x-=dx;
				fNose[i].y+=dy;
				fLWing[i].x-=dx;
				fLWing[i].y+=dy;
				fRWing[i].x-=dx;
				fRWing[i].y+=dy;

				if (i<2)
				{
					fEngL[i].x-=dx;
					fEngL[i].y+=dy;
				}

				fUpFlame[i].x-=dx;
				fUpFlame[i].y+=dy;
				fUpFlame[3+i].x-=dx;
				fUpFlame[3+i].y+=dy;
				fDownFlame[i].x-=dx;
				fDownFlame[i].y+=dy;
				fLeftFlame[i].x-=dx;
				fLeftFlame[i].y+=dy;
				fRightFlame[i].x-=dx;
				fRightFlame[i].y+=dy;
			}
		}
	break;
	case 'l':
		//Deg+=0.05;
		Rotate(fTurnDeg*fDeltaTime);
		//fXo-=fMov;
	break;
	case 'r':
		//Deg-=0.05;
		Rotate(-(fTurnDeg*fDeltaTime));
		//fXo+=fMov;
	break;
	}

	pos.x = fXo;
	pos.y = fYo;
}

void Player::Draw(float fDeltaTime)
{
	if (GetExplode() == false)
	{
		DrawShip();
		DrawShield();
	}
	else
		{DrawExplosion(fDeltaTime);}

	//filledEllipseRGBA(screen, fX1, fY1, 5, 5, iBlue, iGreen, iRed, 255);
	//trigonRGBA(screen, fX1, fY1, fX2, fY2, fX3, fY3, iRed, iGreen, iBlue, 255);
	//circleRGBA(screen, pos.x, pos.y, pos.size, 255, 255, 255, 255);
}

void Player::DrawShip()
{
	for (int i=0; i<4; i++)
	{
		lineRGBA(screen, fLine[i].x, fLine[i].y, fLine[i+1].x, fLine[i+1].y, iRed, iGreen, iBlue, 255);
		lineRGBA(screen, fBox[i].x, fBox[i].y, fBox[i+1].x, fBox[i+1].y, iRed, iGreen, iBlue, 255);
	}
	trigonRGBA(screen, fNose[0].x, fNose[0].y, fNose[1].x, fNose[1].y, fNose[2].x, fNose[2].y, iRed, iGreen, iBlue, 255);
	trigonRGBA(screen, fLWing[0].x, fLWing[0].y, fLWing[1].x, fLWing[1].y, fLWing[2].x, fLWing[2].y, iRed, iGreen, iBlue, 255);
	trigonRGBA(screen, fRWing[0].x, fRWing[0].y, fRWing[1].x, fRWing[1].y, fRWing[2].x, fRWing[2].y, iRed, iGreen, iBlue, 255);
	lineRGBA(screen, fLWing[1].x, fLWing[1].y, fRWing[1].x, fRWing[1].y, iRed, iGreen, iBlue, 255);
	lineRGBA(screen, fEngL[0].x, fEngL[0].y, fEngL[1].x, fEngL[1].y, iRed, iGreen, iBlue, 255);
	if (true==bUpFlame)
	{
		filledTrigonRGBA(screen, fUpFlame[0].x, fUpFlame[0].y, fUpFlame[1].x, fUpFlame[1].y, fUpFlame[2].x, fUpFlame[2].y, 255, 255, 255, 255);
		filledTrigonRGBA(screen, fUpFlame[3].x, fUpFlame[3].y, fUpFlame[4].x, fUpFlame[4].y, fUpFlame[5].x, fUpFlame[5].y, 255, 255, 255, 255);
	}
	if (true==bDownFlame)
	{filledTrigonRGBA(screen, fDownFlame[0].x, fDownFlame[0].y, fDownFlame[1].x, fDownFlame[1].y, fDownFlame[2].x, fDownFlame[2].y, 255, 255, 255, 255);}
	if (true==bLeftFlame)
	{filledTrigonRGBA(screen, fLeftFlame[0].x, fLeftFlame[0].y, fLeftFlame[1].x, fLeftFlame[1].y, fLeftFlame[2].x, fLeftFlame[2].y, 255, 255, 255, 255);}
	if (true==bRightFlame)
	{filledTrigonRGBA(screen, fRightFlame[0].x, fRightFlame[0].y, fRightFlame[1].x, fRightFlame[1].y, fRightFlame[2].x, fRightFlame[2].y, 255, 255, 255, 255);}
}

void Player::DrawShield()
{
	if (true==GetShieldAlive())
	{
		circleRGBA(screen, pos.x, pos.y, fShieldSize, 0, 255, 0, 255);
		if (GetShield()>=40)
		{
			circleRGBA(screen, pos.x, pos.y, fShieldSize+1, 0, 255, 0, 255);
		}
		if (GetShield()>=70)
		{
			circleRGBA(screen, pos.x, pos.y, fShieldSize+2, 0, 255, 0, 255);
		}
	}
}

void Player::DrawExplosion(float fTD)
{
	float fDrawSize = (pos.size * 2);
	float fIncr = 75;
	fIncr *= fTD;

	filledCircleRGBA(screen, pos.x, pos.y, fExpC1, 255, 255, 255, 255);
	if (fExpC1 <= fDrawSize)
		{fExpC1+=fIncr;}

	if (fExpC1 >= pos.size)
	{
		filledCircleRGBA(screen, pos.x, pos.y, fExpC2, 0, 255, 255, 255);
		if (fExpC2 <= fDrawSize)
			{fExpC2+=fIncr;}
	}

	if (fExpC2 >= pos.size)
	{
		filledCircleRGBA(screen, pos.x, pos.y, fExpC3, 55, 200, 200, 255);
		if (fExpC3 <= fDrawSize)
			{fExpC3+=fIncr;}
	}
	if (fExpC3 >= fDrawSize)
	{
		SetExplode(false);
		fExpC1 = 0; fExpC2 = 0; fExpC3 = 0;
	}
}

bool Player::Shoot()
{
	for (int i = 0; i < GetBulletMax(); i++)
	{
		if (false == bullets[i].GetAlive())
		{
			bullets[i].Create(GetX1(), GetY1(), GetfDeg(), 200);
			//phaserChannel = Mix_PlayChannel(-1, phaser, 0);
			return true;
		}
	}
	return false;
}
void Player::SetUpFlame(bool bTemp)
{
	bUpFlame=bTemp;
}
void Player::SetDownFlame(bool bTemp)
{
	bDownFlame=bTemp;
}
void Player::SetLeftFlame(bool bTemp)
{
	bLeftFlame=bTemp;
}
void Player::SetRightFlame(bool bTemp)
{
	bRightFlame=bTemp;
}

void Player::SetCurDeg(float fTemp)
{
	fCurDeg = fTemp;
}

void Player::SetModSize(float fTemp)
{
	fModSize = fTemp;
}

void Player::SetPos(int iX, int iY)
{
	fXo = iX;
	fYo = iY;
	pos.x = fXo;
	pos.y = fYo;
	SetPlayerArr();
	Rotate(0);
}

float Player::GetXo()
{
	return fXo;
}

float Player::GetYo()
{
	return fYo;
}

float Player::GetX1()
{
	return fNose[0].x;
}
float Player::GetY1()
{
	return fNose[0].y;
}
float Player::GetfDeg()
{
	return fDeg;
}

float Player::GetPosX()
{
	return pos.x;
}
float Player::GetPosY()
{
	return pos.y;
}

float Player::GetPosSize()
{
	if (GetShieldAlive()==true)
		{return fShieldSize;}
	else
		{return pos.size;}
}

int Player::GetRed()
{
	return iRed;
}
int Player::GetGreen()
{
	return iGreen;
}
int Player::GetBlue()
{
	return iBlue;
}

void Player::TurnFlameOff()
{
	SetUpFlame(false);
	SetDownFlame(false);
	SetLeftFlame(false);
	SetRightFlame(false);
}