//Blake Sullivan - Player header
#ifndef PLAYER_H
#define PLAYER_H
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
//#include "SDL_mixer.h"
#include <math.h>
#include "Bullet.h"
#include "Attributes.h"
extern SDL_Surface *screen;

class Player : public Attributes
{
private:
	struct Position
	{
		float x;
		float y;
	};
	Position fLine[5], fBox[5], fEngL[2];
	Position fLWing[3], fRWing[3], fNose[3];
	Position fUpFlame[6], fDownFlame[3], fLeftFlame[3], fRightFlame[3];
	float fXo, fYo, fExpC1, fExpC2, fExpC3;
	float fCurDeg, fDeg, fSize, fMov, fShieldSize, fModSize; //o = origin
	int iRed, iGreen, iBlue;
	bool bUpFlame, bDownFlame, bRightFlame, bLeftFlame;

	struct collisionXY
	{
		float x;
		float y;
		float size;
	};
	collisionXY pos;

	//Mix_Chunk *phaser;
	//int phaserChannel;
	//Attributes attr;
	//short sXarr[13], sYarr[13], sX[5], sY[5];

public:
	
	Bullet bullets[10];
	//Player();
	~Player();
	void Init(float, float, int, int, int, float);
	void Move(char, float);
	void Rotate(float);
	//void Face(float, float);
	void Draw(float);
	void DrawShip();
	void DrawShield();
	void DrawExplosion(float);
	bool Shoot();

	float SetNewX(float, float);
	float SetNewY(float, float);

	void SetPlayerArr();
	void SetUpFlame(bool);
	void SetDownFlame(bool);
	void SetLeftFlame(bool);
	void SetRightFlame(bool);
	void SetCurDeg(float);
	void SetModSize(float);
	void SetPos(int, int);

	void TurnFlameOff();

	float GetXo();
	float GetYo();
	float GetX1();
	float GetY1();
	float GetfDeg();
	float GetPosX();
	float GetPosY();
	float GetPosSize();
	int GetRed();
	int GetGreen();
	int GetBlue();
};

#endif