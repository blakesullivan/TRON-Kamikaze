//Blake Sullivan - Level.cpp
#include "Level.h"

Level::Level(SDL_Event & event, int iL, Player & p, bool& bGR, float fT, bool s)
{
	for (int i=0; i<500; i++)
		{keysHeld[i] = false;} // everything will be initialized to false

	//string sBGM = " ";
	//sBGM = "BGM"; sBGM += iL+48; sBGM += ".wav";
	//bgm = NULL;
	//bgm = Mix_LoadMUS(sBGM.c_str());
	//Mix_PlayMusic(bgm, -1);
	//Mix_VolumeMusic(35);

	bSoundOn = s;
	phaser = Mix_LoadWAV("zap.wav");
	explosion = Mix_LoadWAV("explosion.wav");
	pickup = Mix_LoadWAV("pickup.wav");
	playerChannel = -1;
	bGChannel = -1;

	Load(iL, p, fT);
	Manage(event, bGR);
}

Level::~Level()
{
	//Mix_HaltMusic();
	Mix_FreeChunk(phaser);
	Mix_FreeChunk(explosion);
	Mix_FreeChunk(pickup);
}

void Level::Load(int iLevel, Player & pl, float fT)
{
	//iGameplayer=1;
	iMaxBGs = 5 * iLevel;
	if (iMaxBGs > numBad) {iMaxBGs = numBad;}

	iGameLevel = iLevel;
	iBGLeft = iMaxBGs;

	player = pl;
	//player.Init(400, 300, 0, 255, 255, 150);
	player.SetPos(400, 300);
	player.Rotate(0);
	player.TurnFlameOff();

	SpawnBadGuys(iLevel);	

	player = pl;
	player.SetPos(400, 300);
	player.Rotate(0);

	for (int i=0; i < maxBull; i++)
	{
		player.bullets[i].SetAlive(false);
		player.bullets[i].SetColours(player.GetRed(), player.GetGreen(), player.GetBlue());
		for (int j = 0; j < iMaxBGs; j++)
		{
			bG[j].bullets[i].SetAlive(false);
			bG[j].bullets[i].SetColours(bG[j].GetRed(), bG[j].GetGreen(), bG[j].GetBlue());
		}
		pU[i].SetAlive(false);
	}
	fTimer = fT;
}

void Level::SpawnBadGuys(int iLevel)
{
	bool bExit = false;
	int iCount;
	float posX = 0, posY = 0;
	do
	{
		iCount = 0;
		for (int i=0; i < iMaxBGs; i++)
		{

			if (bG[i].GetAlive() == false)
			{
				if (((rand() % 2) + 1) == 1)
				{posX = rand() % 270 + 30;}
				else
				{posX = rand() % 270 + 470;}

				posY = rand() % 500 + 60;
				/*if (((rand() % 3) + 1) == 1)
				{posY = rand() % 100 + 100;}
				else
				{posY = rand() % 100 + 480;}*/

				if ((i == 9 && iLevel > 4) || (i > 17 && iLevel > 7) || (i >= 15 && iLevel == 10))
				{bG[i].Init(posX, posY,  'l');}
				else if (i == 0 || (i <= 1 && iLevel > 3) || (i <= 5 && iLevel > 6) || (i <= 8 && iLevel > 7) || iLevel > 9)
				{bG[i].Init(posX, posY, 'b');}
				else if ((i >= 15 && iLevel > 3) || (i >= 11 && iLevel > 4) || iLevel > 5)
				{bG[i].Init(posX, posY,  'c');}
				else
				{bG[i].Init(posX, posY,  's');}
			}
		}
		PlayerCollision(false);
		BadGuyCollision(true);
		for (int i = 0; i < iMaxBGs; i++)
		{
			if (bG[i].GetAlive()==true)
			{
				iCount++;
			}
		}

		if (iCount == iMaxBGs)
			{bExit = true;}
		else
			{bExit = false;}

	}while (bExit == false);
}

