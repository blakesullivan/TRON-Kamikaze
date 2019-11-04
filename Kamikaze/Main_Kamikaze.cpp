//Blake Sullivan - Main.cpp
#include "GameManage.h"
#include <Windows.h>
//The attributes of the screen 
const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT = 600; 
const int SCREEN_BPP = 32; //Bits Per Pixel

SDL_Surface *screen = NULL; //the pointer to the screen in memory
/* Mix_Chunk is like Mix_Music, only it's for ordinary sounds. */
//Mix_Chunk *phaser = NULL;
//Mix_Music *game = NULL;

/*	Every sound that gets played is assigned to a channel.
	Note that this is different from the number of channels you request when you open the audio device;
	a channel in SDL_mixer holds information about a sound sample that is playing, 
	while the number of channels you request when opening the device is dependant on what sort of sound you want 
	(1 channel = mono, 2 = stereo, etc) */
//int phaserChannel = -1;

int main(int argc, char *argv[]) 
{
	FreeConsole();
	GameManage GM;
	SDL_Event event;
	bool bgameRunning= true;

	//Audio setup
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16; 
	int audio_channels = 2;
	int audio_buffers = 4096;
	
    //Initialize all SDL subsystems 
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ) 
	{ return 1; }

    //Set up the screen 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE ); 
	//If there was an error in setting up the screen 
	if( screen == NULL ) { return 1; } 

	//Set up sound
	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) 
	{
		printf("Unable to open audio!\n");
		exit(1);
	}
	//game = Mix_LoadMUS("title.wav");

	//Set the window caption 
	SDL_WM_SetCaption("TRON: Kamikaze", NULL ); 

	//Fill the screen white 
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
	//Mix_PlayMusic(game, -1);

	GM.Init();
	GM.ResetMusic("title.wav");
	while (bgameRunning)
	{	
		// check for any events from the user or the system
		SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0, 0, 0 ) ); 
		
		GM.Manage(event, bgameRunning);

    	//Update the screen
		if( SDL_Flip( screen ) == -1 ) { return 1; }  //Sends the picture to the monitor
	}

	//Mix_HaltMusic();
	//Mix_FreeMusic(game);

	//GM.~GameManage();

	Mix_CloseAudio();
    SDL_Quit();

    return 0;  
}