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

// ‚»‚Ì‚¤‚¿Input‚ÉˆÚ‚·
bool CheckPush(E_Button_Type button);
bool CheckKeep(E_Button_Type button, E_Button_State state);

static void ChangeDebugMode();
static void ChangeGameMode();
static void ExitGame();
static void dummy();

static unsigned int InputBuff[3] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };

typedef struct {
	int x;
	int y;
	const char* string;
	void (* function)();
}T_MENU_BUTTON_M;

T_MENU_BUTTON_M MenuButton[5] = {
	{980,	400,	Menu_1,	ChangeGameMode},
	{950,	500,	Menu_2,	dummy},
	{920,	600,	Menu_3,	dummy},
	{890,	700,	Menu_4,	ExitGame},
	{860,	800,	Menu_5,	dummy},
};

static int Font[2];
static int Id = -1;
static int FrameCnt = 0;
static int FrameWaitCnt = 0;

void SceneMenu::Initialize() {
	Font[0] = CreateFontToHandle("0", 64, 4);
	Font[1] = CreateFontToHandle("1", 72, 4, DX_FONTTYPE_EDGE, -1, 2);
}

void SceneMenu::Draw() {

	// ƒ{ƒ^ƒ“•`‰æ
	int i = 0;
	int x = 0;
	int y = 0;
	int f = Font[0];
	unsigned int C1 = GetColor(100, 100, 100);
	unsigned int C2 = GetColor(255, 255, 255);

	// ”wŒi•`‰æ
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	for (const auto& b : MenuButton) {
		y = b.y;
		x = b.x;
	
		if (Id == (4 - i)) {
			f = Font[1];
			x -= 15;
		}
		else {
			f = Font[0];
		}
	
		DrawStringToHandle(x, y, b.string, C1, f, C2);
		i++;
	}
}

void SceneMenu::Update() {

	if (CheckPush(E_Button_Type::Up)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id++;
		if (Id > 4) {
			Id = 0;
		}
	}

	if (CheckKeep(E_Button_Type::Up, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			Id++;
			FrameCnt = 0;
			if (Id > 4) {
				Id = 0;
			}
		}
	}

	if (CheckPush(E_Button_Type::Down)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id--;
		if (Id < 0) {
			Id = 4;
		}
	}

	if (CheckKeep(E_Button_Type::Down, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			Id--;
			FrameCnt = 0;
			if (Id < 0) {
				Id = 4;
			}
		}
	}

	if (CheckPush(E_Button_Type::Circle)) {
		if (Id >= 0 && Id < 5) {
			MenuButton[(4 - Id)].function();
		}
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

void ExitGame() {
	SceneManager::QuitGame = true;
}

void dummy() {}

void SceneMenu::Event_Push_Button(E_Button_Type buttonType) {}

void SceneMenu::Event_Release_Button(E_Button_Type button) {}

void SceneMenu::Event_Keep_Button(E_Button_Type buttonType, E_Button_State onoff) {}

bool CheckPush(E_Button_Type button) {

	bool ret = false;

	switch (button) {
	case E_Button_Type::Circle:
		if (Input::pre.Circle == static_cast<int>(E_Button_State::Button_Off) &&
			Input::now.Circle == static_cast<int>(E_Button_State::Button_On)) {
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
	}
	return ret;
}

void CheckRelease() {

}

bool CheckKeep(E_Button_Type button, E_Button_State state) {

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
	}
	return ret;
}