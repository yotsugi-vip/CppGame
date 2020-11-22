#include "SceneMenu.h"
#include "SceneManager.h"
#include "Pad.h"
#include "Sound.h"
#include "Input.h"
#include "Component.h"
#include "DataManager.h"
#include <DxLib.h>


static void ChangeDebugMode();
static void ChangeGameMode();
static void ChangeConfig();
static void ExitGame();
static void dummy();

T_MENU_BUTTON MenuButton[5] = {
	{BUTTON_X_0,	BUTTON_Y_0,	Menu_1,	ChangeGameMode	},
	{BUTTON_X_1,	BUTTON_Y_1,	Menu_2,	dummy			},
	{BUTTON_X_2,	BUTTON_Y_2,	Menu_3,	ChangeConfig	},
	{BUTTON_X_3,	BUTTON_Y_3,	Menu_4,	ExitGame		},
	{BUTTON_X_4,	BUTTON_Y_4,	Menu_5,	ChangeDebugMode	},
};

static int Id = -1;
static int FrameCnt = 0;
static int FrameWaitCnt = 0;

void SceneMenu::Initialize() { }

void SceneMenu::Draw() {

	// ƒ{ƒ^ƒ“•`‰æ
	int i = 0;
	int x = 0;
	int y = 0;
	int f = DataManager::FontTable[static_cast<int>(Fonts::Menu)];
	unsigned int C1 = GetColor(100, 100, 100);
	unsigned int C2 = GetColor(255, 255, 255);

	// ”wŒi•`‰æ
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	// ƒ^ƒCƒgƒ‹•`‰æ
	DrawGraph(TITLE_MENU_X, TITLE_MENU_Y, DataManager::GraphTable[static_cast<int>(Graph::Title)], true);


	for (const auto& b : MenuButton) {
		y = b.y;
		x = b.x;
	
		if (Id == (4 - i)) {
			f = DataManager::FontTable[static_cast<int>(Fonts::Menu_Selected)];
			x -= 15;
		}
		else {
			f = DataManager::FontTable[static_cast<int>(Fonts::Menu)];
		}
	
		DrawStringToHandle(x, y, b.string, C1, f, C2);
		i++;
	}
}

void SceneMenu::Update() {

	if (Input::CheckPush(E_Button_Type::Up)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id++;
		Sound::SE_SelectMenu();
		if (Id > 4) {
			Id = 0;
		}
	}

	if (Input::CheckKeep(E_Button_Type::Up, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			Id++;
			FrameCnt = 0;
			Sound::SE_SelectMenu();
			if (Id > 4) {
				Id = 0;
			}
		}
	}

	if (Input::CheckPush(E_Button_Type::Down)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id--;
		Sound::SE_SelectMenu();
		if (Id < 0) {
			Id = 4;
		}
	}

	if (Input::CheckKeep(E_Button_Type::Down, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			Id--;
			FrameCnt = 0;
			Sound::SE_SelectMenu();
			if (Id < 0) {
				Id = 4;
			}
		}
	}

	if (Input::CheckPush(E_Button_Type::Circle)) {
		if (Id >= 0 && Id < 5) {
			Sound::SE_ConfirmMenu();
			MenuButton[(4 - Id)].function();
		}
	}

	if (Input::CheckPush(E_Button_Type::Cross)) {
		Sound::SE_Cancel();
		SceneManager::NextScene = E_Scene::Title;
	}

}

void SceneMenu::End() {
}

void ChangeDebugMode() {
	SceneManager::NextScene = E_Scene::Debug;
}

void ChangeGameMode() {
	SceneManager::NextScene = E_Scene::Select_Mode;
}

void ChangeConfig() {
	SceneManager::NextScene = E_Scene::Config;
}

void ExitGame() {
	SceneManager::QuitGame = true;
}

void dummy() { }

void SceneMenu::Event_Push_Button(E_Button_Type buttonType) {}

void SceneMenu::Event_Release_Button(E_Button_Type button) {}

void SceneMenu::Event_Keep_Button(E_Button_Type buttonType, E_Button_State onoff) {}