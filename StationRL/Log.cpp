#include "Log.h"


Log::Log(void)
{

}

void Log::SendMessage(std::string text, TCODColor* col)
{
	//Push a new message onto the list
	LogMessage* newMsg = new LogMessage();
	newMsg->MessageText = text;
	newMsg->MessageColor = col;
	messageList.push_back(newMsg);
}

void Log::Draw(int x, int y, int numLines, TCODConsole* toDrawOn)
{
	if(messageList.empty())
	{
		return;
	}

	if(numLines > messageList.size())
	{
		numLines = messageList.size();
	}

	// Print the messages in the requisite colours!
	for(int i = 0; i < numLines; i++)
	{
		LogMessage* currentMessage = messageList.at((messageList.size()-1) - i);
		
		toDrawOn->setDefaultForeground(*currentMessage->MessageColor);
		toDrawOn->print(x, y+numLines-i, currentMessage->MessageText.c_str());
	}
}

