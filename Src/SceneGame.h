#pragma once
#include "SceneBase.h"
class SceneGame : public SceneBase, public EventBase
{
public:
	void Draw();
	void Initialize();
	void Input();
	void End();

public:
	void Event_Push_Button(int button);
	void Event_Release_Button(int button);
	void Event_Keep_Button(int button, int onoff);
};

