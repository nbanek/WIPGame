#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "GameState.h"
#include "SDL_mixer.h"


class Gameplay : public GameState
{
private:
	SDL_Surface* gSurface = nullptr;
	SDL_Texture* gTexture = nullptr;
	Mix_Chunk* gScreech = nullptr;
public:
	Gameplay();
	~Gameplay();

	void handle_events();
	void render();
	bool load_media();


};

#endif GAMEPLAY_H