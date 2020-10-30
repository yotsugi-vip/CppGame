#pragma once
#include "SceneBase.h"

class SceneMenu : public SceneBase
{
	void Draw();
	void Input();
	void Initialize();
	void End();
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