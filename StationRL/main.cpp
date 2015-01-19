// StationRL
// A roguelike on a space station, loosely based on space disaster films and SS13,  by J. Brown / DrMelon
// 2014-2015

// Using the Doryen Library
#include <libtcod.hpp>
#include "StateMachine.h"
#include "TitleState.h"
#include "MenuState.h"
#include "GameState.h"

// Hide the console window
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")


StateMachine* theGame;


int main()
{
	// Initialize libtcod.
	TCODConsole::initRoot(80, 80, " ", false, TCOD_RENDERER_OPENGL);
	TCODSystem::setFps(30);

	// Initialize FSM
	theGame = new StateMachine();

	// Create, Initialize, and Add States
	TitleState* titleState = new TitleState();
	MenuState* menuState = new MenuState();
	GameState* gameState = new GameState();

	titleState->nextState = menuState;

	theGame->AddState(gameState);
	

	// Run FSM.
	
	theGame->Run();

	// Clean Up States


	return 0;
}