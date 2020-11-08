#include "SceneSelectMode.h"
#include "SceneManager.h"
#include "Component.h"
#include <DxLib.h>


const char* BUTTON_LABEL_EASY = "easy";
const char* BUTTON_LABEL_NORMAL = "normal";
const char* BUTTON_LABEL_HARD = "hard";

const char* BUTTON_TEXT_EASY[] = { "","" };
const char* BUTTON_TEXT_NORMAL[] = { "","" };
const char* BUTTON_TEXT_HARD[] = { "","" };

static void dummy();
static void ChangeGameMode();

Button button[] = {
	{  10, 10,  200,  30,  BUTTON_LABEL_EASY,	false,  ChangeGameMode	},
	{  10, 45,  200,  65,  BUTTON_LABEL_NORMAL,	false,  ChangeGameMode	},
	{  10, 80,  200, 100,  BUTTON_LABEL_HARD,	false,  ChangeGameMode	},
};

static int SelectIndex = 0;
static int FrameCount = 0;

void SceneSelectMode::Initialize() {

}

void SceneSelectMode::Draw() {
	// ”wŒi•`‰æ
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	for (auto b : button) {
		b.Draw();
	}
}

void SceneSelectMode::End() {

}

void SceneSelectMode::Event_Push_Button(E_Button_Type buttonType) {

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

void SceneSelectMode::Event_Release_Button(E_Button_Type button) {}

void SceneSelectMode::Event_Keep_Button(E_Button_Type buttonType, E_Button_State onoff) {
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

void dummy(){}

void ChangeGameMode() {
	SceneManager::NextScene = E_Scene::Scene_Game;
}