#ifndef CAPPSTATE_H
#define CAPPSTATE_H

#include "CEvent.h"
#include "CAppStateManager.h"

CAppStateIntro CAppStateIntro::Instance;

class CAppState : public CEvent {
    public:
        CAppState();
        virtual ~CAppState() {}

    public:
        virtual void OnActivate() = 0;

        virtual void OnDeactivate() = 0;

        virtual void OnLoop() = 0;

        virtual void OnRender(SDL_Surface* Surf_Display) = 0;

//        virtual void OnEvent();
};

#endif
