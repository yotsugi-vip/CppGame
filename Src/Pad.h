#pragma once
typedef struct {
	int X;
	int Y;
	unsigned char Push_Button;
} T_Stick;

typedef struct {
	unsigned char Circle;
	unsigned char Cross;
	unsigned char Square;
	unsigned char Triangle;
}T_Right_Buttons;

typedef struct {
	unsigned char Button1;
	unsigned char Button2;
	int Triger;
}T_Top_Buttons;

enum class D_Pad_Direction {
	UP = 0,
	DOWN = 18000,
	LEFT = 27000,
	RIGHT = 9000
};

enum class Button_Info {
	RELEASE = 0,
	PUSH = 128
};

class Pad
{
public:
	static T_Stick L_Stick;
	static T_Stick R_Stick;
	static unsigned int D_Pad;
	static T_Right_Buttons R_Buttons;
	static T_Top_Buttons L_Top;
	static T_Top_Buttons R_Top;
	static unsigned char Share_Button;
	static unsigned char Options_Button;
	static unsigned char Touch_Pad;
	static unsigned char Home_Button;

public:
	static void GetPadInput(void);
	static bool IsAbyButtonPush(void);
};

