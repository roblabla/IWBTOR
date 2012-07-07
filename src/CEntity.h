#ifndef CENTITY_H_
#define CENTITY_H_

#include "CAnimation.h"
#include "CSurface.h"
#include "luabind/luabind.hpp"

class CEntity {

    protected:
        CAnimation      Anim_Control;

        SDL_Surface*    Surf_Entity;

    public:
        float           X;
        float           Y;

        int             Width;
        int             Height;

        int             AnimState;

    public:
        CEntity();

        virtual ~CEntity();

    public:
        virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        virtual void OnLoop();

        virtual void OnRender(SDL_Surface* Surf_Display);

        virtual void OnCleanup();
};

struct CEntityWrapper : CEntity, luabind::wrap_base {
	CEntityWrapper(): CEntity() {}
	virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames)
	{
	//	return call_member<>();
	}
	virtual void OnLoop()
	{
		luabind::call_member<void>();
	}
    static void default_OnLoop(CEntity* ptr)
    {
        return ptr->CEntity::OnLoop();
    }

};
#endif /* CENTITY_H_ */
