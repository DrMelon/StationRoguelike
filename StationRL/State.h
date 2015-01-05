#pragma once

//@Author: J. Brown / DrMelon
//@Purpose: State class for use in State Machine.
//  Abstract class, all states are derived from this class.


#include <libtcod.hpp>

class State
{
	public:
		State(void);
		~State(void);

		virtual void Draw() = 0;
		virtual void Update() = 0;
		State* nextState;
		bool goNextState;

};



