#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "SDL.h"

class GameState
{
public:

	virtual ~GameState() {};
	virtual void handle_events() = 0;
	virtual void render() = 0;
};


#endif GAMESTATE_H