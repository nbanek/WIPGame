
#include <SDL.h>
#include <iostream>
#include "globals.h"
#include "functions.h"
#include "Intro.h"


int main(int argc, char* args[])
{
	
    //Initialize
    if (init() == false)
    {
        return 1;
    }



	//Set the current state ID
    stateID = STATE_INTRO;
	
    //Set the current a game state object
    currentState = new Intro();

	//this is the main game loop
	while (stateID != STATE_EXIT)
	{

		//Handle events for the current state
		currentState->handle_events();
		//render the current state
		currentState->render();
		//Change state if needed
		change_state();

	}
	//Call destructors and clean up memory
	clean_up();
	
	return 0;
}




