#include "SceneMenu.h"
#include "SceneManager.h"
#include "Pad.h"
#include <DxLib.h>

static const char* Menu_1 = "Arcade";
static const char* Menu_2 = "Practice";
static const char* Menu_3 = "Config";
static const char* Menu_4 = "Exit";
static const char* Menu_5 = "Debug Mode";

static int FontHandle_Menu = -1;

static int SelectIndex = 0;
static int InputFrame = 0;

static void ChangeDebugMode();
static void ChangeGameMode();
static void ExitGame();
static void dummy();

static unsigned int InputBuff[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

static Button button[5] = {
	// Xs  Xe   Ys   Ye   String  Slected Action
	{  10, 200, 10,  30,  Menu_1, false,  ChangeGameMode	},
	{  10, 200, 35,  55,  Menu_2, false,  dummy				},
	{  10, 200, 60,  80,  Menu_3, false,  dummy				},
	{  10, 200, 85,  105, Menu_4, false,  ExitGame			},
	{  10, 200, 110, 130, Menu_5, false,  ChangeDebugMode	},
};

void SceneMenu::Initialize() {
	FontHandle_Menu = CreateFontToHandle("Menu", 15, 4);
}

void SceneMenu::Draw() {

	// 背景描画
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	
	// ボタン描画
	for (auto b : button) {
		b.Draw();
	}
}

void SceneMenu::Input() {

	// 前フレームと入力値が異なったら直ちにカーソル移動
	if (InputBuff[0] == InputBuff[1] &&
		InputBuff[1] == InputBuff[2] &&
		InputBuff[2] == Pad::D_Pad) {
		if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::UP))
			SelectIndex--;
		if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::DOWN))
			SelectIndex++;
	}
	else {
		if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::UP))
			InputFrame++;
		if (Pad::D_Pad == static_cast<int>(D_Pad_Direction::DOWN))
			InputFrame--;
	}

	// バッファ更新
	InputBuff[2] = InputBuff[1];
	InputBuff[1] = InputBuff[2];
	InputBuff[0] = Pad::D_Pad;

	if (InputFrame > 5) {
		InputFrame = 0;
		SelectIndex--;
	}

	if (InputFrame < -5) {
		InputFrame = 0;
		SelectIndex++;
	}


	if (SelectIndex > 4) {
		SelectIndex = 0;
	}

	if (SelectIndex < 0) {
		SelectIndex = 4;
	}

	for (int i = 0; i < 5; i++) {
		if (i == SelectIndex) {
			button[i].isSelected = true;
		}
		else {
			button[i].isSelected = false;
		}
	}

	if (Pad::R_Buttons.Cross == 128) {
		button[SelectIndex].func();
	}
}

void SceneMenu::End() {
	DeleteFontToHandle(FontHandle_Menu);
}

void Button::Draw() {
	unsigned int Cr = GetColor(0, 0, 0);

	// メニュー描画
	DrawBox(Button::X_start, Button::Y_start, Button::X_end, Button::Y_end, GetColor(0, 0, 0), Button::isSelected);
	DrawStringToHandle(Button::X_start + 3, Button::Y_start + 1, Button::String, Cr, FontHandle_Menu);
}

void ChangeDebugMode() {
	SceneManager::NowScene = E_Scene::Scene_Debug;
}

void ChangeGameMode() {
	SceneManager::NowScene = E_Scene::Scene_Game;
}

void ExitGame() {
	SceneManager::QuitGame = true;
}

void dummy() {}