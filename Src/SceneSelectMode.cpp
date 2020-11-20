#include "SceneSelectMode.h"
#include "SceneManager.h"
#include "Component.h"
#include "DataManager.h"
#include "Input.h"
#include "Sound.h"
#include <DxLib.h>


const char* BUTTON_LABEL_EASY = "EASY";
const char* BUTTON_LABEL_NORMAL = "NORMAL";
const char* BUTTON_LABEL_HARD = "HARD";

static void dummy();
static void ChangeGameMode();

typedef struct {
	int x;
	int y;
	void (* function)();
}T;

static int Id = 0;
static int FrameCnt = 0;
static int FrameWaitCnt = 0;

void SceneSelectMode::Initialize() {
	Id = -1;
	
}


void SceneSelectMode::Draw() {
	
	TextBox_Color color;

	// 背景描画
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);
	
	
	color = (Id == 2) ? TextBox_Color::PINK : TextBox_Color::GRAY;

	Component::DrawTextBox(320, 170, 960, 300, color);
	DrawGraph(550, 200, DataManager::GraphTable[static_cast<int>(Graph::Mode_Hard)], true);
	DrawString(560, 260, "まずはここから", GetColor(0, 0, 0));

	color = (Id == 1) ? TextBox_Color::PINK : TextBox_Color::GRAY;

	Component::DrawTextBox(320, 320, 960, 450, color);
	DrawGraph(510, 350, DataManager::GraphTable[static_cast<int>(Graph::Mode_Normal)], true);
	DrawString(480, 410, "だいたいの人がクリアできると思います", GetColor(0,0,0));

	color = (Id == 0) ? TextBox_Color::PINK : TextBox_Color::GRAY;

	Component::DrawTextBox(320, 470, 960, 600, color);
	DrawGraph(540, 500, DataManager::GraphTable[static_cast<int>(Graph::Mode_Easy)], true);
	DrawString(500, 560, "シューティング チョットデキル", GetColor(0, 0, 0));
}

void SceneSelectMode::Update() {
	if (Input::CheckPush(E_Button_Type::Up)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id++;
		Sound::SE_SelectMenu();
		if (Id > 2) {
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
			if (Id > 2) {
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
			Id = 2;
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
				Id = 2;
			}
		}
	}

	if (Input::CheckPush(E_Button_Type::Circle)) {
		if (Id >= 0 && Id < 3) {
			Sound::SE_ConfirmMenu();
			ChangeGameMode();
		}
	}

	if (Input::CheckPush(E_Button_Type::Cross)) {
		Sound::SE_Cancel();
		SceneManager::NextScene = E_Scene::Menu;
	}
}

void SceneSelectMode::End() {

}

void SceneSelectMode::Event_Push_Button(E_Button_Type buttonType) { }

void SceneSelectMode::Event_Release_Button(E_Button_Type button) { }

void SceneSelectMode::Event_Keep_Button(E_Button_Type buttonType, E_Button_State onoff) { }

void dummy(){}

void ChangeGameMode() {
	SceneManager::NextScene = E_Scene::Game;
}