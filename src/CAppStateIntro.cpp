#include "CAppStateIntro.h"

CAppStateIntro CAppStateIntro::Instance;

CAppStateIntro::CAppStateIntro() {
	Surf_Background = NULL;
	Surf_Title = NULL;
	Surf_Story = NULL;
}

void CAppStateIntro::OnActivate() {
    if ((Surf_Background = CSurface::OnLoad(DIR_BACKGROUND)) == NULL) {
        fprintf(stderr, "Unable to load: %s\n", DIR_BACKGROUND);
        exit(1);
    }
    if ((Surf_Story = CSurface::OnLoad(DIR_STORY)) == NULL) {
        fprintf(stderr, "Unable to load: %s\n", DIR_STORY);
        exit(1);
    }

	Anim_Story.MaxFrames = STORY_FRAMES;
	Anim_Story.SetFrameRate(STORY_FRAME_DELAY);
	StartTime = SDL_GetTicks();
	CCamera::CameraControl.SetPos(CAMERA_START_X, CAMERA_START_Y);

	if(Mix_OpenAudio(SDL_AUDIO_RATE, SDL_AUDIO_FORMAT, SDL_AUDIO_CHANNELS, SDL_AUDIO_BUFFER) != 0) {
		fprintf(stderr, "Unable to initialize audio: %s\n", Mix_GetError()); //Mix_GetError doesn't work, so fuck it.
		exit(1);
	}
	Mix_Music *sound = NULL;
    if ((sound = Mix_LoadMUS(DIR_START_MUSIC)) == NULL) {
        fprintf(stderr, "Unable to load: %s\n", DIR_START_MUSIC);
        exit(1);
    }

	Mix_PlayMusic(sound, 0);
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
	CEntityManager::OnLoop();
	if(Anim_Story.GetCurrentFrame() != 61)
		Anim_Story.OnAnimate();
	else
		CCamera::CameraControl.OnMove(0,0.5);

}

void CAppStateIntro::OnRender(SDL_Surface* Surf_Display) {
	CEntityManager::OnRender(Surf_Display);
	if(Surf_Background) {
		CSurface::OnDraw(Surf_Display, Surf_Background,0, Surf_Display->h-Surf_Background->h-165+CCamera::CameraControl.GetY());
		CSurface::OnDraw(Surf_Display, Surf_Story,0, Surf_Display->h-165+CCamera::CameraControl.GetY(),0, Anim_Story.GetCurrentFrame() * 165, 800, 165);
	}
}

CAppStateIntro* CAppStateIntro::GetInstance() {
	return &Instance;
}
