//Blake Sullivan - GameManage.cpp
#include "GameManage.h"

GameManage::GameManage()
{
	iGamePlay=0;
	bKeyPressed = false;
	bPlayMusic = true;
	bPlaySound = true;
	srand(time(NULL));
	bgm = NULL;
	//Init();
}
GameManage::~GameManage()
{
	Mix_PlayMusic(bgm, -1);
	Mix_HaltMusic();
	Mix_FreeMusic(bgm);
}

void GameManage::Init()
{
	for (int i=0; i<500; i++)
	{
		keysHeld[i] = false; // everything will be initialized to false
	}
}

void GameManage::Manage(SDL_Event & event, bool & bGRunning)
{
	int iMaxLevel = 10;
	bool bMusicChanged = false;

	if (bPlayMusic == false) {Mix_HaltMusic();}
	Init();
	
	switch (iGamePlay)
	{
	case 0:
		LoadMenu(event, bGRunning);
	break;
	case 1:
		ResetMusic("story.wav");
		LoadSplashScreen(event, bGRunning, 'S', 1);
		ResetMusic("BGM1.wav");
		tauntChannel = 1;
		//Mix_VolumeMusic(35);
		GamePlayer.Init(400, 300, 0, 255, 255, 150);
		fTime = 180;
		for (int i = 1; i <= iMaxLevel; i++)
		{
			if(i == 1 || i == 6) {PlayTaunt("CHANGE.wav");}
			if(i == 2 || i == 8) {PlayTaunt("ALIVE.wav");}
			if(i == 4 || i == 7 || i == 9) {PlayTaunt("DIE.wav");}
			if(i == 5 || i == 10) {PlayTaunt("ODDS.wav");}
			if (i == 6)	{ResetMusic("BGM2.wav");	}
			
			RunLevel(event, i, bGRunning);
			if (GamePlayer.GetLives() <= 0 || bGRunning == false)
			{
				iGamePlay=8;
				break;
			}
			//taunt = Mix_LoadWAV("DIE.wav");
			//tauntChannel = Mix_PlayChannel(-1, taunt, 0);
		}
		if (iGamePlay != 8) {iGamePlay = 7;}
	break;
	case 2:
		LoadSplashScreen(event, bGRunning, 'H', iGamePlay);
	break;
	case 3:
		LoadOptions(event, bGRunning);
	break;
	case 7:
		ResetMusic("win.wav");
		LoadSplashScreen(event, bGRunning, 'W', iGamePlay);
		ResetMusic("title.wav");
		//iGamePlay = 0;
	break;
	case 8:
		ResetMusic("lose.wav");
		LoadSplashScreen(event, bGRunning, 'L', iGamePlay);
		ResetMusic("title.wav");
		//iGamePlay = 0;
	break;
	}
	bKeyPressed = false;
}

void GameManage::LoadMenu(SDL_Event & event, bool & bGR)
{
	Menu objMenu('M');
	do
	{
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
		objMenu.DrawMenu();
		Input(event, bGR);
		
		if (bKeyPressed == true)
		{
			if (keysHeld[SDLK_1] || keysHeld[SDLK_KP1])
				{iGamePlay=1;}
			else if (keysHeld[SDLK_2] || keysHeld[SDLK_KP2])
				{iGamePlay=2;}
			else if (keysHeld[SDLK_3] || keysHeld[SDLK_KP3])
				{iGamePlay=3;}
			else if (keysHeld[SDLK_4] || keysHeld[SDLK_KP4])
				{bGR=false;}
		}

		if( SDL_Flip( screen ) == -1 ) {iGamePlay==4; bGR==false;}  //Sends the picture to the monitor
		if (bGR == false)
			{break;}
	}while (iGamePlay == 0);
}

void GameManage::RunLevel(SDL_Event & event, int iLevel, bool & bGameRun)
{
	Level level(event, iLevel, GamePlayer, bGameRun, fTime, bPlaySound);
	SetPlayerFromLevel(level.GetPlayer());
	SetTimer(level.GetTimer() + 20);
}

void GameManage::SetPlayerFromLevel(Player & p)
{
	GamePlayer = p;
}

void GameManage::SetTimer(float fT)
{
	fTime = fT;
}

void GameManage::Input(SDL_Event & event, bool & bGameR)
{
	static bool bPressed = false;
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
		{bGameR = false;}

	if (event.type == SDL_KEYDOWN)
	{
		if (keysHeld[event.key.keysym.sym] == false && bPressed == false)
			{bKeyPressed = true; bPressed = true;}
		keysHeld[event.key.keysym.sym] = true;
	}

	if (event.type == SDL_KEYUP)
	{
		keysHeld[event.key.keysym.sym] = false;
		bKeyPressed = false; bPressed = false;
	}

	if (keysHeld[SDLK_ESCAPE])
		{bGameR=false;}
}

void GameManage::LoadSplashScreen(SDL_Event & event, bool & bGR, char cType, int iGP)
{
	bool bExit = false;
	Menu objMenu(cType);
	do
	{
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
		objMenu.DrawSplash(cType);
		Input(event, bGR);
		if (bKeyPressed == true && cType != 'S') 
		{iGamePlay = 0;}
		else if (bKeyPressed == true && cType == 'S') 
		{bExit = true;}

		if( SDL_Flip( screen ) == -1 ) {iGamePlay==4; bGR==false;}  //Sends the picture to the monitor
		if (bGR == false)
			{break;}
	}while (iGamePlay == iGP && bExit == false);
}

void GameManage::LoadOptions(SDL_Event & event, bool & bGR)
{
	Menu objMenu('O');
	bool bChanged = false;
	do
	{
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
		objMenu.DrawOptions(bPlayMusic, bPlaySound);
		Input(event, bGR);
		if( SDL_Flip( screen ) == -1 ) {iGamePlay==4; bGR==false;}  //Sends the picture to the monitor
		if (bKeyPressed == true && bChanged == false) 
		{
			if (keysHeld[SDLK_m])
			{
				if (bPlayMusic == true)
					{bPlayMusic = false;}
				else
					{bPlayMusic = true;}
			}
			
			if (keysHeld[SDLK_s])
			{
				if (bPlaySound == true)
					{bPlaySound = false;}
				else
					{bPlaySound = true;}
			}
			
			if (keysHeld[SDLK_s] == false && keysHeld[SDLK_m] == false) {iGamePlay = 0;}
			bChanged = true;
		}
		else
		{
			if (bKeyPressed == false) {bChanged = false;}
		}

	}while (iGamePlay == 3 && bGR == true);
}

void GameManage::PlayTaunt(string sTaunt)
{
	taunt = Mix_LoadWAV(sTaunt.c_str());
	if (bPlaySound == true) {tauntChannel = Mix_PlayChannel(1, taunt, 0);}
}

void GameManage::ResetMusic(string sMusic)
{
	Mix_HaltMusic();
	bgm = Mix_LoadMUS(sMusic.c_str());
	if (bPlayMusic == true) {Mix_PlayMusic(bgm, -1);}
}