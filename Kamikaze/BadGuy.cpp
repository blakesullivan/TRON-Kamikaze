//Bad Guy
#include "BadGuy.h"
BadGuy::BadGuy()//: fMov(1),fRad(10)
{
	fXo=0;
	fYo=0;
	pos.x=0;
	pos.y=0;
	pos.size=0;
	bAlive=true;
	Deg=90;
	fDeg=0;
	iMaxBulletTime=10;
	cType='s';
	fExpC1 = 0;
	fExpC2 = 0;
	fExpC3 = 0;

	//SetShape();
}

void BadGuy::Init(float fXs, float fYs, char typeS)
{
	fXo=fXs;
	fYo=fYs;
	bAlive=true;

	SetAttr(typeS);
	if (typeS == 'l') {typeS = 'b';}
	if (typeS == 'c') {typeS = 's';}
	
	if (typeS == 's' || typeS == 'b')
	{cType = typeS;}
	else
	{cType = 's';}

	fShootTimer= rand() % ((iMaxBulletTime*2) + 1);

	for (int i=0; i<7; i++)
	{
		fCLBod[i].x=0; fCLBod[i].y=0;
		fCRBod[i].x=0; fCRBod[i].y=0;

		if (i < 6)
		{
			fLWing[i].x=0; fLWing[i].y=0;
			fRWing[i].x=0; fRWing[i].y=0;
		}
		if (i<5)
		{
			fBod[i].x=0; fBod[i].y=0;
			fHead[i].x=0; fHead[i].y=0;
			fCLowBod[i].x=0; fCLowBod[i].y=0;
		}
		if (i < 2)
		{
			fCMidBod[i].x=0; fCMidBod[i].y=0;
			fHipS[i].x=0; fHipS[i].y=0;
			fLSideS[i].x=0; fLSideS[i].y=0;
			fRSideS[i].x=0; fRSideS[i].y=0;
			fLSmallSideS[i].x=0; fLSmallSideS[i].y=0;
			fRSmallSideS[i].x=0; fRSmallSideS[i].y=0;
			fLBigS[i].x=0; fLBigS[i].y=0;
			fRBigS[i].x=0; fRBigS[i].y=0;
			fMidS[i].x=0; fMidS[i].y=0;
		}
	}
	fShoot.x=0; fShoot.y=0;
	
	fExpC1 = 0;
	fExpC2 = 0;
	fExpC3 = 0;

	SetShape();
	//square
	/*pos.x=iXo-10;
	pos.y=iYo-10;
	pos.size=20;*/

	//circle
	pos.x=fXo;
	pos.y=fYo+1;
	//pos.size=15;
}

void BadGuy::SetAttr(char cTemp)
{
	switch (cTemp)
	{
	case 'b':
		SetupAttr(50, 0, false, 1, 2, 20, 1, 200, true, 100);
		SetColours(255, 0, 0);
		fMov=5;
	break;
	case 'l':
		SetupAttr(100, 0, false, 1, 3, 30, 1, 400, true, 150);
		SetColours(255, 150, 0);
		fMov=5;
	break;
	case 'c':
		SetupAttr(30, 0, false, 1, 2, 20, 1, 100, true, 75);
		SetColours(255, 150, 0);
		fMov=15;
	break;
	case 's':
		SetupAttr(10, 0, false, 1, 1, 10, 1, 50, true, 50);
		SetColours(255, 0, 0);
		fMov=10;
	break;
	default: //'s'
		SetAttr('s');
	}
}

void BadGuy::SetShape()
{		
	if (cType=='b')
		{SetShapeB();}
	else
		{SetShapeS();}
}

