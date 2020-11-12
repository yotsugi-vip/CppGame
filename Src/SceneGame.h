#pragma once
#include "SceneBase.h"
#include "Task.h"

class SceneGame : public SceneBase, public EventBase, public Task
{
public:
	void Draw();
	void Update();

public:
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
	int HitCircle_x;
	int HitCircle_y;
	int Frame;
} T_Player_Info;