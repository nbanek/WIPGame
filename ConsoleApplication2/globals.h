#ifndef GLOBALS_H
#define GLOBALS_H

#include "SDL.h"
#include <iostream>
#include "GameState.h"
#include "Intro.h"
#include "Title.h"
#include "Gameplay.h"

//Temporary screen dimension we can use to debug
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The render window
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;



//The event poll
extern SDL_Event event;

enum GameStates
{
	STATE_NULL,
	STATE_INTRO,
	STATE_TITLE,
	STATE_GAME,
	STATE_EXIT,
};


extern int stateID;
extern int nextState;


extern GameState* currentState;




#endif GLOBALS_H


