#pragma once


//Starts up SDL and creates window
bool init();

//State status manager
void set_next_state(int newState);

//State changer
void change_state();

void clean_up();

