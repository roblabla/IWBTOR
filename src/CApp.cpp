#include "CApp.h"

CApp::CApp() {
    Running = true;
}

/*CApp::~CApp()
{
    //dtor
}*/

int CApp::OnExecute() {
    if (OnInit() == false) {
        return 1;
    }
    SDL_Event event;

    while(Running) {
        while(SDL_PollEvent(&event)) {
            OnEvent(&event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}

bool CApp::OnInit() {
    if(SDL_Init(SDL_INIT_ARGS) != 0) {
		return false;
	}

	if((Surf_Display = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

    SDL_WM_SetCaption(WINDOW_TITLE, WINDOW_ICON_TEXT);

	CAppStateManager::SetActiveAppState(APPSTATE_INTRO);

	return true;
}

void CApp::OnEvent(SDL_Event *Event) {
    CEvent::OnEvent(Event);
    CAppStateManager::OnEvent(Event);
}

void CApp::OnLoop() {
	CAppStateManager::OnLoop();
	CFPS::FPSControl.OnLoop();
}

void CApp::OnRender() {
	CAppStateManager::OnRender(Surf_Display);
    //Update the screen
    SDL_Flip(Surf_Display);
    //no point checking for an error we're not going to catch
    /*if( SDL_Flip(Surf_Display) != 0 )
    {
        return;
    }*/
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnCleanup() {
	SDL_FreeSurface(Surf_Display);
}

