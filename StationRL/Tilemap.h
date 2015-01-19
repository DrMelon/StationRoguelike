#pragma once

//@Author: J. Brown / DrMelon
//@Purpose: Tilemaps hold the state of a walkable map. Tilemaps are generated from a seed and starting conditions; these can be generated randomly,
// or once world-generation is added, provided as part of the overworld map process.



// Starting conditions describe what kind of map needs to be generated.

// Tiletypes are used to generate tile types from the generic tile objects.

#include "Tile.h"
#include <libtcod.hpp>
#include <vector>


class Tilemap
{
	public:
		enum StartCondition
		{
			STATION, STATION_WRECK, OUTPOST, OUTPOST_WRECK, MODULE, MODULE_WRECK, MODULE_CLUSTER, MODULE_CLUSTER_WRECK, ASTEROID, ASTEROID_BASE, ASTEROID_BASE_WRECK
		};

		enum TileType
		{
			SPACE, METAL_FLOOR, METAL_WALL, TILED_FLOOR, TILED_WALL, REINFORCED_WALL, REINFORCED_FLOOR
		};



	public:
		Tilemap(int sx, int sy);
		~Tilemap(void);
		
		// Members
		int seed;
		int sizeX, sizeY;
		std::vector<Tile*> tileMap;
		TCODRandom* randomizer;

		void GenerateMap(int newseed, StartCondition startingconditions);
		Tile* TileFromType(TileType t);
		Tile* GetTile(int x, int y);
		void SetTile(int x, int y, Tile* t);
		void ModifyTile(int x, int y, TileType t);
		void DrawOnConsole(TCODConsole* drawConsole, int offsetx, int offsety);

		//void SaveMap(char* filename);
		//void LoadMap(char* filename);


};

