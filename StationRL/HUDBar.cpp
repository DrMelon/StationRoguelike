#include "HUDBar.h"


HUDBar::HUDBar(TCODConsole* toDraw, TCODColor* back, TCODColor* fore, int size, int* max, int* link, int x, int y)
{
	consoleToDrawOn = toDraw;
	backColour = back;
	frontColour = fore;
	barSize = size;
	maxValue = max;
	linkedValue = link;
	xPos = x;
	yPos = y;
}


HUDBar::~HUDBar(void)
{
}

void HUDBar::DrawBar()
{
	// Draw on the console relative to the position.
	// The bar is vertical, with a numeric value at the bottom in %
	
	// Fetch linked value.
	int blockValue = (*linkedValue); 

	// Constrain to maximum/minimum size
	if (blockValue > (*maxValue))
	{
		blockValue = (*maxValue);
	}
	if (blockValue < 0)
	{
		blockValue = 0;
	}

	// Get bar fill %
	float barPercent = (float)(*linkedValue) / (float)(*maxValue);


	// Draw bar background
	for(int i = yPos; i < yPos + barSize; i++)
	{
		consoleToDrawOn->setCharBackground(xPos, i, *backColour);
	}

	// Draw bar foreground
	// Draw requisite number of blocks.
	int numBlocksToDraw = (int)(barPercent * barSize);
	for(int i = yPos; i < yPos + numBlocksToDraw; i++)
	{
		consoleToDrawOn->putCharEx(xPos, i, 219, *frontColour, *backColour);
		if(i+1 < yPos + barSize)
		{
			consoleToDrawOn->putCharEx(xPos, i+1, TCOD_CHAR_BLOCK3, *frontColour, *backColour);
		}
	}

	// Draw numeral
	consoleToDrawOn->print(xPos - 1, yPos - 1, "%d%%", (int)(barPercent * 100));
	

}

void Update()
{

	// Currently, does nothing.
}