void BadGuy::SetShapeS()
{
	fBod[0].x=fXo-15; 
	fBod[0].y=fYo+5;
	fBod[1].x=fBod[0].x; 
	fBod[1].y=fYo+15; 
	fBod[2].x=fXo+15; 
	fBod[2].y=fBod[1].y;
	fBod[3].x=fBod[2].x;
	fBod[3].y=fBod[0].y;
	fBod[4].x=fBod[0].x;
	fBod[4].y=fBod[0].y;

	fHead[0].x=fXo-3; 
	fHead[0].y=fYo;
	fHead[1].x=fHead[0].x; 
	fHead[1].y=fYo+15; 
	fHead[2].x=fXo+3; 
	fHead[2].y=fHead[1].y; 
	fHead[3].x=fHead[2].x; 
	fHead[3].y=fHead[0].y; 
	fHead[4].x=fHead[0].x; 
	fHead[4].y=fHead[0].y; 

	fLWing[0].x=fXo-5; 
	fLWing[0].y=fYo-20;
	fLWing[1].x=fXo-10; 
	fLWing[1].y=fYo+5;
	fLWing[2].x=fXo-15; 
	fLWing[2].y=fLWing[1].y;

	fRWing[0].x=fXo+5; 
	fRWing[0].y=fYo-20;
	fRWing[1].x=fXo+10; 
	fRWing[1].y=fYo+5;
	fRWing[2].x=fXo+15; 
	fRWing[2].y=fRWing[1].y;

	fShoot.x = fXo;
	fShoot.y = fLWing[0].y;

	pos.size = 15;
}

void BadGuy::SetShapeB()
{
	fHead[0].x=fXo-15;
	fHead[0].y=fYo-22;
	fHead[1].x=fXo-3;
	fHead[1].y=fHead[0].y-8;
	fHead[2].x=fXo+3;
	fHead[2].y=fHead[1].y;
	fHead[3].x=fXo+15;
	fHead[3].y=fHead[0].y;
	fHead[4].x=fHead[0].x; 
	fHead[4].y=fHead[0].y;

	fLBigS[0].x=fXo-40;
	fLBigS[0].y=fYo-20;
	fLBigS[1].x=fXo-1;
	fLBigS[1].y=fYo-18;
	fRBigS[0].x=fXo+40;
	fRBigS[0].y=fYo-20;
	fRBigS[1].x=fXo+1;
	fRBigS[1].y=fYo-18;

	fBod[0].x=fXo-8;
	fBod[0].y=fYo-16;
	fBod[1].x=fXo+8;
	fBod[1].y=fBod[0].y;
	fBod[2].x=fXo+5;
	fBod[2].y=fYo-13;
	fBod[3].x=fXo-5;
	fBod[3].y=fBod[2].y;
	fBod[4].x=fBod[0].x;
	fBod[4].y=fBod[0].y;

	fCLBod[0].x=fXo-1;
	fCLBod[0].y=fYo-11;
	fCLBod[1].x=fXo-6;
	fCLBod[1].y=fCLBod[0].y;
	fCLBod[2].x=fXo-10;
	fCLBod[2].y=fYo-16;
	fCLBod[3].x=fXo-20;
	fCLBod[3].y=fCLBod[2].y;
	fCLBod[4].x=fXo-15;
	fCLBod[4].y=fYo-8;
	fCLBod[5].x=fCLBod[0].x;
	fCLBod[5].y=fCLBod[4].y;
	fCLBod[6].x=fCLBod[0].x;
	fCLBod[6].y=fCLBod[0].y;

	fCRBod[0].x=fXo+1;
	fCRBod[0].y=fYo-11;
	fCRBod[1].x=fXo+6;
	fCRBod[1].y=fCRBod[0].y;
	fCRBod[2].x=fXo+10;
	fCRBod[2].y=fYo-16;
	fCRBod[3].x=fXo+20;
	fCRBod[3].y=fCRBod[2].y;
	fCRBod[4].x=fXo+15;
	fCRBod[4].y=fYo-8;
	fCRBod[5].x=fCRBod[0].x;
	fCRBod[5].y=fCRBod[4].y;
	fCRBod[6].x=fCRBod[0].x;
	fCRBod[6].y=fCRBod[0].y;

	fLSideS[0].x=fXo-35;
	fLSideS[0].y=fYo-16;
	fLSideS[1].x=fXo-30;
	fLSideS[1].y=fYo-4;
	fRSideS[0].x=fXo+35;
	fRSideS[0].y=fYo-16;
	fRSideS[1].x=fXo+30;
	fRSideS[1].y=fYo-4;

	fLSmallSideS[0].x=fXo-27;
	fLSmallSideS[0].y=fYo-13;
	fLSmallSideS[1].x=fXo-22;
	fLSmallSideS[1].y=fYo-11;
	fRSmallSideS[0].x=fXo+27;
	fRSmallSideS[0].y=fYo-13;
	fRSmallSideS[1].x=fXo+22;
	fRSmallSideS[1].y=fYo-11;

	fMidS[0].x=fXo-5;
	fMidS[0].y=fYo-6;
	fMidS[1].x=fXo+5;
	fMidS[1].y=fYo-4;

	fHipS[0].x=fXo-35;
	fHipS[0].y=fYo-2;
	fHipS[1].x=fXo+35;
	fHipS[1].y=fYo;

	fCLowBod[0].x=fXo-5;
	fCLowBod[0].y=fYo+2;
	fCLowBod[1].x=fXo-3;
	fCLowBod[1].y=fYo+4;
	fCLowBod[2].x=fXo+3;
	fCLowBod[2].y=fCLowBod[1].y;
	fCLowBod[3].x=fXo+5;
	fCLowBod[3].y=fCLowBod[0].y;
	fCLowBod[4].x=fCLowBod[0].x;
	fCLowBod[4].y=fCLowBod[0].y;
	
	fLWing[0].x=fXo-35;
	fLWing[0].y=fYo+2;
	fLWing[1].x=fLWing[0].x; 
	fLWing[1].y=fYo+30;
	fLWing[2].x=fXo-20; 
	fLWing[2].y=fLWing[1].y;
	fLWing[3].x=fXo-30;
	fLWing[3].y=fYo+25;
	fLWing[4].x=fLWing[3].x;
	fLWing[4].y=fLWing[0].y;
	fLWing[5].x=fLWing[0].x;
	fLWing[5].y=fLWing[0].y;

	fRWing[0].x=fXo+35;
	fRWing[0].y=fYo+2;
	fRWing[1].x=fRWing[0].x; 
	fRWing[1].y=fYo+30;
	fRWing[2].x=fXo+20; 
	fRWing[2].y=fRWing[1].y;
	fRWing[3].x=fXo+30;
	fRWing[3].y=fYo+25;
	fRWing[4].x=fRWing[3].x;
	fRWing[4].y=fRWing[0].y;
	fRWing[5].x=fRWing[0].x;
	fRWing[5].y=fRWing[0].y;

	fShoot.x = fXo;
	fShoot.y = fLWing[2].y;

	pos.size = 30;
}

