#include "GameState.h"


GameState::GameState(void)
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

	theTilemap = new Tilemap(80-26, 80-16);
	theTilemap->GenerateMap(0, Tilemap::STATION);

	theHUDCorrupt = new CorruptEffect(myConsole);
}

void GameState::Draw()
{
	myConsole->clear();

	// Draw tiles
	theTilemap->DrawOnConsole(myConsole, 0, 0);


	// Draw HUD
	theHUD->DrawHUD();
	
	// Corrupt screen
	theHUDCorrupt->Update();
	

	// Blit own console onto screen.
	TCODConsole::root->blit(myConsole, 0, 0, 80, 80, TCODConsole::root, 0, 0);
}

void GameState::Update()
{
	// Push any key to advance to next state!
	TCOD_key_t keyPressed = myConsole->checkForKeypress();


	if(keyPressed.vk == TCODK_ENTER)
	{
		goNextState = true;
	}
}

GameState::~GameState(void)
{
}
