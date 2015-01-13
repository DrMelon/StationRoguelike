#include "CorruptEffect.h"


CorruptEffect::CorruptEffect(TCODConsole* consoleToMessWith)
{
	consoleAffected = consoleToMessWith;
	timeToNextCorrupt = 0;
	corruptTime = 60;
	corruptRNG = new TCODRandom();
}

void CorruptEffect::Update()
{
	// First, we check to see if the time to next corrupt is 0.
	if(timeToNextCorrupt <= 0)
	{
		timeToNextCorrupt = 120; // 2 sec in the future till next corrupt (change this with frequency based on player suit integrity)
		corruptTime = 60;

		// Pick locations on the screen to corrupt
		for(int i = 0; i < 32; i++)
		{
			locations[i].x = corruptRNG->getInt(0, 79);
			locations[i].y = corruptRNG->getInt(0, 79);
		}


	}
	timeToNextCorrupt--;
	// If the corruptTime is bigger than zero, the effect is running.
	int getRandomChar = 0;
	if(corruptTime > 0)
	{
		// Set Colours Randomly
		TCODColor newCol;
		newCol.r = corruptRNG->getInt(0, 255);
		newCol.g = corruptRNG->getInt(0, 255);
		newCol.b = corruptRNG->getInt(0, 255);

		
		consoleAffected->setDefaultForeground(newCol);

		for(int i = 0; i < 32; i++)
		{
			getRandomChar = corruptRNG->getInt(0, 254);
			consoleAffected->putChar(locations[i].x, locations[i].y, getRandomChar);
			getRandomChar = corruptRNG->getInt(0, 254);
			consoleAffected->putChar(locations[i].x+1, locations[i].y, getRandomChar);
			getRandomChar = corruptRNG->getInt(0, 254);
			consoleAffected->putChar(locations[i].x, locations[i].y+1, getRandomChar);
			getRandomChar = corruptRNG->getInt(0, 254);
			consoleAffected->putChar(locations[i].x+1, locations[i].y+1, getRandomChar);
		}
		corruptTime--;
	}

}

CorruptEffect::~CorruptEffect(void)
{
}
