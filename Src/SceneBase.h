#pragma once
class SceneBase {
public:
	virtual void Draw() = 0;
	virtual void Input() = 0;
	virtual void Initialize() = 0;
	virtual void End() = 0;
};

class EventBase {
public:
	virtual void Event_Push_Button(int button) = 0;
	virtual void Event_Release_Button(int button) = 0;
	virtual void Event_Keep_Button(int button, int onoff) = 0;
};