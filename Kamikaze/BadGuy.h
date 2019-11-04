//Badguy.h
#ifndef BadGuy_H
#define BadGuy_H
#include "SDL.h"
#include "SDL_gfXPrimitives.h" 
#include <math.h>
#include "Bullet.h"
#include "Attributes.h"
#include <string>
using namespace std;
extern SDL_Surface *screen;

class BadGuy : public Attributes
{
private:
	struct Position
	{
		float x;
		float y;
	};
	Position fBod[5], fHead[5], fCLBod[7], fCRBod[7], fCLowBod[5], fCMidBod[2], fHipS[2], fShoot;
	Position fLWing[6], fRWing[6], fLSideS[2], fRSideS[2], fLSmallSideS[2], fRSmallSideS[2], fLBigS[2], fRBigS[2], fMidS[2];
	float fXo, fYo, fRad, Deg, fDeg;
	//float fX1, fX2, fX3, fY1, fY2, fY3;
	float fMov, fShootTimer, fExpC1, fExpC2, fExpC3;
	char cType;
	int iMaxBulletTime, iRed, iGreen, iBlue;

	struct collisionXY
	{
		float x;
		float y;
		float size;
	};
	collisionXY pos;

public:
	BadGuy();

	Bullet bullets[10];
	//Attributes attr;
	void Init(float, float, char);
	void Face(float, float);
	void FaceS();
	void FaceB();

	void Move(float);
	void Draw(float);
	void DrawTypeS();
	void DrawTypeB();
	void DrawExplosion(float);
	void DrawLabel(int);

	bool CalcShoot(float);
	void Shoot();
	
	void SetShape();
	void SetShapeB();
	void SetShapeS();
	float SetNewX(float, float);
	float SetNewY(float, float);
	void SetAttr(char);
	void SetColours(int, int, int);
	
	float GetPosX();
	float GetPosY();
	float GetPosSize();
	char GetType();
	float GetExpC3();
	int GetRed();
	int GetGreen();
	int GetBlue();
};

#endif