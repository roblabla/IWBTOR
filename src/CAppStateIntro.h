/*
 * CAppStateIntro.h
 *
 *  Created on: Jun 4, 2012
 *      Author: roblabla
 */

#ifndef CAPPSTATEINTRO_H_
#define CAPPSTATEINTRO_H_

#include <SDL/SDL.h>
#include "CAppState.h"
#include "CSurface.h"
#include "CCamera.h"
class CAppStateIntro: public CAppState {
		private:
			static CAppStateIntro Instance;

			SDL_Surface* Surf_Background;
			SDL_Surface* Surf_Title;
			float y;
			int StartTime;

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