void BadGuy::Draw(float fDT)
{
	if (GetExplode()==false)
	{
		switch (cType)
		{
		case 's':
			DrawTypeS();
		break;
		case 'b':
			DrawTypeB();
		break;
		default:
			DrawTypeS();
		}
	}
	else
	{
		DrawExplosion(fDT);
	}
	//Collision Circle
	//ellipseRGBA(screen, pos.x, pos.y, pos.size, pos.size, 255, 255, 255, 255);
}

void BadGuy::DrawTypeS()
{
	for (int i=0; i<4; i++)
	{
		lineRGBA(screen, fBod[i].x, fBod[i].y, fBod[i+1].x, fBod[i+1].y, iRed, iGreen, iBlue, 255);
		lineRGBA(screen, fHead[i].x, fHead[i].y, fHead[i+1].x, fHead[i+1].y, iRed, iGreen, iBlue, 255);
	}
	trigonRGBA(screen, fLWing[0].x, fLWing[0].y, fLWing[1].x, fLWing[1].y, fLWing[2].x, fLWing[2].y, iRed, iGreen, iBlue, 255);
	trigonRGBA(screen, fRWing[0].x, fRWing[0].y, fRWing[1].x, fRWing[1].y, fRWing[2].x, fRWing[2].y, iRed, iGreen, iBlue, 255);
}

