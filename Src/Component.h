#pragma once
class Component
{
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
};