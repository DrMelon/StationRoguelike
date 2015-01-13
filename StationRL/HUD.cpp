#include "HUD.h"


HUD::HUD(TCODConsole* mainCon)
{
	// Link to main HUD
	mainConsole = mainCon;

	logInstance = &Log::instance();

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

	myPlayerDotHealth = new int(15);
	myPlayerDotMaxHealth = new int(100);

	// Create HUD bars (x, y relative to infoConsole), length 8, maxval 100 (would be player max health)
	healthBar = new HUDBar(infoConsole,  healthColorBack,  healthColor,  8,  myPlayerDotMaxHealth,  myPlayerDotHealth,  5,  5);
}

void HUD::DrawHUD()
{

	// Clear the consoles
	infoConsole->clear();
	fdiskConsole->clear();
	logConsole->clear();

	// Draw Rectangles for the consoles
	infoConsole->setDefaultForeground(TCODColor::white);
	infoConsole->printFrame(0, 0, 25, 80, true, TCOD_BKGND_SET, "EVA_DISP_0");
	fdiskConsole->setDefaultForeground(TCODColor::white);
	fdiskConsole->printFrame(0, 0, 15, 15, true, TCOD_BKGND_SET, "FDISK_0");
	logConsole->setDefaultForeground(TCODColor::white);
	logConsole->setDefaultBackground(TCODColor::darkestGrey);
	logConsole->printFrame(0, 0, 80, 15,  true, TCOD_BKGND_SET, "EVA_TTYLOG_0");
	
	

	// Draw log
	// Draw HUDBars
	healthBar->DrawBar();

	// Draw fdisk slot
	fdiskConsole->setDefaultForeground(TCODColor::black);
	// Print floppy disk slot
	//      ■■██■■
	
	int halfblock = 223;
	int fullblock = 219;
	int lightblock = 220;
	

	fdiskConsole->putChar(4, 15, halfblock);
	fdiskConsole->putChar(5, 15, halfblock);
	fdiskConsole->putChar(9, 15, halfblock);
	fdiskConsole->putChar(10, 15, halfblock);

	fdiskConsole->putChar(6, 15, fullblock);
	fdiskConsole->putChar(7, 15, fullblock);
	fdiskConsole->putChar(8, 15, fullblock);

	fdiskConsole->putCharEx(13, 15, lightblock, TCODColor::darkRed, TCODColor::darkestGrey);
		
	
	
	// Draw the log messages
	logInstance->Draw(1, 1, 8, logConsole);
	
	

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
