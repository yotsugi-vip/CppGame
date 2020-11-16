#include "SceneMenu.h"
#include "SceneManager.h"
#include "Pad.h"
#include <DxLib.h>
#include "Input.h"
#include "Component.h"

static const char* Menu_1 = "Arcade";
static const char* Menu_2 = "Practice";
static const char* Menu_3 = "Config";
static const char* Menu_4 = "Exit";
static const char* Menu_5 = "Debug Mode";

static int SelectIndex = 0;
static int InputFrame = 0;

static int FrameCount = 0;

static void ChangeDebugMode();
static void ChangeGameMode();
static void ExitGame();
static void dummy();

static unsigned int InputBuff[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

static Button button[5] = {
	// Xs  Ys   Xe   Ye   String  Slected Action
	{  10, 10,  200, 30,  Menu_1, false,  ChangeGameMode	},
	{  10, 35,  200, 55,  Menu_2, false,  dummy				},
	{  10, 60,  200, 80,  Menu_3, false,  dummy				},
	{  10, 85,  200, 105, Menu_4, false,  ExitGame			},
	{  10, 110, 200, 130, Menu_5, false,  ChangeDebugMode	},
};

static int Font[2];
static int Id = 0;

void SceneMenu::Initialize() {
	Font[0] = CreateFontToHandle("0", 64, 4);
	Font[1] = CreateFontToHandle("1", 72, 4, DX_FONTTYPE_EDGE, -1, 2);
}

void SceneMenu::Draw() {

	// ”wŒi•`‰æ
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	if (Id == 4) {
		DrawStringToHandle(980, 400, "Arcade", GetColor(100, 100, 100), Font[1], GetColor(255, 255, 255));
	}
	else {
		DrawStringToHandle(1010, 400, "Arcade", GetColor(100, 100, 100), Font[0], GetColor(255, 255, 255));
	}
	if (Id == 3) {
		DrawStringToHandle(960, 500, "Practice", GetColor(100, 100, 100), Font[1], GetColor(255, 255, 255));
	}
	else {
		DrawStringToHandle(990, 500, "Practice", GetColor(100, 100, 100), Font[0], GetColor(255, 255, 255));
	}

	if (Id == 2) {
		DrawStringToHandle(940, 600, "Option", GetColor(100, 100, 100), Font[1], GetColor(255, 255, 255));
	}
	else {
		DrawStringToHandle(970, 600, "Option", GetColor(100, 100, 100), Font[0], GetColor(255, 255, 255));
	}

	if (Id == 1) {
		DrawStringToHandle(920, 700, "Credit", GetColor(100, 100, 100), Font[1], GetColor(255, 255, 255));
	}
	else {
		DrawStringToHandle(950, 700, "Credit", GetColor(100, 100, 100), Font[0], GetColor(255, 255, 255));
	}

	if(Id == 0){
		DrawStringToHandle(900, 800, "Exit", GetColor(100, 100, 100), Font[1], GetColor(255, 255, 255));
	}
	else {
		DrawStringToHandle(930, 800, "Exit", GetColor(100, 100, 100), Font[0], GetColor(255, 255, 255));
	}

	// ƒ{ƒ^ƒ“•`‰æ
	for (auto b : button) {
		b.Draw();
	}
}

void SceneMenu::Update() {
	if (Input::now.Up == static_cast<int>(E_Button_State::Button_On)) {
		if (Input::pre.Up == static_cast<int>(E_Button_State::Button_Off)) {
			Id++;
			if (Id > 4) {
				Id = 0;
			}
		}
	} else if (Input::now.Down == static_cast<int>(E_Button_State::Button_On)) {
		if (Input::pre.Down == static_cast<int>(E_Button_State::Button_Off)) {
			Id--;
			if (Id < 0) {
				Id = 4;
			}
		}
	}
}

void SceneMenu::End() {
}

void ChangeDebugMode() {
	SceneManager::NextScene = E_Scene::Scene_Debug;
}

void ChangeGameMode() {
	SceneManager::NextScene = E_Scene::Scene_Select_Mode;
}

void ExitGame() {
	SceneManager::QuitGame = true;
}

void dummy() {}

void SceneMenu::Event_Push_Button(E_Button_Type buttonType) {

	FrameCount = 0;

	switch (buttonType)
	{
	case E_Button_Type::Circle:
		button[SelectIndex].func();
		break;
	case E_Button_Type::Cross:
		SceneManager::NextScene = E_Scene(static_cast<int>(SceneManager::NowScene) - 1);
		break;
	case E_Button_Type::Up:
		SelectIndex--;
		if (SelectIndex < 0) {
			SelectIndex = 4;
		}
		break;
	case E_Button_Type::Down:
		SelectIndex++;
		if (SelectIndex > 4) {
			SelectIndex = 0;
		}
		break;
	default:
		break;
	}

	for (int i = 0; i < 5; i++) {
		if (i == SelectIndex) {
			button[i].isSelected = true;
		}
		else {
			button[i].isSelected = false;
		}
	}
}

void SceneMenu::Event_Release_Button(E_Button_Type button) {}

void SceneMenu::Event_Keep_Button(E_Button_Type buttonType, E_Button_State onoff) {
	if (onoff == E_Button_State::Button_On) {
		switch (buttonType)
		{
		case E_Button_Type::Up:
			if (FrameCount < 6) {
				FrameCount++;
			}
			else {
				FrameCount = 0;
				SelectIndex--;
				if (SelectIndex < 0) {
					SelectIndex = 4;
				}
			}
			break;
		case E_Button_Type::Down:
			if (FrameCount < 6) {
				FrameCount++;
			}
			else {
				FrameCount = 0;
				SelectIndex++;
				if (SelectIndex > 4) {
					SelectIndex = 0;
				}
			}
			break;
		default:
			break;
		}

		for (int i = 0; i < 5; i++) {
			if (i == SelectIndex) {
				button[i].isSelected = true;
			}
			else {
				button[i].isSelected = false;
			}
		}
	}
}