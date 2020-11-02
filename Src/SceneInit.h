#pragma once
#include "SceneBase.h"
class SceneInit : public SceneBase, public EventBase
{
public:
	void Draw();
	void End();
	void Initialize();
	void Input();

public:
	void Event_Push_Button(int button);
	void Event_Release_Button(int button);
	void Event_Keep_Button(int button, int onoff);
};