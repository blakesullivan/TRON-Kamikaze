//Blake Sullivan - HUD.h
#ifndef HUD_H
#define HUD_H
#include "SDL.h"   /* All SDL App's need this */
#include "SDL_gfxPrimitives.h"
#include "Player.h"
#include "Bullet.h"
#include <string>
using namespace std;
extern SDL_Surface *screen;

class HUD
{
private:
	struct Position
	{
		float x;
		float y;
	};
	Position fHealthBox[2], fHealth[2], fShieldBox[2], fShield[2];
	int iY1, iY2;
	Player pIcon;
	Bullet bIcon;

public:
	HUD();

	void SetupHealth(int);
	void SetupShield(int);

	void Draw(int, int, float, int, int, int, int);
	void DrawHealth();
	void DrawShield();
	void DrawTimer(float);
	void DrawPlayerLives(int);
	void DrawBullets(int, int);
	void DrawCountDown(int);
	void DrawLevel(int);
};
#endif