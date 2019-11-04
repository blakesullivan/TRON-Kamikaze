//Blake Sullivan - GameManage.h
#ifndef GAMEMANAGE_H
#define GAMEMANAGE_H
//#include "HUD.h"
//#include "Player.h"
//#include "BadGuy.h"
#include "Level.h"
#include "Menu.h"
#include <time.h>
using namespace std;

//#define numBad 10
//#define maxBull 10

class GameManage
{
private:
	Player GamePlayer;
	int iGamePlay;
	float fTime;
	bool keysHeld[500]; //323
	bool bKeyPressed;
	bool bPlayMusic, bPlaySound;
	Mix_Music *bgm;
	Mix_Chunk *taunt;
	int tauntChannel;

public:
	GameManage();
	~GameManage();

	void Init();

	void Manage(SDL_Event &, bool &);
	void Input(SDL_Event &, bool &);

	void LoadMenu(SDL_Event &, bool &);
	void RunLevel(SDL_Event &, int, bool &);
	void LoadSplashScreen(SDL_Event &, bool &, char, int);
	void LoadOptions(SDL_Event &, bool &);
	void SetPlayerFromLevel(Player &);
	void SetTimer(float);

	void PlayTaunt(string);
	void ResetMusic(string);
};
#endif