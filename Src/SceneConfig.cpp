#include "SceneConfig.h"
#include "DataManager.h"
#include "Input.h"
#include "Sound.h"

#include <DxLib.h>

static void drawNum(int num, int x, int y);
static void drawNums(int num, int x, int y);
static int convert(int num);

static int FrameCnt = 0;
static int FrameWaitCnt = 0;
static int Id = -1;

static void dummy();
static void ButtonExit();
static void ButtonDefault();

constexpr int ID_EXIT = 0;
constexpr int ID_DEFAULT = 1;
constexpr int ID_BGM = 2;
constexpr int ID_SE = 3;
constexpr int ID_MAX = ID_SE;
constexpr int ID_MIN = ID_EXIT;

typedef void (*pFunc)();

static pFunc ConfigFunc[4] = {
	ButtonExit,
	ButtonDefault,
	dummy,
	dummy,
};

void SceneConfig::Draw(){
	int x, y;

	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

	if (Id == 3) {
		DrawGraph(80, 100, DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)], true);
		GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)], &x, &y);
		drawNums(Sound::SE_Ratio, x + 100, 100);
	}
	else {
		DrawGraph(100, 100, DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)], true);
		GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)], &x, &y);
		drawNums(Sound::SE_Ratio, x + 120, 100);
	}

	if (Id == 2) {
		DrawGraph(80, 174, DataManager::GraphTable[static_cast<int>(Graph::Config_BGM)], true);
		GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Config_BGM)], &x, &y);
		drawNums(Sound::BGM_Ratio, x + 100, 174);
	}
	else {
		DrawGraph(100, 174, DataManager::GraphTable[static_cast<int>(Graph::Config_BGM)], true);
		GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Config_BGM)], &x, &y);
		drawNums(Sound::BGM_Ratio, x + 120, 174);
	}

	if (Id == 1) {
		DrawGraph(80, 248, DataManager::GraphTable[static_cast<int>(Graph::Config_Default)], true);
	}
	else {
		DrawGraph(100, 248, DataManager::GraphTable[static_cast<int>(Graph::Config_Default)], true);
	}

	if (Id == 0) {
		DrawGraph(80, 322, DataManager::GraphTable[static_cast<int>(Graph::Config_Exit)], true);
	}
	else {
		DrawGraph(100, 322, DataManager::GraphTable[static_cast<int>(Graph::Config_Exit)], true);
	}
	

}

void SceneConfig::Initialize(){

}

void SceneConfig::Update() {
	int val = 0;

#pragma region PUSH
	if (Input::CheckPush(E_Button_Type::Up)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id++;
		Sound::SE_SelectMenu();
		if (Id > ID_MAX) {
			Id = 0;
		}
	}

	if (Input::CheckPush(E_Button_Type::Down)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Id--;
		Sound::SE_SelectMenu();
		if (Id < ID_MIN) {
			Id = ID_MAX;
		}
	}

	if (Input::CheckPush(E_Button_Type::Left)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Sound::SE_SelectMenu();
		if (Id == ID_BGM) {
			val = Sound::BGM_Ratio - 5;
			Sound::SetBgmRatio(val);
		}
		else if (Id == ID_SE) {
			val = Sound::SE_Ratio - 5;
			Sound::SetSeRatio(val);
		}
		
	}

	if (Input::CheckPush(E_Button_Type::Right)) {
		FrameCnt = 0;
		FrameWaitCnt = 0;
		Sound::SE_SelectMenu();

		if (Id == ID_BGM) {
			val = Sound::BGM_Ratio + 5;
			Sound::SetBgmRatio(val);
		}
		else if (Id == ID_SE) {
			val = Sound::SE_Ratio + 5;
			Sound::SetSeRatio(val);
		}

	}

	if (Input::CheckPush(E_Button_Type::Circle)) {
		if (Id >= 0 && Id < 4) {
			Sound::SE_ConfirmMenu();
			ConfigFunc[Id]();
		}
	}

	if (Input::CheckPush(E_Button_Type::Cross)) {
		Sound::SE_Cancel();
		SceneManager::NextScene = E_Scene::Menu;
	}
#pragma endregion

#pragma region KEEP
	if (Input::CheckKeep(E_Button_Type::Up, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			Id++;
			FrameCnt = 0;
			Sound::SE_SelectMenu();
			if (Id > 3) {
				Id = 0;
			}
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
				Id = 3;
			}
		}
	}

	if (Input::CheckKeep(E_Button_Type::Right, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			FrameCnt = 0;
			Sound::SE_SelectMenu();
			if (Id == ID_BGM) {
				val = Sound::BGM_Ratio + 5;
				Sound::SetBgmRatio(val);
			}
			else if (Id == ID_SE) {
				val = Sound::SE_Ratio + 5;
				Sound::SetSeRatio(val);
			}
		}
	}

	if (Input::CheckKeep(E_Button_Type::Left, E_Button_State::Button_On)) {
		FrameWaitCnt++;
		FrameCnt++;
		if (FrameWaitCnt > 20 && FrameCnt > 5) {
			FrameCnt = 0;
			Sound::SE_SelectMenu();
			if (Id == ID_BGM) {
				val = Sound::BGM_Ratio - 5;
				Sound::SetBgmRatio(val);
			}
			else if (Id == ID_SE) {
				val = Sound::SE_Ratio - 5;
				Sound::SetSeRatio(val);
			}
		}
	}
#pragma endregion

}

void SceneConfig::End(){}

void SceneConfig::Event_Push_Button(E_Button_Type button){}
void SceneConfig::Event_Release_Button(E_Button_Type button){}
void SceneConfig::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}


void drawNums(int num, int x, int y) {

	int hundredsPlace = num / 100;
	int tensPlace = (num - hundredsPlace * 100) / 10;
	int oncesPlace = num - hundredsPlace * 100 - tensPlace * 10;

	if (num >= 100) {
		drawNum(hundredsPlace, x, y);
	}

	drawNum(tensPlace, x + 60, y);
	drawNum(oncesPlace, x + 120, y);
	DrawGraph(x + 184, y, DataManager::GraphTable[static_cast<int>(Graph::Num_per)], true);
}

void drawNum(int num, int x, int y) {
	DrawGraph(x, y, DataManager::GraphTable[convert(num)], true);
}

int convert(int num) {

	Graph ret = Graph::Num_1;
	switch (num) {
	case 0:
		ret = Graph::Num_0;
		break;
	case 1:
		ret = Graph::Num_1;
		break;
	case 2:
		ret = Graph::Num_2;
		break;
	case 3:
		ret = Graph::Num_3;
		break;
	case 4:
		ret = Graph::Num_4;
		break;
	case 5:
		ret = Graph::Num_5;
		break;
	case 6:
		ret = Graph::Num_6;
		break;
	case 7:
		ret = Graph::Num_7;
		break;
	case 8:
		ret = Graph::Num_8;
		break;
	case 9:
		ret = Graph::Num_9;
		break;
	default:
		ret = Graph::Num_0;
		break;
	}
	return static_cast<int>(ret);
}

void dummy(){}

void ButtonExit() {
	SceneManager::NextScene = E_Scene::Menu;
}

void ButtonDefault() {
	Sound::SetBgmRatio(50);
	Sound::SetSeRatio(50);
}