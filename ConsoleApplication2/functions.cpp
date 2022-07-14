#include "functions.h"
#include "Title.h"
#include "Intro.h"
#include "Gameplay.h"
#include "globals.h"
#include "SDL_mixer.h"


bool init()
{
	//Initialization flag
	bool success = true;



	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("GOAT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == nullptr)
				{
				printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
				}
		}

	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}


void change_state()
{
	//Check if the state change requested
	if (nextState != STATE_NULL)
	{
		//Delete the current game state
		if (nextState != STATE_EXIT)
		{
			delete currentState;
		}

		//Change the game state
		switch (nextState)
		{
		case STATE_TITLE:
			currentState = new Title();
			break;
		case STATE_INTRO:
			currentState = new Intro();
			break;
		case STATE_GAME:
			currentState = new Gameplay();
			break;

		}

		//Load in the next requested state
		stateID = nextState;

		//NULL out the next state for loop
		nextState = STATE_NULL;
	}
}

void set_next_state(int newState)
{
	//User has not requested exiting
	if (nextState != STATE_EXIT)
	{
		//The next state
		nextState = newState;
	}
}

void clean_up()
{
	//free pointers and ram
	delete currentState;

	//Quit
	SDL_Quit();
}

