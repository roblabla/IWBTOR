/*
 * CAppStateIntro.cpp
 *
 *  Created on: Jun 4, 2012
 *      Author: roblabla
 */

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#include "CAppStateIntro.h"
#include <iostream>
#include "CAppStateManager.h"

CAppStateIntro CAppStateIntro::Instance;

CAppStateIntro::CAppStateIntro() {
	Surf_Background = NULL;
	Surf_Title = NULL;
	y = 0;
}

void CAppStateIntro::OnActivate() {
	// Load Simple Logo
	Surf_Background = CSurface::OnLoad("background.png");
	StartTime = SDL_GetTicks();
	CCamera::CameraControl.SetPos(0,0);
}

void CAppStateIntro::OnDeactivate() {
	if(Surf_Background) {
		SDL_FreeSurface(Surf_Background);
		Surf_Background = NULL;
	}
	if(Surf_Title) {
		SDL_FreeSurface(Surf_Title);
		Surf_Title = NULL;
	}
}

void CAppStateIntro::OnLoop() {
	if(y != Surf_Background->h)
		std::cout << y;
		CCamera::CameraControl.OnMove(0,0.1);
	if(StartTime + 3000 < SDL_GetTicks()) {
	//	CAppStateManager::SetActiveAppState(APPSTATE_GAME);
	}
}

void CAppStateIntro::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Background) {
		CSurface::OnDraw(Surf_Display, Surf_Background,0, Surf_Display->h-Surf_Background->h+y);
	}
}

CAppStateIntro* CAppStateIntro::GetInstance() {
	return &Instance;
}
