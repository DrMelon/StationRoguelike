#include "StateMachine.h"


StateMachine::StateMachine(void)
{
}

void StateMachine::Run()
{

	// While we have states to run through...
	while(stateList.size() > 0)
	{

		// Check if the current state wants to advance to the next state.
		if(stateList.back()->goNextState == true)
		{
			// If there is a next state, push it on.
			if(stateList.back()->nextState != 0)
			{
				AddState(stateList.back()->nextState);
			}
			// If there isn't, pop off a state.
			else
			{
				PopState();
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
