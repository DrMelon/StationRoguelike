#pragma once
//@Author: J. Brown / DrMelon
//@Purpose: Simple HUD class for displaying information in StationRL:
//
// HUD Design:
//
//
// The HUD itself will take up a lower portion of the screen, and a strip running down the right hand side.
// The lower portion will act as a message log / activity display, providing the player with information like in most Roguelikes.
// On the right will be displayed things like Health, Suit Integrity, O2 Level, etc. The player might not always be wearing a suit,
// and different suits can display different information, so there will be a segment dedicated to the suit's own functionality.
// Hopefully suit functionality will be encoded on in-game floppy disks that can be inserted and removed to alter functionality or display.
// 
//
//
//

#include <libtcod.hpp>
#include "HUDBar.h"
#include <string>
#include "Log.h"

class HUD
{
	public:
		HUD(TCODConsole* mainCon);
		~HUD(void);

		TCODConsole* mainConsole; // Main console to draw on.
		Log* logInstance; // Log to draw

		//Player* myPlayer // Reference to player to fetch suit data etc from.
		int* myPlayerDotHealth; //[DEBUG]
		int* myPlayerDotMaxHealth;

		TCODColor* healthColor;
		TCODColor* healthColorBack;

		// HUD Spaces
		TCODConsole* logConsole;
		TCODConsole* fdiskConsole;
		TCODConsole* infoConsole;

		// HUD Elements
		HUDBar* healthBar;
		//HUDBar* oxygenBar
		
		void DrawHUD();
		void Update();

};

