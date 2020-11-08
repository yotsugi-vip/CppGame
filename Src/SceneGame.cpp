#include "SceneGame.h"
#include "SceneManager.h"
#include "DataManager.h"
#include <DxLib.h>

static void Draw_BackGround();
static void DrawPlayer();

static int GraphHandle_joji = 0;

static T_Player_Info NowInfo_P = { 50,15,0 };
static T_Player_Info PreInfo_P = NowInfo_P;

void SceneGame::Initialize() {
	
	GraphHandle_joji = LoadGraph("asset\\joji_shadow.png");

	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_DOWN_SCALE, 2);
	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_HSB, 0, 0, 0, 200);

	LoadDivGraph("asset\\p.png", static_cast<int>(Caractor::MAX), 4, 4, 64, 64, DataManager::CaractorImg);
}

void SceneGame::Draw() {
	int x, y, b;

	GetScreenState(&x, &y, &b);
	Draw_BackGround();
	DrawBox(10, 10, x * 2 / 3, y - 10, GetColor(0, 0, 0), true);

	DrawPlayer();
}


void SceneGame::End() {

}

void Draw_BackGround() {
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)], false);
	DrawGraph(370, 140, GraphHandle_joji, true);
}

void SceneGame::Event_Push_Button(E_Button_Type button) {}
void SceneGame::Event_Release_Button(E_Button_Type button) {}
void SceneGame::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {}

void DrawPlayer() {
	int drawHandle = 0;

	if (NowInfo_P.x == PreInfo_P.x && 
		NowInfo_P.y == PreInfo_P.y) {

		switch (NowInfo_P.Frame/10) {
		case 0:
			drawHandle = DataManager::CaractorImg[0];
			break;
		case 1:
			drawHandle = DataManager::CaractorImg[4];
			break;
		case 2:
			drawHandle = DataManager::CaractorImg[8];
			break;
		default:
			drawHandle = DataManager::CaractorImg[0];
			break;
		}
	}

	DrawGraph(NowInfo_P.x, NowInfo_P.y, drawHandle, true);

	if (NowInfo_P.Frame > 30) {
		NowInfo_P.Frame = 0;
	}
	else {
		NowInfo_P.Frame++;
	}
}