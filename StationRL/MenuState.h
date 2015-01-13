#pragma once
#include "state.h"
#include "HUD.h"
#include "CorruptEffect.h"
#include "Log.h"
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

		// Log instance
		Log* logInstance;


		// We want sorta moody clouds in the background, perlin noise stuff.
		TCODNoise* cloudGen;

		// Menu items

		// HUD [DEBUG]
		HUD* theHUD;
		CorruptEffect* theHUDCorrupt;
};

