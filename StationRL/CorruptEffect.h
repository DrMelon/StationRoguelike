#pragma once

#include <libtcod.hpp>

//@Author: J. Brown / DrMelon
//@Purpose: This is a simple screen corruption effect. It'll read a point on the console, change the ascii value randomly, and then move on.
// It's applied as a kind of filter, as the player approaches low suit integrity. 

struct CorruptLocation
{
	int x;
	int y;
};

class CorruptEffect
{
	public:
		CorruptEffect(TCODConsole* consoleToMessWith);
		~CorruptEffect(void);

		TCODConsole* consoleAffected;
		int timeToNextCorrupt;
		int corruptTime;
		int corruptSeed;

		TCODRandom* corruptRNG;
		CorruptLocation locations[32];

		void Update();

};

