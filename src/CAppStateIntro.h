/*
 * CAppStateIntro.h
 *
 *  Created on: Jun 4, 2012
 *      Author: roblabla
 */

#ifndef CAPPSTATEINTRO_H_
#define CAPPSTATEINTRO_H_

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "CAppState.h"
#include "CSurface.h"
#include "CCamera.h"
#include "CAnimation.h"
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

#endif /* CAPPSTATEINTRO_H_ */
