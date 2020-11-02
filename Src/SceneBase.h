#pragma once

enum class E_Button_State {
	Button_On = 0,
	Button_Off,
	MAX
};

enum class E_Button_Type
{
	Circle = 0,
	Cross,
	Triangle,
	Square,
	Up,
	Down,
	Left,
	Right,
	MAX
};


class SceneBase {
public:
	virtual void Draw() = 0;
	virtual void Input() = 0;
	virtual void Initialize() = 0;
	virtual void End() = 0;
};

class EventBase {
public:
	virtual void Event_Push_Button(E_Button_Type button) = 0;
	virtual void Event_Release_Button(E_Button_Type button) = 0;
	virtual void Event_Keep_Button(E_Button_Type button, E_Button_State onoff) = 0;
};