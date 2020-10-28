#pragma once
#include <DxLib.h>
#include <list>

class Fps
{
public:
	static int count;
	static int base_time;
	static std::list<int> fpsAveQueue;
	static int fpsAve;
	static int processingTime;
	static void Wait(void);
};

