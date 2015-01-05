#pragma once
#include "state.h"
class TitleState :	public State
{
	public:
		TitleState(void);
		~TitleState(void);

		void Update();
		void Draw();

	private:

		// Has its own render console
		TCODConsole* myConsole;

		// Loads a title image
		TCODImage* titleImage;

		// Fade-in-from-black parameters
		bool isFading;
		float fadeAmt;
};

