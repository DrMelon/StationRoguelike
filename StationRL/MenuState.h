#pragma once
#include "state.h"

//@Author: J. Brown / DrMelon
//@Purpose: Main menu state - Start a new game, load a game, options, credits, exit.


class MenuState : public State
{
	public:
		MenuState(void);
		~MenuState(void);

		
		void Draw();
		void Update();

	private:

		// Our console
		TCODConsole* myConsole;
		
		// We want sorta moody clouds in the background, perlin noise stuff.
		TCODNoise* cloudGen;

		// Menu items
};

