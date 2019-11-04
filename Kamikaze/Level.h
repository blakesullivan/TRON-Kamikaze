//Blake Sullivan - Level.h
#ifndef LEVEL_H
#define LEVEL_H

#include "SDL_mixer.h"
#include "Player.h"
#include "BadGuy.h"
#include "HUD.h"
#include "Pickup.h"
#include <string>
#include <iostream>
using namespace std;

extern SDL_Surface *screen;

#define numBad 20
#define maxBull 10

class Level
{
private:
	Player player;
	BadGuy bG[numBad];
	HUD hud;
	Pickup pU[maxBull];
	bool keysHeld[500]; //323
	int iMaxBGs, iBGLeft, iGameLevel;
	bool bSoundOn;
	//Mix_Music *bgm;
	Mix_Chunk *phaser;
	Mix_Chunk *explosion;
	Mix_Chunk *pickup;
	int playerChannel, bGChannel;
	float fTimer;

public:
	Level(SDL_Event &, int, Player &, bool&, float, bool);
	~Level();

	void Load(int, Player &, float);
	void Manage(SDL_Event &, bool &);

	void SpawnBadGuys(int);
	void RespawnPlayer();
	
	void Input(SDL_Event &, bool &);
	void Move(float);
	void Pickups(float&);
	void AddValueToPlayer(int);

	void Collision();
	void PlayerCollision(bool);
	void BadGuyCollision(bool);
	void BulletCollision();
	void PlayerBulletCollision();
	void BadGuyBulletCollision();
	void WallCollision();
	void PickupCollision();
	bool CollisionCheck(float, float, float, float, float, float);
	bool CheckAllBadGuysGone();

	void Draw(float, float);
	void DrawTitle(float);

	void UpdateTime(int &, float &, int &, float &, float &, float &);

	Player GetPlayer();
	float GetTimer();
};
#endif