/*
 * CAppState.h
 *
 *  Created on: Jun 4, 2012
 *      Author: roblabla
 */

#ifndef CAPPSTATE_H_
#define CAPPSTATE_H_

#include "CEvent.h"

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

#endif /* CAPPSTATE_H_ */
