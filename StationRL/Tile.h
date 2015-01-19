#pragma once
//@Author: J. Brown / DrMelon
//@Purpose: The tile class is used to make the map. O:!

#include <libtcod.hpp>
#include <string>

class Tile
{
	public:
		Tile(void);
		~Tile(void);

		// Tile collision stuff
		bool isOpaque;
		bool isSolid;
		bool isWalkable; // Note that solid and walkable aren't the same thing! Some tiles could be jumped over or flown over, but not walked over.
		
		//GasInfo atmosphericContent; // This holds information about gases, pressures, and temperatures. Need to know, for space stuff!
		int damageRating;
		int maxDamage;

		TCODColor* tileColor;
		std::string tileName;
		std::string tileDesc;


};

