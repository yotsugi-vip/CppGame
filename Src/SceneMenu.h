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
	void Event_Push_Button(int button);
	void Event_Release_Button(int button);
	void Event_Keep_Button(int button, int onoff);
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