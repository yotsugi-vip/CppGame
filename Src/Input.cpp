#include "Input.h"
#include "Pad.h"
#include "SceneManager.h"

T_INPUT Input::now;
T_INPUT Input::pre;


static int GetInputInfo(int val, int judge_on);

int GetInputInfo(int val, int judge_on) {
	int ret;
	if (val == judge_on) {
		ret = static_cast<int>(E_Button_Info::Button_On);
	}
	else {
		ret = static_cast<int>(E_Button_Info::Button_Off);
	}
	return ret;
}

void Input::EventLoop() {
	// »έΜόΝπΫΆ
	Input::pre = Input::now;

	// InputξρπXV
	Input::GetInput();

	// Z
	if (Input::now.Circle != Input::pre.Circle) {
		if (Input::now.Circle == static_cast<int>(E_Button_Info::Button_On)) {
		}
		else {
		}
	}
	else {
		// KEEP
		if (Input::now.Circle == static_cast<int>(E_Button_Info::Button_On)) {
		}
		else {
		}
	}

	// ’Ί
	if (Input::now.Triange != Input::pre.Triange) {

	}

	//  Ί
	if (Input::now.Square != Input::pre.Square) {

	}

	// ~Ί
	if (Input::now.Cross != Input::pre.Cross) {

	}

	// γΊ
	if (Input::now.Up != Input::pre.Up) {

	}

	// ΊΊ
	if (Input::now.Down != Input::pre.Down) {

	}

	// ΆΊ
	if (Input::now.Left != Input::pre.Left) {

	}

	// EΊ
	if (Input::now.Right != Input::pre.Right) {

	}
}

void Input::GetInput() {
	Input::now.Circle = GetInputInfo(Pad::R_Buttons.Circle, 128);
	Input::now.Cross = GetInputInfo(Pad::R_Buttons.Cross, 128);
	Input::now.Triange = GetInputInfo(Pad::R_Buttons.Triangle, 128);
	Input::now.Square = GetInputInfo(Pad::R_Buttons.Square, 128);
	Input::now.Up = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::UP));
	Input::now.Down = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::DOWN));
	Input::now.Left = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::LEFT));
	Input::now.Right = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::RIGHT));
}

void Input::Event_Push_Button(int button) {

}

void Input::Event_Release_Button(int button) {

}


void Input::Event_Keep_Button(int button, int onoff) {

}