void Level::Manage(SDL_Event & event, bool & bGRunning)
{
	//SDL_Event event;
	int iLastTime=0;
	float fLoadTimer=3;
	int iThisTime=0;
	float fDeltaTime=0;
	float fDropTimer = rand() % 10 + 5;
	bool bExit = false;

	fTimer += 3;
	//FPS setting
	do
	{
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 

		UpdateTime(iThisTime, fDeltaTime, iLastTime, fTimer, fLoadTimer, fDropTimer);
		if (fLoadTimer <= 0)
		{
			Input(event, bGRunning);
			if (player.GetAlive() == true)
			{
				Move(fDeltaTime);
				Pickups(fDropTimer);
				Collision();
			}
			else if (player.GetExplode() == false)
				{RespawnPlayer();}
		}
		else
			{DrawTitle(fLoadTimer);}
		
		Draw(fDeltaTime, fTimer);
		
		if (fTimer<=0)
			{bExit = true;}

		if(SDL_Flip( screen ) == -1 ) {bGRunning = false; bExit = true;}  //Sends the picture to the monitor
		//cout << iBGLeft << endl;
		if ((player.GetLives() <= 0 && player.GetExplode() == false) || bGRunning == false) 
		{bExit = true;}
		if (CheckAllBadGuysGone() == true)
		{bExit = true;}

	}while (bExit == false);
}

void Level::UpdateTime(int& iTT, float& fDT, int& iLT, float& fT, float& fLT, float& fDrT)
{
	iTT = SDL_GetTicks();
	if (iLT == 0)
		{iLT = iTT;}
	fDT = (float) (iTT - iLT) / 1000;
	iLT = iTT;
	fT -= fDT;
	fLT -= fDT;
	fDrT -= fDT;
}

void Level::Input(SDL_Event & event, bool & bGameR)
{
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT)
	{
		bGameR = false;
	}

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_SPACE && keysHeld[SDLK_SPACE] == false)// && iGameplayer == 1)
		{
				if (true == player.Shoot() && bSoundOn == true)
					{playerChannel = Mix_PlayChannel(-1, phaser, 0);}
				//cout << "anything\n";
		}
		keysHeld[event.key.keysym.sym] = true;		
	}

	if (event.type == SDL_KEYUP)
	{
		keysHeld[event.key.keysym.sym] = false;
	}

	if (keysHeld[SDLK_ESCAPE])
	{
		bGameR=false;
	}
	
}

void Level::Move(float fDeltaTime)
{
	WallCollision();
	if (keysHeld[SDLK_LEFT] || keysHeld[SDLK_a])
	{
		player.Move('l', fDeltaTime);
		player.SetLeftFlame(true);
	}
	else
	{player.SetLeftFlame(false);}

	if (keysHeld[SDLK_RIGHT] || keysHeld[SDLK_d])
	{
		player.Move('r', fDeltaTime);
		player.SetRightFlame(true);
	}
	else
	{player.SetRightFlame(false);}

	if (keysHeld[SDLK_UP] || keysHeld[SDLK_w])
	{
		player.Move('u', fDeltaTime);
		player.SetUpFlame(true);
	}
	else
	{player.SetUpFlame(false);}

	if (keysHeld[SDLK_DOWN] || keysHeld[SDLK_s])
	{
		player.Move('v', fDeltaTime);
		player.SetDownFlame(true);
	}
	else
	{player.SetDownFlame(false);}

	for (int i=0; i < iMaxBGs; i++)
	{
		if (bG[i].GetAlive() == true)
		{
			bG[i].Face(player.GetXo(), player.GetYo());
			bG[i].Move(fDeltaTime);
			if (true == bG[i].CalcShoot(fDeltaTime) && bSoundOn == true)
				{bGChannel = Mix_PlayChannel(-1, phaser, 0);}
		}
		for (int j = 0; j < maxBull; j++)
		{
			if (bG[i].bullets[j].GetAlive()==true)
			{
				bG[i].bullets[j].Move(fDeltaTime);
			}
		}
	}

	for (int i = 0; i < maxBull; i++)
	{
		if (player.bullets[i].GetAlive()==true)
		{
			player.bullets[i].Move(fDeltaTime);
		}
	}
}

void Level::Collision()
{
	PlayerCollision(true);
	BadGuyCollision(false);
	BulletCollision();
	PickupCollision();	
}

