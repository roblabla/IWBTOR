#include <SDL/SDL.h>
#include "CApp.h"

bool CApp::OnInit(){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if((Surf_Display = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);

	CAppStateManager::SetActiveAppState(APPSTATE_INTRO);

	return true;
}
