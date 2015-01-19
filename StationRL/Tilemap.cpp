#include "Tilemap.h"


Tilemap::Tilemap(int sx, int sy)
{
	sizeX = sx;
	sizeY = sy;
	randomizer = 0;
}

void Tilemap::GenerateMap(int newseed, Tilemap::StartCondition startingconditions)
{
	seed = newseed;


	// Set up RNG
	if(randomizer != 0)
	{
		delete randomizer;
		randomizer = 0;
	}

	randomizer = new TCODRandom(seed, TCOD_random_algo_t::TCOD_RNG_CMWC);

	// Create full of space, dotted with random tiles.
	for(int i = 0; i < sizeX*sizeY; i++)
	{
	
		if(randomizer->getInt(0, 10) > 5)
		{
			tileMap.push_back(TileFromType(SPACE));
		}
		else
		{
			tileMap.push_back(TileFromType(METAL_WALL));
		}



	}

}

void Tilemap::DrawOnConsole(TCODConsole* drawConsole, int offsetX, int offsetY)
{
	for(int i = 0; i < sizeX; i++)
	{
		for(int j = 0; j < sizeY; j++)
		{
			drawConsole->setCharBackground(i, j, *GetTile(i+offsetX, j+offsetY)->tileColor);
		}
	}
}

Tile* Tilemap::TileFromType(Tilemap::TileType t)
{
	Tile* newTile = new Tile();
	
	switch(t)
	{
		default: //space tile
		case SPACE:
			newTile->isOpaque = false;
			newTile->isWalkable = false;
			newTile->isSolid = false;
			newTile->damageRating = 0;
			newTile->maxDamage = 0;
			newTile->tileColor = (TCODColor*)&TCODColor::black;
			newTile->tileName = "space";
			newTile->tileDesc = "The final frontier, and if you're not lucky, your grave.";
			break;
		case METAL_FLOOR:
			newTile->isOpaque = false;
			newTile->isWalkable = true;
			newTile->isSolid = false;
			newTile->damageRating = 0;
			newTile->maxDamage = 20;
			newTile->tileColor = (TCODColor*)&TCODColor::lightGrey;
			newTile->tileName = "metal plate floor";
			newTile->tileDesc = "Standard nano-filament metal floor panelling. Cheap, reliable, and easy to clean.";
			break;
		case METAL_WALL:
			newTile->isOpaque = true;
			newTile->isWalkable = true;
			newTile->isSolid = true;
			newTile->damageRating = 0;
			newTile->maxDamage = 20;
			newTile->tileColor = (TCODColor*)&TCODColor::lighterGrey;
			newTile->tileName = "metal plate wall";
			newTile->tileDesc = "Standard nano-filament metal wall plating. The usual building block that most stations are fabricated from these days.";
			break;
		

	}


	return newTile;

}

Tile* Tilemap::GetTile(int x, int y)
{

	if(x < 0)
	{
		x = 0;
	}
	if(x > sizeX)
	{
		x = sizeX;
	}
	if(y < 0)
	{
		y = 0;
	}
	if(y > sizeY)
	{
		y = sizeY;
	}

	// Access tilemap
	int index = y * sizeX + x;
	return tileMap.at(index);
}

void Tilemap::SetTile(int x, int y, Tile* t)
{

}

void Tilemap::ModifyTile(int x, int y, Tilemap::TileType t)
{

}

Tilemap::~Tilemap(void)
{
}
