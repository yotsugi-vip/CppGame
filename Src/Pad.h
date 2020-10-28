#pragma once
typedef struct {
	int X;
	int Y;
	unsigned char Push_Button;
} T_Stick;

typedef struct {
	unsigned int Left;
	unsigned int Right;
	unsigned int Up;
	unsigned int Down;
}T_Direction_Pad;

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

class Pad
{
public:
	static T_Stick L_Stick;
	static T_Stick R_Stick;
	static T_Direction_Pad D_Pad;
	static T_Right_Buttons R_Buttons;
	static T_Top_Buttons L_Top;
	static T_Top_Buttons R_Top;
	static unsigned char Share_Button;
	static unsigned char Options_Button;
	static unsigned char Touch_Pad;
	static unsigned char Home_Button;

public:
	static void GetPadInput(void);
};

