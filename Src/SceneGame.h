#pragma once
#include "SceneBase.h"
class SceneGame : public SceneBase, public EventBase
{
public:
	void Draw();
	void Initialize();
	void End();

public:
	void Event_Push_Button(E_Button_Type button);
	void Event_Release_Button(E_Button_Type button);
	void Event_Keep_Button(E_Button_Type button, E_Button_State onoff);
};

typedef struct {
	int x;
	int y;
	int Frame;
} T_Player_Info;