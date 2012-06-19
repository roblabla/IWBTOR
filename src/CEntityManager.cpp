/*
 * CEntityManager.cpp
 *
 *  Created on: Jun 18, 2012
 *      Author: roblabla
 */

#include "CEntityManager.h"

std::vector<CEntity*> CEntityManager::EntityList;

CEntityManager::CEntityManager() {
	// TODO Auto-generated constructor stub

}

CEntityManager::~CEntityManager() {
	// TODO Auto-generated destructor stub
}

void CEntityManager::addInEntityList(CEntity entity){
	CEntityManager::EntityList.push_back(&entity);
}

void CEntityManager::OnLoop(){
	for(int i = 0;i < CEntityManager::EntityList.size();i++) {
		if(!CEntityManager::EntityList[i]) continue;
		CEntityManager::EntityList[i]->OnLoop();
	}
}

void CEntityManager::OnRender(SDL_Surface *Surf_Display){
	for(int i = 0;i < CEntityManager::EntityList.size();i++) {
	    if(!CEntityManager::EntityList[i]) continue;

	    CEntityManager::EntityList[i]->OnRender(Surf_Display);
	}
}

void CEntityManager::OnCleanup(){
	for(int i = 0;i < CEntityManager::EntityList.size();i++) {
		if(!CEntityManager::EntityList[i]) continue;
		CEntityManager::EntityList[i]->OnCleanup();
	}
	CEntityManager::EntityList.clear();
}

