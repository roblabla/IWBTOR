#include "CApp.h"

void CApp::OnEvent(SDL_Event *Event) {
    CEvent::OnEvent(Event);

    CAppStateManager::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}
