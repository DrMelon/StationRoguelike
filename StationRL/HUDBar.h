#pragma once
//@Author: J. Brown / DrMelon
//@Purpose: This class displays a bar representing an integer value.
// It's used on the HUD class.

#include <libtcod.hpp>


class HUDBar
{
	public:
		HUDBar(TCODConsole* toDraw, TCODColor* back, TCODColor* fore, int size, int* max, int* link, int x, int y);
		~HUDBar(void);
		void DrawBar();
		void Update();
	//private: //I'M LAZY OK
		int* linkedValue;
		int* maxValue;
		int xPos, yPos;
		int barSize;
		TCODConsole* consoleToDrawOn;
		TCODColor* backColour;
		TCODColor* frontColour;

};

