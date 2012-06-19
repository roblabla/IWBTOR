/*
 * CEntityManager.h
 *
 *  Created on: Jun 18, 2012
 *      Author: roblabla
 */

#ifndef CENTITYMANAGER_H_
#define CENTITYMANAGER_H_
#include <vector>
#include "CEntity.h"
class CEntityManager {
	private:
        static std::vector<CEntity*>    EntityList;

	public:
        static void addInEntityList(CEntity entity);
        static void OnLoop();
        static void OnRender(SDL_Surface *Surf_Display);
        static void OnCleanup();
	public:
        CEntityManager();
		virtual ~CEntityManager();
};

#endif /* CENTITYMANAGER_H_ */
