#pragma once
#include "SceneBase.h"

enum class E_Button_Info {
	Button_On = 0,
	Button_Off,
};

typedef struct {
	int Up;
	int Down;
	int Left;
	int Right;
	int Circle;
	int Triange;
	int Square;
	int Cross;
} T_INPUT;

class Input : public EventBase
{
public:
	static T_INPUT now;
	static T_INPUT pre;

public:
	static void EventLoop();
	static void GetInput();

public:
	void Event_Push_Button(int button);
	void Event_Release_Button(int button);
	void Event_Keep_Button(int button, int onoff);
};