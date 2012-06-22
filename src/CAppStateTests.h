
#ifndef CAPPSTATETESTS_H_
#define CAPPSTATETESTS_H_

#include "CAppState.h"
#include "CLuaManager.h"

class CAppStateTests: public CAppState {
		private:
			static CAppStateTests Instance;

		private:
			CAppStateTests();

		public:
			void OnActivate();

			void OnDeactivate();

			void OnLoop();

			void OnRender(SDL_Surface* Surf_Display);

		public:
			static CAppStateTests* GetInstance();
};


#endif /* CAPPSTATETESTS_H_ */
