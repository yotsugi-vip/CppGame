#include "SceneConfig.h"
#include "DataManager.h"

#include <DxLib.h>

static void drawNum(int num, int x, int y);
static void drawNums(int num, int x, int y);
static int convert(int num);

void SceneConfig::Draw(){
	int x, y;

	DrawGraph(100, 100, DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)], true);
	DrawGraph(100, 174, DataManager::GraphTable[static_cast<int>(Graph::Config_BGM)], true);
	DrawGraph(100, 248, DataManager::GraphTable[static_cast<int>(Graph::Config_Default)], true);
	DrawGraph(100, 322, DataManager::GraphTable[static_cast<int>(Graph::Config_Exit)], true);
	
	GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)], &x, &y);
	drawNums(100, x + 120, 100);

	GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Config_BGM)], &x, &y);
	drawNums(85, x + 120, 174);
}

void SceneConfig::Update(){}

void SceneConfig::Initialize(){}
void SceneConfig::End(){}

void SceneConfig::Event_Push_Button(E_Button_Type button){}
void SceneConfig::Event_Release_Button(E_Button_Type button){}
void SceneConfig::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}


void drawNums(int num, int x, int y) {

	int hundredsPlace = num / 100;
	int tensPlace = (num - hundredsPlace * 100) / 10;
	int oncesPlace = num - hundredsPlace * 100 - tensPlace / 10;

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