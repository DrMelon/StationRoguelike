#include "StateMachine.h"


StateMachine::StateMachine(void)
{
	popAll = false;
}

void StateMachine::Run()
{


	// While we have states to run through... (main loop)
	while(stateList.size() > 0)
	{
		if(popAll == true)
		{
			PopState();
			return;
		}

		// Check if the current state wants to advance to the next state.
		if(stateList.back()->goNextState == true)
		{
			// If there is a next state, push it on.
			if(stateList.back()->nextState != 0)
			{
				AddState(stateList.back()->nextState);
			}
			// If there isn't, begin popping all states
			else
			{
				popAll = true;
				
			}

		}
		 
		// Update/Draw loop.
		if(stateList.size() > 0)
		{
			
			stateList.back()->Update();
			TCODConsole::root->clear();
				stateList.back()->Draw();
			TCODConsole::root->flush();
		}

	}
}

void StateMachine::AddState(State* newState)
{
	stateList.push_back(newState);
}

void StateMachine::PopState()
{
	stateList.pop_back();
}

StateMachine::~StateMachine(void)
{
}
