//Blake Sullivan - Menu.cpp
#include "Menu.h"

Menu::Menu(char cStyle)
{
	SetStringColours(255,255,255);
	image = NULL;
	switch (cStyle)
	{
	case 'M':
		image = SDL_LoadBMP("title.bmp");
	break;
	case 'H':
		image = SDL_LoadBMP("title.bmp");
	break;
	case 'O':
		image = SDL_LoadBMP("title.bmp");
	break;
	case 'S':
		image = SDL_LoadBMP("title.bmp");
	break;
	case 'W':
		image = SDL_LoadBMP("win.bmp");
	break;
	case 'L':
		image = SDL_LoadBMP("gameover.bmp");
	break;
	}
	SDL_SetColorKey(image, SDL_SRCCOLORKEY, SDL_MapRGB(image->format, 0, 0, 0) );
	//Draw();
}

Menu::~Menu()
{
	//Mix_PlayMusic(bgm, -1);
	SDL_FreeSurface(image);
}

void Menu::DrawMenu()
{
	char menuItem[255];
	int i = 1, iPos = 280;
	SetStringColours(255,255,255);
	//sprintf(menuItem, "TRON: Kamikaze");
	//stringRGBA(screen, 290, 100, menuItem, 255, 255, 255, 255);
	sclip.x = 0; sclip.y = 0; sclip.w = 250; sclip.h = 100;
	dclip.x = 250; dclip.y = 100; dclip.w = 250; dclip.h = 100;
	SDL_BlitSurface(image, &sclip, screen, &dclip);

	sprintf(menuItem, ">>> %d. Play", i); i++; iPos += 20;
	stringRGBA(screen, 300, iPos, menuItem, 255, 255, 255, 255);
	//sprintf(menuItem, "%d. 2 Player", i); i++;
	//stringRGBA(screen, 300, 220, menuItem, 255, 255, 255, 255);
	sprintf(menuItem, ">>> %d. Highscore", i); i++; iPos += 20;
	stringRGBA(screen, 300, iPos, menuItem, 255, 255, 255, 255);
	sprintf(menuItem, ">>> %d. Options", i); i++; iPos += 20;
	stringRGBA(screen, 300, iPos, menuItem, 255, 255, 255, 255);
	sprintf(menuItem, ">>> %d. Exit", i); i++; iPos += 20;
	stringRGBA(screen, 300, iPos, menuItem, 255, 255, 255, 255);
}

void Menu::DrawOptions(bool bMusic, bool bSounds)
{
	int iPos = 200;
	SetStringColours(255,255,255);
	OutputString("PRESS ANY KEY TO SAVE AND CONTINUE.", 250, 550);
	sclip.x = 0; sclip.y = 0; sclip.w = 250; sclip.h = 100;
	dclip.x = 250; dclip.y = 50; dclip.w = 250; dclip.h = 100;
	SDL_BlitSurface(image, &sclip, screen, &dclip);

	OutputString("PLAYER CONTROLS", 250, iPos); iPos += 20;
	OutputString("Up/Accelerate: UP Arrow / W", 250, iPos); iPos += 20;
	OutputString("Down/Brake: DOWN Arrow / S", 250, iPos); iPos += 20;
	OutputString("Left Turn: LEFT Arrow / A", 250, iPos); iPos += 20;
	OutputString("Right Turn: RIGHT Arrow / D", 250, iPos); iPos += 20;
	OutputString("Shoot: SPACEBAR", 250, iPos); iPos += 60;

	OutputString("AUDIO OPTIONS", 250, iPos); iPos += 20;
	string sOutput;
	if (bMusic == true) {sOutput = "Music: ON";} else {sOutput = "Music: OFF";} 
	OutputString(sOutput, 250, iPos); iPos += 20;
	OutputString("[PRESS 'M' TO TOGGLE MUSIC]", 250, iPos); iPos += 20;
	if (bSounds == true) {sOutput = "Sounds: ON";} else {sOutput = "Sounds: OFF";} 
	OutputString(sOutput, 250, iPos); iPos += 20;
	OutputString("[PRESS 'S' TO TOGGLE SOUND]", 250, iPos); iPos += 20;
}

void Menu::DrawSplash(char cType)
{
	if (cType == 'W')
		{DrawWin();}
	else if (cType == 'L')
		{DrawLose();}
	else if (cType == 'S')
		{DrawStory();}
	else if (cType == 'H')
		{DrawHighScore();}
}

void Menu::DrawWin()
{
	SetStringColours(255,255,255);
	OutputString("PRESS ANY KEY TO CONTINUE.", 250, 400);

	sclip.x = 0; sclip.y = 0; sclip.w = 450; sclip.h = 100;
	dclip.x = 150; dclip.y = 100; dclip.w = 450; dclip.h = 100;
	SDL_BlitSurface(image, &sclip, screen, &dclip);
}

