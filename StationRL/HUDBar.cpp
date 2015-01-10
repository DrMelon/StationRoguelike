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

	int startPoint = yPos;
	int endPoint = startPoint + barSize;

	// Draw bar background
	for(int i = 0; i < barSize; i++)
	{
		consoleToDrawOn->setCharBackground(xPos, i, *backColour);
	}

	// Draw bar foreground
	int blockValue = (*linkedValue); // Fetch linked value.

	// Constrain to maximum/minimum size
	if (blockValue > (*maxValue))
	{
		blockValue = (*maxValue);
	}
	if (blockValue < 0)
	{
		blockValue = 0;
	}

	// Draw requisite number of blocks.
	int numBlocksToDraw = ((*linkedValue) / (*maxValue)) * barSize;
	for(int i = 0; i < numBlocksToDraw; i++)
	{
		consoleToDrawOn->setCharBackground(xPos, i, *frontColour);
	}

	// Draw numeral
	consoleToDrawOn->print(xPos - 1, yPos - 1, "%d%%", ((*linkedValue) / (*maxValue)) * 100);
	

}

void Update()
{

	// Currently, does nothing.
}