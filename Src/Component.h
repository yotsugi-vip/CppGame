#pragma once
#include "DataManager.h"

class Component
{
public:
	static void DrawTextBox(int x, int y, int x2, int y2, TextBox_Color color);
};


class Button {
public:
	int X_start;
	int Y_start;
	int X_end;
	int Y_end;
	const char* String;
	bool isSelected;
	void (*func)();
	void Draw();

public:
};