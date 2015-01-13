#pragma once

//@Author: J. Brown / DrMelon
//@Purpose: This is the game's logging system. This allows messages to be raised from anywhere in the program, and end up in the log. 
// The log contains all the information needed, but will only draw the last few lines when told to draw.
// It is a singleton class.

#include <libtcod.hpp>
#include <string>
#include <vector>

struct LogMessage
{
	std::string MessageText;
	TCODColor* MessageColor;
};

class Log
{
	public:		
		static Log& instance()
		{
			static Log* instance = new Log();
			return *instance;
		}


		void SendMessage(std::string text, TCODColor* col);
		void Draw(int x, int y, int numLines, TCODConsole* toDrawOn);


		std::vector<LogMessage*> messageList;

	private:
		Log(void);

};