void BadGuy::DrawTypeB()
{
	for (int i=0; i<6; i++)
	{
		if (i<4)
		{
			lineRGBA(screen, fBod[i].x, fBod[i].y, fBod[i+1].x, fBod[i+1].y, iRed, iGreen, iBlue, 255);
			lineRGBA(screen, fHead[i].x, fHead[i].y, fHead[i+1].x, fHead[i+1].y, iRed, iGreen, iBlue, 255);
			lineRGBA(screen, fCLowBod[i].x, fCLowBod[i].y, fCLowBod[i+1].x, fCLowBod[i+1].y, iRed, iGreen, iBlue, 255);
		}
		if (i<5)
		{
			lineRGBA(screen, fLWing[i].x, fLWing[i].y, fLWing[i+1].x, fLWing[i+1].y, iRed, iGreen, iBlue, 255);
			lineRGBA(screen, fRWing[i].x, fRWing[i].y, fRWing[i+1].x, fRWing[i+1].y, iRed, iGreen, iBlue, 255);
		}
		lineRGBA(screen, fCLBod[i].x, fCLBod[i].y, fCLBod[i+1].x, fCLBod[i+1].y, iRed, iGreen, iBlue, 255);
		lineRGBA(screen, fCRBod[i].x, fCRBod[i].y, fCRBod[i+1].x, fCRBod[i+1].y, iRed, iGreen, iBlue, 255);
	}
	rectangleRGBA(screen, fLBigS[0].x, fLBigS[0].y, fLBigS[1].x, fLBigS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fRBigS[0].x, fRBigS[0].y, fRBigS[1].x, fRBigS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fHipS[0].x, fHipS[0].y, fHipS[1].x, fHipS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fMidS[0].x, fMidS[0].y, fMidS[1].x, fMidS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fLSideS[0].x, fLSideS[0].y, fLSideS[1].x, fLSideS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fRSideS[0].x, fRSideS[0].y, fRSideS[1].x, fRSideS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fLSmallSideS[0].x, fLSmallSideS[0].y, fLSmallSideS[1].x, fLSmallSideS[1].y, iRed, iGreen, iBlue, 255);
	rectangleRGBA(screen, fRSmallSideS[0].x, fRSmallSideS[0].y, fRSmallSideS[1].x, fRSmallSideS[1].y, iRed, iGreen, iBlue, 255);
	
	//trigonRGBA(screen, fLWing[0].x, fLWing[0].y, fLWing[1].x, fLWing[1].y, fLWing[2].x, fLWing[2].y, 255, 0, 0, 255);
	//trigonRGBA(screen, fRWing[0].x, fRWing[0].y, fRWing[1].x, fRWing[1].y, fRWing[2].x, fRWing[2].y, 255, 0, 0, 255);
}

void BadGuy::DrawExplosion(float fTD)
{
	float fDrawSize = (pos.size * 2);
	float fIncr = 75;
	fIncr *= fTD;

	filledCircleRGBA(screen, pos.x, pos.y, fExpC1, 255, 255, 255, 255);
	if (fExpC1 <= fDrawSize)
		{fExpC1+=fIncr;}

	if (fExpC1 >= pos.size)
	{
		filledCircleRGBA(screen, pos.x, pos.y, fExpC2, iRed, iGreen, iBlue, 255);
		if (fExpC2 <= fDrawSize)
			{fExpC2+=fIncr;}
	}

	if (fExpC2 >= pos.size)
	{
		filledCircleRGBA(screen, pos.x, pos.y, fExpC3, 200, 55, 55, 255);
		if (fExpC3 <= fDrawSize)
			{fExpC3+=fIncr;}
	}
	if (fExpC3 >= fDrawSize)
		{SetExplode(false);}
}

float BadGuy::GetExpC3()
{
	return fExpC3;
}

void BadGuy::DrawLabel(int iTemp)
{
	string sTemp;
	char chars[8] = {'0', '0', '0', '0', '0', '0', '0', '0'};

	sTemp = _itoa(iTemp, chars, 10);

	stringRGBA(screen, fShoot.x, fShoot.y, sTemp.c_str(), 255, 255, 255, 255);
}

