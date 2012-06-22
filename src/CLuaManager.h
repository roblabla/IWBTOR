
#ifndef CLUAMANAGER_H_
#define CLUAMANAGER_H_
//lua and stuff
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}
#include "luabind/luabind.hpp"

//classes to be exposed
#include "CEntity.h"


class CLuaManager {
	private:
		void SetupEnviron();
	public:
		void RunFile(char* hi);
	public:
		CLuaManager();
		~CLuaManager();
	private:
		lua_State *myLuaState;

};

#endif /* CLUAMANAGER_H_ */
