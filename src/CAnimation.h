/*
 * CAnnimation.h
 *
 *  Created on: Jun 9, 2012
 *      Author: roblabla
 */

#ifndef CANIMATION_H_
#define CANIMATION_H_
#include <SDL/SDL.h>

class CAnimation {
	private:
		int CurrentFrame;
		int FrameInc;

		int FrameRate;
		long OldTime;

	public:
		int MaxFrames;
		bool Oscillate;

		CAnimation();

		void OnAnimate();

		void SetFrameRate(int Rate);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();
};

#endif /* CANNIMATION_H_ */
