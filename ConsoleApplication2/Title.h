#ifndef TITLE_H
#define TITLE_H

#include "GameState.h"


class Title : public GameState
{
private:
	SDL_Surface* gSurface = nullptr;
	SDL_Texture* gTexture = nullptr;
public:
	//Loads title screen resources
	Title();
	//Frees title resources
	~Title();

	//Main loop functions
	void handle_events();
	void render();
	bool load_media();


};

#endif TITLE_H