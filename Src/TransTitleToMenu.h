#pragma once
#include "Task.h"
#include "SceneBase.h"

class TransTitleToMenu : public Task, public EventBase, public SceneBase
{
public:
	void Update();
	void Draw();

public:
	void Initialize();
	void End();

public:
	void Event_Push_Button(E_Button_Type button);
	void Event_Release_Button(E_Button_Type button);
	void Event_Keep_Button(E_Button_Type button, E_Button_State onoff);
};

