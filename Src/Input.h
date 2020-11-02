#pragma once
#include "SceneBase.h"

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

class Input //: public EventBase
{
public:
	static T_INPUT now;
	static T_INPUT pre;

public:
	static void EventLoop();
	static void GetInput();
	static void Input_Main();

public:
	static void Event_Push_Button(E_Button_Type button);
	static void Event_Release_Button(E_Button_Type button);
	static void Event_Keep_Button(E_Button_Type button, E_Button_State onoff);
};