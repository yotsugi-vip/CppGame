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

static int FontHandle_Menu = -1;

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

void SceneMenu::Initialize() {
	FontHandle_Menu = CreateFontToHandle("Menu", 15, 4);
}

void SceneMenu::Draw() {

	// îwåiï`âÊ
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	
	// É{É^Éìï`âÊ
	for (auto b : button) {
		b.Draw();
	}
}

void SceneMenu::End() {
	DeleteFontToHandle(FontHandle_Menu);
}

void Button::Draw() {
	unsigned int Cr = GetColor(0, 0, 0);

	// ÉÅÉjÉÖÅ[ï`âÊ
	DrawBox(Button::X_start, Button::Y_start, Button::X_end, Button::Y_end, GetColor(0, 0, 0), Button::isSelected);
	DrawStringToHandle(Button::X_start + 3, Button::Y_start + 1, Button::String, Cr, FontHandle_Menu);
}

void ChangeDebugMode() {
	SceneManager::NowScene = E_Scene::Scene_Debug;
}

void ChangeGameMode() {
	SceneManager::NowScene = E_Scene::Scene_Select_Mode;
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