#ifndef INTRO_H
#define INTRO_H

#include "GameState.h"


class Intro : public GameState
{
private:
	SDL_Surface* gSurface = nullptr;
	SDL_Texture* gTexture = nullptr;
public:
	//Loads intro resources
	Intro();

	//Frees intro resources
	~Intro();

	//Main loop functions
	void handle_events();

	bool load_media();

	void render();


};


#endif INTRO_H