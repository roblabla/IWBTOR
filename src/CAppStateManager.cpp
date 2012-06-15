#include "CAppStateManager.h"

//=============================================================================
CAppState* CAppStateManager::ActiveAppState = NULL;

//=============================================================================
void CAppStateManager::OnEvent(SDL_Event* EventHolder) {
	if(ActiveAppState) {
	    ActiveAppState->OnEvent(EventHolder);
	}
}

//-----------------------------------------------------------------------------
void CAppStateManager::OnLoop() {
	if(ActiveAppState) {
	    ActiveAppState->OnLoop();
	}
}

//-----------------------------------------------------------------------------
void CAppStateManager::OnRender(SDL_Surface* Surf_Display) {
	if(ActiveAppState) {
	    ActiveAppState->OnRender(Surf_Display);
	}
}

//=============================================================================
void CAppStateManager::SetActiveAppState(APPSTATE AppStateID) {
	if(ActiveAppState != NULL) {
	    ActiveAppState->OnDeactivate();
	}

	// Also, add your App State Here so that the Manager can switch to it
	switch (AppStateID) {
        case APPSTATE_NONE: {
            ActiveAppState = NULL;
            break;
        }

        case APPSTATE_INTRO: {
            ActiveAppState = CAppStateIntro::GetInstance();
            break;
        }

        //case APPSTATE_GAME: {
        //    ActiveAppState = CAppStateGame::GetInstance();
        //    break;
        //}

        default: {
            //set to NULL so we notice something is wrong and fix it
            ActiveAppState = NULL;
            break;
        }
	}

	if(ActiveAppState != NULL) {
	    ActiveAppState->OnActivate();
	}
}

//-----------------------------------------------------------------------------
CAppState* CAppStateManager::GetActiveAppState() {
	return ActiveAppState;
}
