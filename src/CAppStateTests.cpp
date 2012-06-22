
#include "CAppStateTests.h"

CAppStateTests CAppStateTests::Instance;

CAppStateTests::CAppStateTests() {
}

void CAppStateTests::OnActivate() {
	CLuaManager lua = CLuaManager();
	lua.RunFile("hi");
 }

void CAppStateTests::OnDeactivate() {
}

void CAppStateTests::OnLoop() {
}

void CAppStateTests::OnRender(SDL_Surface* Surf_Display) {
}

CAppStateTests* CAppStateTests::GetInstance() {
	return &Instance;
}
