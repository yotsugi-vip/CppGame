#include "Input.h"
#include "Pad.h"
#include "SceneManager.h"
#include "DataManager.h"

T_INPUT Input::now = { static_cast<int>(E_Button_State::Button_Off) };
T_INPUT Input::pre = { static_cast<int>(E_Button_State::Button_Off) };

static int GetInputInfo(int val, int judge_on);
static void EventCheck(int now, int pre, E_Button_Type button);
static void GetKeyboadInput();
static int InputConvert(int keyInfo);

int GetInputInfo(int val, int judge_on) {
	int ret;
	if (val == judge_on) {
		ret = static_cast<int>(E_Button_State::Button_On);
	}
	else {
		ret = static_cast<int>(E_Button_State::Button_Off);
	}
	return ret;
}

void EventCheck(int now, int pre, E_Button_Type button) {
	if (now != pre) {
		if (now == static_cast<int>(E_Button_State::Button_On)) {
			Input::Event_Push_Button(button);
		}
		else {
			Input::Event_Release_Button(button);
		}
	}
	else {
		Input::Event_Keep_Button(button, (E_Button_State)now);
	}
}

void Input::Input_Main() {

	// Pad入力取得
	Pad::GetPadInput();

	// イベント発行
	Input::EventLoop();
}

void Input::EventLoop() {
	// 現在の入力を保存
	Input::pre = Input::now;

	// Input情報を更新
	Input::GetInput();

	// 〇
	EventCheck(Input::now.Circle, Input::pre.Circle, E_Button_Type::Circle);

	// △押下
	EventCheck(Input::now.Triange, Input::pre.Triange, E_Button_Type::Triangle);

	// □押下
	EventCheck(Input::now.Square, Input::pre.Square, E_Button_Type::Square);

	// ×押下
	EventCheck(Input::now.Cross, Input::pre.Cross, E_Button_Type::Cross);

	// 上押下
	EventCheck(Input::now.Up, Input::pre.Up, E_Button_Type::Up);

	// 下押下
	EventCheck(Input::now.Down, Input::pre.Down, E_Button_Type::Down);

	// 左押下
	EventCheck(Input::now.Left, Input::pre.Left, E_Button_Type::Left);

	// 右押下
	EventCheck(Input::now.Right, Input::pre.Right, E_Button_Type::Right);
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

	
	if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::UP_LEFT)) {
		Input::now.Up = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::UP_LEFT));
		Input::now.Left = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::UP_LEFT));
	}

	if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::UP_RIGHT)) {
		Input::now.Up = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::UP_RIGHT));
		Input::now.Right = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::UP_RIGHT));
	}

	if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::DOWN_LEFT)) {
		Input::now.Down = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::DOWN_LEFT));
		Input::now.Left = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::DOWN_LEFT));
	}

	if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::DOWN_RIGHT)) {
		Input::now.Down = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::DOWN_RIGHT));
		Input::now.Right = GetInputInfo(Pad::D_Pad, static_cast<int>(D_Pad_Direction::DOWN_RIGHT));
	}	

	// キーボード入力取得
	GetKeyboadInput();
}

void Input::Event_Push_Button(E_Button_Type button) {
	DataManager::EventTable[static_cast<int>(SceneManager::NextScene)]->Event_Push_Button(button);
}

void Input::Event_Release_Button(E_Button_Type button) {
	DataManager::EventTable[static_cast<int>(SceneManager::NextScene)]->Event_Release_Button(button);
}

void Input::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {
	DataManager::EventTable[static_cast<int>(SceneManager::NextScene)]->Event_Keep_Button(button, onoff);
}

bool Input::CheckPush(E_Button_Type button) {

	bool ret = false;

	switch (button) {
	case E_Button_Type::Circle:
		if (Input::pre.Circle == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Circle == static_cast<int>(E_Button_State::Button_On)) {
			ret = true;
		}
		break;

	case E_Button_Type::Cross:
		if (Input::pre.Cross == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Cross == static_cast<int>(E_Button_State::Button_On)) {
			ret = true;
		}
		break;
	case E_Button_Type::Up:
		if (Input::pre.Up == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Up == static_cast<int>(E_Button_State::Button_On)) {
			ret = true;
		}
		break;
	case E_Button_Type::Down:
		if (Input::pre.Down == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Down == static_cast<int>(E_Button_State::Button_On)) {
			ret = true;
		}
		break;
	case E_Button_Type::Right:
		if (Input::pre.Right == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Right == static_cast<int>(E_Button_State::Button_On)) {
			ret = true;
		}
		break;
	case E_Button_Type::Left:
		if (Input::pre.Left == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Left == static_cast<int>(E_Button_State::Button_On)) {
			ret = true;
		}
		break;
	}
	return ret;
}

bool Input::CheckRelease(E_Button_Type button) {
	return false;
}

bool Input::CheckKeep(E_Button_Type button, E_Button_State state) {

	bool ret = false;

	switch (button) {
	case E_Button_Type::Circle:
		if (Input::pre.Circle == static_cast<int>(state) &&
			Input::now.Circle == static_cast<int>(state)) {
			ret = true;
		}
		break;
	case E_Button_Type::Up:
		if (Input::pre.Up == static_cast<int>(state) &&
			Input::now.Up == static_cast<int>(state)) {
			ret = true;
		}
		break;
	case E_Button_Type::Down:
		if (Input::pre.Down == static_cast<int>(state) &&
			Input::now.Down == static_cast<int>(state)) {
			ret = true;
		}
		break;
	case E_Button_Type::Left:
		if (Input::pre.Left == static_cast<int>(state) &&
			Input::now.Left == static_cast<int>(state)) {
			ret = true;
		}
		break;
	case E_Button_Type::Right:
		if (Input::pre.Right == static_cast<int>(state) &&
			Input::now.Right == static_cast<int>(state)) {
			ret = true;
		}
		break;
	}
	return ret;
}

void GetKeyboadInput() {
	char keybuf[256] = { 0 };

	// キーボード入力取得
	GetHitKeyStateAll(keybuf);

	Input::now.Circle |= InputConvert(keybuf[KEY_INPUT_RETURN]);
	Input::now.Cross |= InputConvert(keybuf[KEY_INPUT_ESCAPE]);
	Input::now.Up |= InputConvert(keybuf[KEY_INPUT_UP]);
	Input::now.Down |= InputConvert(keybuf[KEY_INPUT_DOWN]);
	Input::now.Left |= InputConvert(keybuf[KEY_INPUT_LEFT]);
	Input::now.Right |= InputConvert(keybuf[KEY_INPUT_RIGHT]);
}

int InputConvert(int keyInfo) {
	E_Button_State ret;

	if (keyInfo == 1) {
		ret = E_Button_State::Button_On;
	}
	else {
		ret = E_Button_State::Button_Off;
	}

	return static_cast<int>(ret);
}