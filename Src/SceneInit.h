#pragma once
#include "SceneBase.h"
#include "Task.h"

class SceneInit : public SceneBase, public EventBase, public Task
{
public:
	void Draw();
	void Update();

public:
	void End();
	void Initialize();

public:
	void Event_Push_Button(E_Button_Type button);
	void Event_Release_Button(E_Button_Type button);
	void Event_Keep_Button(E_Button_Type button, E_Button_State onoff);
};