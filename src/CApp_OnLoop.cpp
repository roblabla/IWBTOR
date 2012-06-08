#include "CApp.h"

void CApp::OnLoop(){
	CAppStateManager::OnLoop();

	CFPS::FPSControl.OnLoop();
}
