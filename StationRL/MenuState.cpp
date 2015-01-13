#include "MenuState.h"


MenuState::MenuState(void)
{
	// Create own console.
	myConsole = new TCODConsole(80, 80);
	
	// Get log instance
	logInstance = &Log::instance();

	// Defaults
	nextState = 0;
	goNextState = false;

	myConsole->clear();

	theHUD = new HUD(myConsole);

	theHUDCorrupt = new CorruptEffect(myConsole);

	// Write into log
	logInstance->SendMessage("[ERROR] Suit Integrity Compromised", (TCODColor*)&TCODColor::grey);

}

void MenuState::Draw()
{
	myConsole->clear();

	// Draw HUD
	theHUD->DrawHUD();
	
	// Corrupt screen
	theHUDCorrupt->Update();

	// Blit own console onto screen.
	TCODConsole::root->blit(myConsole, 0, 0, 80, 80, TCODConsole::root, 0, 0);
}

void MenuState::Update()
{
	// Push any key to advance to next state!
	TCOD_key_t keyPressed = myConsole->checkForKeypress();


	if(keyPressed.vk == TCODK_ENTER)
	{
		goNextState = true;
	}
}


MenuState::~MenuState(void)
{
}
