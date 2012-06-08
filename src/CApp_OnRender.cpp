#include "CApp.h"

void CApp::OnRender(){
	CAppStateManager::OnRender(Surf_Display);
    //Update the screen
    if( SDL_Flip(Surf_Display) == -1 )
    {
        return;
    }
}