void Menu::DrawLose()
{
	SetStringColours(255,255,255);
	OutputString("PRESS ANY KEY TO CONTINUE.", 250, 400);

	sclip.x = 0; sclip.y = 0; sclip.w = 350; sclip.h = 150;
	dclip.x = 200; dclip.y = 100; dclip.w = 350; dclip.h = 150;
	SDL_BlitSurface(image, &sclip, screen, &dclip);	
}

void Menu::DrawStory()
{
	int iPosX = 25, iPosY = 150;
	SetStringColours(255,255,255);
	OutputString("PRESS ANY KEY TO CONTINUE.", 250, 575);
	sclip.x = 0; sclip.y = 0; sclip.w = 250; sclip.h = 100;
	dclip.x = 250; dclip.y = 25; dclip.w = 250; dclip.h = 100;
	SDL_BlitSurface(image, &sclip, screen, &dclip);

	SetStringColours(0,255,255);
	OutputString("[TAKEN FROM LOGS OF KEVIN FLYNN]", iPosX, iPosY); iPosY += 40;
	OutputString(">>> THE GRID: A DIGITAL FRONTIER.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> I TRIED TO PICTURE CLUSTERS OF INFORMATION AS THEY MOVED THROUGH THE COMPUTER.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> WHAT DID THEY LOOK LIKE? SHIPS? MOTORCYCLES? WERE THE CIRCUITS LIKE FREEWAYS?", iPosX, iPosY); iPosY += 20;
	OutputString(">>> I KEPT DREAMING OF A WORLD I THOUGHT I'D NEVER SEE... AND THEN ONE DAY...", iPosX, iPosY); iPosY += 40;
	OutputString(">>> I GOT IN!", iPosX, iPosY); iPosY += 40;
	OutputString(">>> THE GRID I HAD CREATED WAS A UTOPIA.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> BUT I DIDN'T CREATE IT ALONE, I HAD HELP, FROM TWO PROGRAMS: TRON AND C.L.U.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> C.L.U. WAS THE BEST PROGRAM I HAD EVER WRITTEN, WITH ONE PURPOSE: CREATE THE PERFECT SYSTEM.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> LITTLE DID I KNOW THAT HE WOULD SOON BETRAY ME TO CREATE HIS PERFECT SYSTEM.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> I HAVE WRITTEN ONE LAST PROGRAM. A 'SYSTEM MONITOR' TO HELP PROTECT THE SYSTEM.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> C.L.U. HAS ALREADY SENT PROGRAMS AFTER ME, TRON, AND THE SYSTEM MONITOR.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> THESE PROGRAMS WILL STOP AT NOTHING TO DEREZ ANYONE THEY CAN.", iPosX, iPosY); iPosY += 40;
	OutputString(">>> TRON IS DEREZZED AND I'M RUNNING OUT OF TIME. ANY FURTHER CONTACT IS BY C.L.U.", iPosX, iPosY); iPosY += 20;
	OutputString(">>> GOOD LUCK SYSTEM MONITOR, YOU'RE GOING TO NEED IT.", iPosX, iPosY); iPosY += 40;
	OutputString("END OF LINE.", 650, iPosY); iPosY += 20;
}

void Menu::DrawHighScore()
{
	int iPos = 200;
	SetStringColours(255,255,255);
	OutputString("PRESS ANY KEY TO CONTINUE.", 250, 550);

	sclip.x = 0; sclip.y = 0; sclip.w = 250; sclip.h = 100;
	dclip.x = 250; dclip.y = 50; dclip.w = 250; dclip.h = 100;
	SDL_BlitSurface(image, &sclip, screen, &dclip);

	for (int i = 1; i < 11; i++)
	{
		 OutputString(LoadHighScore(i), 300, iPos);
		 iPos += 20;
	}

}

void Menu::OutputString(string sOutput, int iX, int iY)
{
	stringRGBA(screen, iX, iY, sOutput.c_str(), iRed, iGreen, iBlue, 255);
}

void Menu::SetStringColours(int r, int g, int b)
{
	iRed = r;
	iGreen = g;
	iBlue = b;
}

string Menu::LoadHighScore(int iNum)
{
	string sOutput = " ", sNum = " ";
	int iFind = 0;
	ifstream scoreFile("Score.txt");
	if (scoreFile.good())
	{
		do
		{
			scoreFile >> sOutput;
			sNum = sOutput[3];
		} while (atoi(sNum.c_str()) < iNum && scoreFile.eof() == false);
	}
	else
	{sOutput = "File Failed to Open.";}
	return sOutput;
}