#ifndef CAPP_H
#define CAPP_H

#include "SDL.h"

#include "defines.h"

#include "CAppStateManager.h"
#include "CFPS.h"

#include "CEvent.h"
#include "CSurface.h"

//==============================================================================
class CApp : public CEvent {
    private:
        bool Running;
        SDL_Surface* Surf_Display;

    public:
        CApp();
        int OnExecute();

    public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnLoop();
        void OnRender();
        void OnExit();
        void OnCleanup();
};
//==============================================================================

#endif
