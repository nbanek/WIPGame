#include <SDL.h>
#include <iostream>
#include "globals.h"
#include "functions.h"
#include "Gameplay.h"
#include "GameState.h"

Gameplay::Gameplay()
{

	load_media();

}

Gameplay::~Gameplay()
{
	SDL_FreeSurface(gSurface);
	SDL_DestroyTexture(gTexture);
	

}

void Gameplay::handle_events()
{
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			set_next_state(STATE_EXIT);
		}
		
		else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_RETURN))
		{
			set_next_state(STATE_INTRO);
		}

		else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_SPACE))
		{
			//Play sound
			Mix_PlayChannel(-1, gScreech, 0);
			break;
		}
	}
}


bool Gameplay::load_media()
{

	gSurface = SDL_LoadBMP("gameplay.bmp");

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
	
	gScreech = Mix_LoadWAV("rev.wav");
	if (gScreech == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	return true;
}


void Gameplay::render()
{
	SDL_RenderClear(gRenderer);
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	SDL_RenderPresent(gRenderer);
}
