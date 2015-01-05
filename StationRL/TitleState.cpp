#include "TitleState.h"


TitleState::TitleState(void)
{
	// Create own console.
	myConsole = new TCODConsole(80, 80);
	
	// Load title screen image
	titleImage = new TCODImage("data/title.png");

	// Defaults
	nextState = 0;
	goNextState = false;
	isFading = true;
	fadeAmt = 0.0f;

	titleImage->setKeyColor(TCODColor(255, 0, 255));
	myConsole->clear();

	// Blit image onto console.
	titleImage->blit2x(myConsole, 0, 0);
}

void TitleState::Draw()
{
	
	// Blit own console onto screen.
	TCODConsole::root->blit(myConsole, 0, 0, 80, 80, TCODConsole::root, 0, 0, fadeAmt, fadeAmt);
}

void TitleState::Update()
{
	// Push any key to advance to next state!
	TCOD_key_t keyPressed = myConsole->checkForKeypress();

	if(fadeAmt < 1.0f)
	{
		fadeAmt += 0.1f * (1.0/60.0);
	}
	else
	{
		isFading = false;
	}

	if(keyPressed.vk != TCODK_NONE && isFading == false)
	{
		goNextState = true;
	}

}

TitleState::~TitleState(void)
{
}
