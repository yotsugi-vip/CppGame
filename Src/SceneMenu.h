#pragma once
#include "SceneBase.h"

class SceneMenu : public SceneBase, public EventBase
{
public:
	void Draw();
	void Input();
	void Initialize();
	void End();

public:
	void Event_Push_Button(E_Button_Type button);
	void Event_Release_Button(E_Button_Type button);
	void Event_Keep_Button(E_Button_Type button, E_Button_State onoff);
};

class Button {
public:
	int X_start;
	int X_end;
	int Y_start;
	int Y_end;
	const char* String;
	bool isSelected;
	void (*func)();
	void Draw();
};