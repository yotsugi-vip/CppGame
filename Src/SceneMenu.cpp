#include "SceneMenu.h"
#include "SceneManager.h"
#include "Pad.h"
#include <DxLib.h>

static const char* Menu_1 = "Menu 1";
static const char* Menu_2 = "Menu 2";
static const char* Menu_3 = "Menu 3";
static const char* Menu_4 = "Game Mode";
static const char* Menu_5 = "Debug Mode";

static int FontHandle_Menu = -1;

static int SelectIndex = 0;
static int InputFrame = 0;

static void ChangeDebugMode();
static void ChangeGameMode();
static void dummy();

static unsigned int InputBuff[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

static Button button[5] = {
	{10, 200, 10, 30, Menu_1, false, dummy },
	{10, 200, 35, 55, Menu_2, false, dummy},
	{10, 200, 60, 80, Menu_3, false, dummy},
	{10, 200, 85, 105, Menu_4, false, ChangeGameMode},
	{10, 200, 110, 130, Menu_5, false, ChangeDebugMode},
};

void SceneMenu::Initialize() {
	FontHandle_Menu = CreateFontToHandle("Menu", 15, 4);
}

void SceneMenu::Draw() {
	char String[64];

	for (auto b : button) {
		b.Draw();
	}
}

void SceneMenu::Input() {

	// 前フレームと入力値が異なったら直ちにカーソル移動
	if (InputBuff[0] == InputBuff[1] &&
		InputBuff[1] == InputBuff[2] &&
		InputBuff[2] == Pad::D_Pad.Up) {
		if (Pad::D_Pad.Up == 0)
			SelectIndex--;
		if (Pad::D_Pad.Up == 18000)
			SelectIndex++;
	}
	else {
		if (Pad::D_Pad.Up == 0)
			InputFrame++;
		if (Pad::D_Pad.Up == 18000)
			InputFrame--;
	}

	// バッファ更新
	InputBuff[2] = InputBuff[1];
	InputBuff[1] = InputBuff[2];
	InputBuff[0] = Pad::D_Pad.Up;

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
	unsigned int Cr = Button::isSelected ? GetColor(0, 0, 0) : GetColor(255, 255, 255);

	DrawBox(Button::X_start, Button::Y_start, Button::X_end, Button::Y_end, GetColor(255, 255, 255), Button::isSelected);
	DrawStringToHandle(Button::X_start + 3, Button::Y_start + 1, Button::String, Cr, FontHandle_Menu);
}

void ChangeDebugMode() {
	SceneManager::NowScene = E_Scene::Scene_Debug;
}

void ChangeGameMode() {
	SceneManager::NowScene = E_Scene::Scene_Game;
}

void dummy() {}