void Level::PlayerCollision(bool bTestplayerer)
{
	for (int i=0; i < iMaxBGs; i++)
	{
		if (bG[i].GetAlive()==true)
		{
			if (true==CollisionCheck(player.GetPosX(), player.GetPosY(), player.GetPosSize(), bG[i].GetPosX(), bG[i].GetPosY(), bG[i].GetPosSize()))
			{
				if (bG[i].TakeDamageReturnDead(player.GetCollisionDamage()) == true)
				{
					if (bTestplayerer==false)
						{bG[i].SetAlive(false);}
					else
					{
						bG[i].Destroy();
						iBGLeft--;
					}
				}
				if (player.TakeDamageReturnDead(bG[i].GetCollisionDamage()) == true && bTestplayerer == true)
				{
					player.Destroy();
					//player.SetAlive(false);
					//player.SetLives(player.GetLives()-1);
					//explosion goes here
				}
			}
		}
	}
}

void Level::BadGuyCollision(bool bSpawnTest)
{
	for (int i=0; i < iMaxBGs; i++)
	{
		if (bG[i].GetAlive()==true)
		{
			for (int j=i+1; j < iMaxBGs; j++)
			{
				if (bG[j].GetAlive()==true)
				{
					if (true==CollisionCheck(bG[i].GetPosX(), bG[i].GetPosY(), bG[i].GetPosSize(), bG[j].GetPosX(), bG[j].GetPosY(), bG[j].GetPosSize()))
					{
						if (bG[i].TakeDamageReturnDead(bG[j].GetCollisionDamage()) == true)
						{
							if (bSpawnTest==true)
								{bG[i].SetAlive(false);}
							else
							{
								bG[i].Destroy();
								iBGLeft--;
							}
						}
						if (bG[j].TakeDamageReturnDead(bG[i].GetCollisionDamage()) == true)
						{
							if (bSpawnTest==true)
								{bG[j].SetAlive(false);}
							else
							{
								bG[j].Destroy();
								iBGLeft--;
							}
						}
					}
				}
			}
		}
	}
}

void Level::BulletCollision()
{
	PlayerBulletCollision();
	BadGuyBulletCollision();

	for (int i=0; i < maxBull; i++)
	{
		if (player.bullets[i].GetX()<=0 || player.bullets[i].GetX()>800 || player.bullets[i].GetY()<=0 || player.bullets[i].GetY()>600)
		{
			player.bullets[i].SetAlive(false);
		}

		for (int j=0; j < iMaxBGs; j++)
		{
			if (bG[j].bullets[i].GetX()<=0 || bG[j].bullets[i].GetX()>800 || bG[j].bullets[i].GetY()<=0 || bG[j].bullets[i].GetY()>600)
			{
				bG[j].bullets[i].SetAlive(false);
			}
		}
	}
}

void Level::PlayerBulletCollision()
{
	for (int i=0; i < maxBull; i++)
	{
		if (player.bullets[i].GetAlive()==true)
		{
			for (int j=0; j < iMaxBGs; j++) 
			{
				if (bG[j].GetAlive()==true)
				{
					if (true==CollisionCheck(player.bullets[i].GetX(), player.bullets[i].GetY(), player.bullets[i].GetSize(), bG[j].GetPosX(), bG[j].GetPosY(), bG[j].GetPosSize()))
					{
						if (bG[j].TakeDamageReturnDead(player.GetBulletDamage()) == true)
						{
							bG[j].Destroy();
							iBGLeft--;
						}
						player.bullets[i].SetAlive(false);
					}
				}
			}
		}
	}
}

void Level::BadGuyBulletCollision()
{
	for (int i=0; i < iMaxBGs; i++)
	{
		for (int j = 0; j < maxBull; j++)
		{
			if (bG[i].bullets[j].GetAlive()==true)
			{
				if (true==CollisionCheck(bG[i].bullets[j].GetX(), bG[i].bullets[j].GetY(), bG[i].bullets[j].GetSize(), player.GetPosX(), player.GetPosY(), player.GetPosSize()))
				{
					if (player.TakeDamageReturnDead(bG[i].GetBulletDamage()) == true)
					{
						player.Destroy();
						//player.SetAlive(false);
						//player.SetLives(player.GetLives()-1);
						//explosion goes here
					}
					bG[i].bullets[j].SetAlive(false);
				}
			}
		}
	}
}