void BadGuy::Face(float px, float py)
{
	//Sets variables around the points
	Deg = atan((px-fXo)/(fYo-py))*180/M_PI;
	//Deg = atan2((px-iXo),(py-iYo))*180/M_PI;
	
	if (py > fYo)
	{
		Deg+=180;
	}
	fDeg = Deg;
	fDeg = (fDeg*M_PI/180);

	SetShape();

	switch (cType)
	{
	case 's':
		FaceS();
	break;
	case 'b':
		FaceB();
	break;
	default:
		FaceS();
	}
	pos.x=fXo;
	pos.y=fYo;
}

void BadGuy::FaceB()
{
	float fXNew = 0, fYNew = 0;
	//Roatates here using a formula
}

void BadGuy::FaceS()
{
	float fXNew = 0, fYNew = 0;
	//Roatates here using a formula
	fXNew = SetNewX(fShoot.x, fShoot.y); fYNew = SetNewY(fShoot.x, fShoot.y);
	fShoot.x = fXNew; fShoot.y = fYNew;
	for (int i = 0; i<5; i++)
	{
		fXNew = SetNewX(fBod[i].x, fBod[i].y); fYNew = SetNewY(fBod[i].x, fBod[i].y);
		fBod[i].x = fXNew; fBod[i].y = fYNew;

		fXNew = SetNewX(fHead[i].x, fHead[i].y); fYNew = SetNewY(fHead[i].x, fHead[i].y);
		fHead[i].x = fXNew; fHead[i].y = fYNew;

		if (i<3)
		{
			fXNew = SetNewX(fLWing[i].x, fLWing[i].y); fYNew = SetNewY(fLWing[i].x, fLWing[i].y);
			fLWing[i].x = fXNew; fLWing[i].y = fYNew;

			fXNew = SetNewX(fRWing[i].x, fRWing[i].y); fYNew = SetNewY(fRWing[i].x, fRWing[i].y);
			fRWing[i].x = fXNew; fRWing[i].y = fYNew;
		}
	}
}

bool BadGuy::CalcShoot(float fDeltaTime)
{
	if (fShootTimer<=0)
	{
		fShootTimer = rand() % iMaxBulletTime + 1;
		Shoot();
		return true;
	}
	else
	{
		fShootTimer -= fDeltaTime;
		return false;
	}
}

void BadGuy::Shoot()
{
	for (int i = 0; i < GetBulletMax(); i++)
	{
		if (bullets[i].GetAlive()==false)
		{
			bullets[i].Create(fShoot.x, fShoot.y, fDeg, 200);
			break;
		}
	}
}

float BadGuy::SetNewX(float pX, float pY)
{
	float fTemp = 0;
	fTemp = fXo + ((pX - fXo) * cos(fDeg)) - ((pY - fYo) * sin(fDeg));
	return fTemp;
}

float BadGuy::SetNewY(float pX, float pY)
{
	float fTemp = 0;
	fTemp = fYo + ((pY - fYo) * cos(fDeg)) + ((pX - fXo) * sin(fDeg));
	return fTemp;
}

void BadGuy::Move(float fDeltaTime)
{
	float dx = 0, dy = 0;
	dx = (fMov * fDeltaTime) * sin(fDeg);
	dy = (fMov * fDeltaTime) * cos(fDeg);
	fXo += dx;
	fYo -= dy;

	pos.x = fXo;
	pos.y = fYo;
	//pos.size=9;
}

float BadGuy::GetPosX()
{
	return pos.x;
}
float BadGuy::GetPosY()
{
	return pos.y;
}
float BadGuy::GetPosSize()
{
	return pos.size;
}

char BadGuy::GetType()
{
	return cType;
}

void BadGuy::SetColours(int r, int g, int b)
{
	iRed = r;
	iGreen = g;
	iBlue = b;
}
int BadGuy::GetRed()
{
	return iRed;
}
int BadGuy::GetGreen()
{
	return iGreen;
}
int BadGuy::GetBlue()
{
	return iBlue;
}