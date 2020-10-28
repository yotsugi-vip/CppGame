#include <DxLib.h>
#include "Pad.h"

T_Stick Pad::L_Stick;
T_Stick Pad::R_Stick;
T_Direction_Pad Pad::D_Pad;
T_Right_Buttons Pad::R_Buttons;
T_Top_Buttons Pad::L_Top;
T_Top_Buttons Pad::R_Top;
unsigned char Pad::Share_Button;
unsigned char Pad::Options_Button;
unsigned char Pad::Touch_Pad;
unsigned char Pad::Home_Button;

void Pad::GetPadInput(void) {
	DINPUT_JOYSTATE input;
	int i;
	int Color;

	// 入力状態を取得
	GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	Pad::L_Stick.X = input.X;
	Pad::L_Stick.Y = input.Y;
	Pad::L_Stick.Push_Button = input.Buttons[10];

	Pad::R_Stick.X = input.Z;
	Pad::R_Stick.Y = input.Rz;
	Pad::R_Stick.Push_Button = input.Buttons[11];

	Pad::L_Top.Button1 = input.Buttons[4];
	Pad::L_Top.Button2 = input.Buttons[5];
	Pad::L_Top.Triger = input.Rx;

	Pad::R_Top.Button1 = input.Buttons[6];
	Pad::R_Top.Button2 = input.Buttons[7];
	Pad::R_Top.Triger = input.Ry;

	Pad::D_Pad.Up = input.POV[0];
	Pad::D_Pad.Down = input.POV[1];
	Pad::D_Pad.Left = input.POV[2];
	Pad::D_Pad.Right = input.POV[3];

	Pad::R_Buttons.Square = input.Buttons[0];
	Pad::R_Buttons.Cross = input.Buttons[1];
	Pad::R_Buttons.Circle = input.Buttons[2];
	Pad::R_Buttons.Triangle = input.Buttons[3];

	Pad::Share_Button = input.Buttons[8];
	Pad::Options_Button = input.Buttons[9];
	Pad::Touch_Pad = input.Buttons[13];
	Pad::Home_Button = input.Buttons[12];
}