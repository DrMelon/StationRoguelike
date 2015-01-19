#pragma once
#include "state.h"
#include "HUD.h"
#include "CorruptEffect.h"
#include "Log.h"
#include "Tilemap.h"
//@Author: J. Brown / DrMelon
//@Purpose: Gameplay state - state entered by starting a new game or loading a game. 


class GameState :	public State
{
	public:
		GameState(void);
		~GameState(void);

		
		void Draw();
		void Update();

	private:

		// Our console
		TCODConsole* myConsole;

		// Log instance
		Log* logInstance;


		// HUD [DEBUG]
		HUD* theHUD;
		CorruptEffect* theHUDCorrupt;

		// Testing tilemap
		Tilemap* theTilemap;

};