void Level::WallCollision()
{
	float fX = 0, fY = 0;
	bool bNeedToMove = false;
	if (player.GetPosX() < 0)
	{
		fX = 799;
		bNeedToMove = true;
	}
	else if (player.GetPosX() > 800)
	{
		fX = 1;
		bNeedToMove = true;
	}
	else
	{fX = player.GetPosX();}

	if (player.GetPosY() < 0)
	{
		fY = 599;
		bNeedToMove = true;
	}
	else if (player.GetPosY() > 600)
	{
		fY = 1;
		bNeedToMove = true;
	}
	else
	{fY = player.GetPosY();}
	
	if (bNeedToMove == true) {player.SetPos(fX, fY);}
}

void Level::PickupCollision()
{
	for (int i = 0; i < maxBull; i++)
	{
		if (pU[i].GetAlive() == true)
		{
			if (true == CollisionCheck(player.GetPosX(), player.GetPosY(), player.GetPosSize(), pU[i].GetX(), pU[i].GetY(), pU[i].GetSize()))
			{
				AddValueToPlayer(i);
				pU[i].SetAlive(false);
				if (bSoundOn == true) {playerChannel = Mix_PlayChannel(-1, pickup, 0);}
			}
		}
	}
}

bool Level::CollisionCheck(float p1X, float p1Y, float p1S, float p2X, float p2Y, float p2S)
{
	if (sqrt(pow((p2X-p1X),2)+pow((p2Y-p1Y),2)) <= p1S + p2S)
		{return true;}
	else
		{return false;}
}

void Level::Draw(float fDeltaTime, float fTimer)
{
	int iPlayerBulletsShot = 0;
	static bool bPlayerExplode = false, bBGExplode[numBad] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

	if (player.GetAlive() == true || true == player.GetExplode())
		{player.Draw(fDeltaTime);}
	if (player.GetAlive() == false && true == player.GetExplode() && bPlayerExplode == false)
	{
		if (bSoundOn == true) {playerChannel = Mix_PlayChannel(-1, explosion, 0);}
		bPlayerExplode = true;
	}
	else if (player.GetAlive() == true && false == player.GetExplode() && bPlayerExplode == true)
	{bPlayerExplode = false;}

	for (int i=0;i < iMaxBGs;i++)
	{
		if (true==bG[i].GetAlive() || true==bG[i].GetExplode())
		{
			bG[i].Draw(fDeltaTime);
			//bG[i].DrawLabel(bG[i].GetAlive());
		}
		if (bG[i].GetAlive() == false && true == bG[i].GetExplode() && bBGExplode[i] == false)
		{
			if (bSoundOn == true) {bGChannel = Mix_PlayChannel(-1, explosion, 0);}
			bBGExplode[i] = true;
		}
		else if (bG[i].GetAlive() == true && false == bG[i].GetExplode() && bBGExplode[i] == true)
		{bBGExplode[i] = false;}
	}
	for (int i = 0; i < maxBull; i++)
	{
		if (player.bullets[i].GetAlive()==true)
		{
			iPlayerBulletsShot++;
			player.bullets[i].Draw();
		}

		for (int j = 0; j < iMaxBGs; j++)
		{
			if (bG[j].bullets[i].GetAlive()==true)
				{bG[j].bullets[i].Draw();}
		}

		if (pU[i].GetAlive() == true)
			{pU[i].Draw();}
	}
	hud.Draw(player.GetHealth(), player.GetShield(), fTimer, player.GetLives(), player.GetBulletType(), player.GetBulletMax() - iPlayerBulletsShot, iGameLevel);
}

Player Level::GetPlayer()
{
	return player;
}

void Level::DrawTitle(float fTime)
{
	int iTime = 0;
	iTime = fTime; // - 120;
	hud.DrawCountDown(iTime);
}

