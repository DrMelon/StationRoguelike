#pragma once

//@Author: J. Brown / DrMelon
//@Purpose: This class is a simple finite state machine.

#include "State.h"
#include <vector>

class StateMachine
{
	public:
		StateMachine(void);
		~StateMachine(void);

		void Run();
		void AddState(State* newState);
		void PopState();

	private:
		std::vector<State*> stateList;
};

