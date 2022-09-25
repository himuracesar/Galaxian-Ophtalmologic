#pragma once
#ifndef WIN_TIMER_H
#define WIN_TIMER_H

#include "../Core/DogStdafx.h"

class WinTimer
{
	public:
		WinTimer();
		~WinTimer();

		DOGvoid Release();

		DOGfloat TotalTime()const;  // in seconds
		DOGfloat DeltaTime()const; // in seconds

		DOGvoid Reset(); // Call before message loop.
		DOGvoid Start(); // Call when unpaused.
		DOGvoid Stop();  // Call when paused.
		DOGvoid Tick();  // Call every frame.

	private:
		DOGdouble mSecondsPerCount;
		DOGdouble mDeltaTime;

		DOGint64 mBaseTime;
		DOGint64 mPausedTime;
		DOGint64 mStopTime;
		DOGint64 mPrevTime;
		DOGint64 mCurrTime;

		bool mStopped;
};

#endif