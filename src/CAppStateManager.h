#ifndef CAPPSTATEMANAGER_H
#define CAPPSTATEMANAGER_H

#include "CAppState.h"

// Refer to your Other App States Here
#include "CAppStateIntro.h"
#include "CAppStateTests.h"

//=============================================================================
enum APPSTATE{
	// Add your Other App States Here
	APPSTATE_NONE,
	APPSTATE_INTRO,
	APPSTATE_TESTS,
	APPSTATE_GAME
};

//=============================================================================
class CAppStateManager {
	private:
		static CAppState* ActiveAppState;

	public:
		static void OnEvent(SDL_Event* Event);

		static void OnLoop();

		static void OnRender(SDL_Surface* Surf_Display);

	public:
		static void SetActiveAppState(APPSTATE AppStateID);

		static CAppState* GetActiveAppState();
};

//=============================================================================

#endif
