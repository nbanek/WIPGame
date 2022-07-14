#include "globals.h"

int stateID = STATE_NULL;
int nextState = STATE_NULL;

//The render window
SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

//The events
SDL_Event event;

GameState* currentState = NULL;