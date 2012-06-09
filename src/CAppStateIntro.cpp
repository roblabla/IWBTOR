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
	Surf_Story = NULL;
}

void CAppStateIntro::OnActivate() {
	// Load Simple Logo
	Surf_Background = CSurface::OnLoad("background.png");
	Surf_Story = CSurface::OnLoad("story.png");
	Anim_Story.MaxFrames = 63;
	Anim_Story.SetFrameRate(500);
	StartTime = SDL_GetTicks();
	CCamera::CameraControl.SetPos(0,0);

	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 4096;

	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError());
		exit(1);
	}
	Mix_Music *sound = NULL;

	sound = Mix_LoadMUS("megaman1.ogg");

	Mix_PlayMusic(sound,0);
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
	if(Anim_Story.GetCurrentFrame() != 61)
		Anim_Story.OnAnimate();
	else
		CCamera::CameraControl.OnMove(0,0.5);
}

void CAppStateIntro::OnRender(SDL_Surface* Surf_Display) {
	if(Surf_Background) {
		CSurface::OnDraw(Surf_Display, Surf_Background,0, Surf_Display->h-Surf_Background->h-165+CCamera::CameraControl.GetY());
		CSurface::OnDraw(Surf_Display, Surf_Story,0, Surf_Display->h-165+CCamera::CameraControl.GetY(),0, Anim_Story.GetCurrentFrame() * 165, 800, 165);
	}
}

CAppStateIntro* CAppStateIntro::GetInstance() {
	return &Instance;
}