void Level::RespawnPlayer()
{
	float fX = 0, fY = 0;
	bool bReposition = true;
	player.SetAlive(true);
	player.SetHealth(50);
	player.SetShield(100);
	player.SetShieldAlive(true);
	do
	{
		fX = rand() % 760 + 15;
		fY = rand() % 530 + 60;
		player.SetPos(fX, fY);
		for (int i = 0; i < iMaxBGs; i++)
		{
			if (bG[i].GetAlive() == true)
			{
				if (true == CollisionCheck(player.GetPosX(), player.GetPosY(), player.GetPosSize(), bG[i].GetPosX(), bG[i].GetPosY(), bG[i].GetPosSize()))
				{
					bReposition = true;
					break;
				}
				else
					{bReposition = false;}
			}
		}
	}while (bReposition == true);
	player.Rotate(0);
}

float Level::GetTimer()
{
	return fTimer;
}

void Level::Pickups(float& fDropTimer)
{
	int iType = 0, iValue = 0, iPoints = 0;
	char cType = ' ';

	if (fDropTimer <= 0)
	{
		fDropTimer = rand() % 20 + 10;
		for (int i = 0; i < maxBull; i++)
		{
			if (pU[i].GetAlive() == false)
			{
				iType = rand() % 20 + 1;
				if (iType >= 0 && iType <= 2)
				{
					cType = 'b';
					iValue = 1;
					iPoints = 75;
				}
				else if (iType >= 3 && iType <= 4)
				{
					cType = 'b';
					iValue = 10;
					iPoints = 75;
				}
				else if (iType >= 5 && iType <= 11)
				{
					cType = 'h';
					iValue = 10;
					iPoints = 50;
				}
				else if (iType == 12)
				{
					cType = 'l';
					iValue = 1;
					iPoints = 100;
				}
				else if (iType >= 13 || iType <= 20)
				{
					cType = 's';
					iValue = 15;
					iPoints = 50;
				}

				pU[i].Create(cType, iValue, iPoints, rand() % 760 + 15, rand() % 530 + 60, 10);
				break;
			}
		}
	}	
}

void Level::AddValueToPlayer(int iPNum)
{
	int iTemp = 0;
	switch (pU[iPNum].GetType())
	{
	case 'b':
		if (pU[iPNum].GetValue() > 1)
		{
			iTemp = player.GetBulletDamage();
			iTemp += pU[iPNum].GetValue();
			player.SetBulletDamage(iTemp);
		}
		else
		{
			iTemp = player.GetBulletMax();
			iTemp += pU[iPNum].GetValue();
			player.SetBulletMax(iTemp);
		}
	break;
	case 'h':
		if (player.GetHealth() < player.GetMaxHealth())
		{
			iTemp = player.GetHealth();
			iTemp += pU[iPNum].GetValue();
			if (iTemp > player.GetMaxHealth())
				{iTemp = player.GetMaxHealth();}
			player.SetHealth(iTemp);
		}
	break;
	case 'l':
		iTemp = player.GetLives();
		iTemp += pU[iPNum].GetValue();
		player.SetLives(iTemp);
	break;
	case 's':
		if (player.GetShieldAlive() == false) {player.SetShieldAlive(true);}
		if (player.GetShield() < player.GetMaxShield())
		{
			iTemp = player.GetShield();
			iTemp += pU[iPNum].GetValue();
			if (iTemp > player.GetMaxShield())
				{iTemp = player.GetMaxShield();}
			player.SetShield(iTemp);
		}
	break;
	default:
		if (player.GetHealth() < player.GetMaxHealth())
		{
			iTemp = player.GetHealth();
			iTemp += pU[iPNum].GetValue();
			if (iTemp > player.GetMaxHealth())
				{iTemp = player.GetMaxHealth();}
			player.SetHealth(iTemp);
		}
	}
}

bool Level::CheckAllBadGuysGone()
{
	for (int i = 0; i < numBad; i++)
	{
		if (i < iMaxBGs)
		{
			if (bG[i].GetAlive() == true || bG[i].GetExplode() == true)
			{return false;}
		}
	}
	return true;
}