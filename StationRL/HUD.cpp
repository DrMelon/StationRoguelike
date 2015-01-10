#include "HUD.h"


HUD::HUD(TCODConsole* mainCon)
{
	// Link to main HUD
	mainConsole = mainCon;


	// Create HUD Consoles
	infoConsole = new TCODConsole(25, 80); //25 Wide, 80 Tall, at right side of screen
	fdiskConsole = new TCODConsole(15, 16); // 15x15 mini console inside info console
	logConsole = new TCODConsole(80, 15); // 80 Wide, 15 Tall, at bottom of screen

	infoConsole->setDefaultBackground(TCODColor::darkGrey);
	fdiskConsole->setDefaultBackground(TCODColor::darkestGrey);
	logConsole->setDefaultBackground(TCODColor::darkGrey);

	// Create Colours
	healthColor = new TCODColor(255, 60, 60);
	healthColorBack = new TCODColor(127, 30, 30);

	myPlayerDotHealth = new int(50);
	myPlayerDotMaxHealth = new int(100);

	// Create HUD bars (x, y relative to infoConsole), length 8, maxval 100 (would be player max health)
	healthBar = new HUDBar(infoConsole,  healthColor,  healthColorBack,  8,  myPlayerDotMaxHealth,  myPlayerDotHealth,  5,  5);
}

void HUD::DrawHUD()
{

	// Clear the consoles
	infoConsole->clear();
	fdiskConsole->clear();
	logConsole->clear();

	// Draw Rectangles for the consoles
	infoConsole->printFrame(0, 0, 25, 80, true, TCOD_BKGND_SET, "EVA_DISP_0");
	fdiskConsole->setDefaultForeground(TCODColor::white);
	fdiskConsole->printFrame(0, 0, 15, 15, true, TCOD_BKGND_SET, "FDISK_0");
	logConsole->printFrame(0, 0, 80, 15,  true, TCOD_BKGND_SET, "EVA_TTYL_0");

	// Draw log
	// Draw HUDBars
	healthBar->DrawBar();

	// Draw fdisk slot
	fdiskConsole->setDefaultForeground(TCODColor::black);
	// PRINT DIS
	//char line = 196;
	//char halfblock = 254;
	//char fullblock = 219;
	//──────■██■─────



	// Blit consoles onto main console
	TCODConsole::root->blit(fdiskConsole, 0, 0, 15, 16, infoConsole, 5, 35);
	TCODConsole::root->blit(infoConsole, 0, 0, 25, 80, mainConsole, 80-25, 0);
	TCODConsole::root->blit(logConsole, 0, 0, 80, 25, mainConsole, 0, 80-15);


}

void HUD::Update()
{
	// Update stuff
	//healthBar->Update();
}

HUD::~HUD(void)
{
}
