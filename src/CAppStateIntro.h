#ifndef CAPPSTATEINTRO_H
#define CAPPSTATEINTRO_H

#include "SDL.h"
#include "SDL_mixer.h"

#include "defines.h"

#include "CSurface.h"
#include "CCamera.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "CEntityManager.h"

#include "CAppState.h"

#define DIR_BACKGROUND "background.png"
#define DIR_STORY "story.png"
#define DIR_START_MUSIC "megaman1.ogg"

#define STORY_FRAMES 63
#define STORY_FRAME_DELAY 500

#define CAMERA_START_X 0
#define CAMERA_START_Y 0

class CAppStateIntro: public CAppState {
		private:
			static CAppStateIntro Instance;

			SDL_Surface* Surf_Background;
			SDL_Surface* Surf_Title;
			SDL_Surface* Surf_Story;
			float y;
			int StartTime;
			CAnimation Anim_Story;

		private:
			CAppStateIntro();

		public:
			void OnActivate();

			void OnDeactivate();

			void OnLoop();

			void OnRender(SDL_Surface* Surf_Display);

		public:
			static CAppStateIntro* GetInstance();
};

#endif
