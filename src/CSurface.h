/*
 * CSurface.h
 *
 *  Created on: Jun 5, 2012
 *      Author: roblabla
 */

#ifndef CSURFACE_H_
#define CSURFACE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

//==============================================================================
class CSurface {
	public:
		CSurface();

	public:
		static SDL_Surface* OnLoad(char* File);

		static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

		static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

		static bool Transparent(SDL_Surface* Surf_Dest, int R, int G, int B);
};

//==============================================================================


#endif /* CSURFACE_H_ */
