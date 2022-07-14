#include <SDL.h>
#include <iostream>
#include "globals.h"
#include "functions.h"
#include "Intro.h"
#include "Title.h"
#include "Gameplay.h"
#include "GameState.h"

Intro::Intro()
{
	load_media();
	
}

Intro::~Intro()
{
	SDL_FreeSurface(gSurface);
	SDL_DestroyTexture(gTexture);
	
}

void Intro::handle_events()
{
	//Looks for input to process
	while (SDL_PollEvent(&event))
	{
		//Quits if user clicks X on windows
		if (event.type == SDL_QUIT)
		{
			//Quits
			set_next_state(STATE_EXIT);
		}
		//Conditional for user pressing Enter
		else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RETURN))
		{
			//Changes the state on the stack
			set_next_state(STATE_TITLE);
		}

	}
}

bool Intro::load_media() 
{
	
	gSurface = SDL_LoadBMP("intro.bmp");

	//Error check and notification for failure to load media
	if ( gSurface == nullptr )
	{
		std::cout << "ERROR" << SDL_GetError() << std::endl;
		return false;
	}

	gTexture = SDL_CreateTextureFromSurface(gRenderer, gSurface);

	//Error check and notification for failure to load media
	if (gTexture == nullptr)
	{
		std::cout << "ERROR" << SDL_GetError() << std::endl;
		return false;
	}
	return true;

}

void Intro::render() 
{
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_RenderPresent(gRenderer);
}