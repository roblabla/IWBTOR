
#include "CLuaManager.h"

CLuaManager::CLuaManager() {
	myLuaState = luaL_newstate();
	luabind::open(myLuaState);

	SetupEnviron();
}

CLuaManager::~CLuaManager() {
	 lua_close(myLuaState);
}

void CLuaManager::SetupEnviron() {
	/*luabind::module(myLuaState)			//SETUP ENTITY CLASS. MOST IMPORTANT ONE.
	[
	 luabind::class_<CEntity>("Entity")			// Entity. It doesn't matter if it's not the same as the actual class.
	 .def(luabind::constructor<>())     // Defines an empty constructor
//	 .def("OnLoad", luabind::tag_function<void()>(&CEntity::OnLoad))	// Defines OnLoad
	 .def("OnLoop", &CEntity::OnLoop)	// Defines OnLoop, etc...
//	 .def("OnRender", &CEntity::OnRender)
	 .def("OnCleanup", &CEntity::OnCleanup)
	];*/

	//Why the above does not work : http://www.rasterbar.com/products/luabind/docs.html#deriving-in-lua

	//I need a wrapper.
}

void CLuaManager::RunFile(char* file) {
	luaL_dofile(myLuaState,file);
}
