#pragma once
#include "SceneBase.h"
#include "Task.h"

constexpr int BUTTON_X_0 = 980;
constexpr int BUTTON_X_1 = 950;
constexpr int BUTTON_X_2 = 920;
constexpr int BUTTON_X_3 = 890;
constexpr int BUTTON_X_4 = 860;

constexpr int BUTTON_Y_0 = 400;
constexpr int BUTTON_Y_1 = 500;
constexpr int BUTTON_Y_2 = 600;
constexpr int BUTTON_Y_3 = 700;
constexpr int BUTTON_Y_4 = 800;

constexpr int TITLE_MENU_X = 20;
constexpr int TITLE_MENU_Y = 20;

typedef struct {
	int x;
	int y;
	const char* string;
	void (*function)();
}T_MENU_BUTTON;

class SceneMenu : public SceneBase, public EventBase, public Task
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