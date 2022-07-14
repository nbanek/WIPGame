#include <SDL.h>
#include <iostream>
#include "globals.h"
#include "functions.h"
#include "Title.h"
#include "GameState.h"

Title::Title()
{
	load_media();
}

Title::~Title()
{
	SDL_FreeSurface(gSurface);
	SDL_DestroyTexture(gTexture);
}

void Title::handle_events()
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
			//State change
			set_next_state(STATE_GAME);
		}
		//Conditional for user pressing escape
		else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
		{
			//State change
			set_next_state(STATE_EXIT);
		}
	}
}


bool Title::load_media()
{

	gSurface = SDL_LoadBMP("title.bmp");

	if (gSurface == nullptr)
	{
		std::cout << "ERROR" << SDL_GetError() << std::endl;
		return false;
	}

	gTexture = SDL_CreateTextureFromSurface(gRenderer, gSurface);
	if (gTexture == nullptr)
	{
		std::cout << "ERROR" << SDL_GetError() << std::endl;
		return false;
	}
	
	return true;

}


void Title::render()
{
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_RenderPresent(gRenderer);
}