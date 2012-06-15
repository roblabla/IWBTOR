#ifndef CFPS_H
#define CFPS_H

#include "SDL.h"

//==============================================================================
class CFPS {
	public:
		static CFPS FPSControl;

	private:
		Uint32     OldTime;
		Uint32     LastTime;

		float 	SpeedFactor;

		int		NumFrames;
		int     Frames;

	public:
		CFPS();

		void    OnLoop();

	public:
		int     GetFPS();

		float   GetSpeedFactor();
};

//==============================================================================
#endif
