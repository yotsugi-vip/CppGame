#include "Fps.h"

int Fps::base_time = 0;
int Fps::count = 0;
int Fps::fpsAve = 0;
int Fps::processingTime = 0;

constexpr int FPS = 60;
constexpr int MILLISECOND = 1000;

std::list<int> Fps::fpsAveQueue = {0,0,0,0,0,0,0,0,0,0};

void Fps::Wait(void)
{
	int nowCount = 0;
	int expectedProcessingTime = 0;
	int term = 0;
	int ave = 0;

	if (0 == Fps::count) {
		Fps::base_time = GetNowCount();
	}
	else {
		nowCount = GetNowCount();
		Fps::processingTime = nowCount - Fps::base_time;
		expectedProcessingTime = Fps::count * MILLISECOND / FPS;
		term = expectedProcessingTime - Fps::processingTime;

		if (term > 0) {
			WaitTimer(term);
		}
	}

	Fps::count++;

	if (Fps::processingTime > MILLISECOND || Fps::count >= FPS) {

		Fps::fpsAveQueue.pop_back();
		Fps::fpsAveQueue.push_front(Fps::count);
		Fps::count = 0;
		Fps::processingTime = 0;

		for (auto sum : Fps::fpsAveQueue) {
			ave += sum;
		}

		Fps::fpsAve = ave / Fps::fpsAveQueue.size();
	}
}
