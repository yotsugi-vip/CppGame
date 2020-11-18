#include "TransTitleToMenu.h"
#include "SceneMenu.h"
#include "SceneTitle.h"
#include "SceneManager.h"
#include "DataManager.h"
#include <DxLib.h>


static void dummy();
static void calc(int* x, int* y);

static T_MENU_BUTTON MenuButtonTrans[5] = {
	{BUTTON_X_0,	BUTTON_Y_0,	Menu_1, dummy},
	{BUTTON_X_1,	BUTTON_Y_1,	Menu_2, dummy},
	{BUTTON_X_2,	BUTTON_Y_2,	Menu_3, dummy},
	{BUTTON_X_3,	BUTTON_Y_3,	Menu_4, dummy},
	{BUTTON_X_4,	BUTTON_Y_4,	Menu_5, dummy},
};

static int FrameCnt = 0;
static int f = 0;

void TransTitleToMenu::Update() {

	FrameCnt++;
	if (FrameCnt > 34) {
		SceneManager::NextScene = E_Scene::Menu;
	}
}

void TransTitleToMenu::Draw() {

	int C1 = GetColor(100, 100, 100);
	int C2 = GetColor(255, 255, 255);
	int f = DataManager::FontTable[static_cast<int>(Fonts::Menu)];
	int cr_cream = GetColor(255, 255, 200);
	int x, y;

	calc(&x, &y);
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);
	DrawGraph(x, y, DataManager::GraphTable[static_cast<int>(Graph::Title)], true);

	if (FrameCnt < 12) { 
		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 50); 
	}
	else if (FrameCnt < 24) { 
		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 100); 
	}
	else if (FrameCnt < 30) {
		SetDrawBlendMode(DX_BLENDMODE_PMA_ALPHA, 200);
	}
	else if (FrameCnt < 36) {
		SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	}

	for (const auto &b : MenuButtonTrans) {
		DrawStringToHandle(b.x - ((35 - FrameCnt) * 3), b.y, b.string, C1, f, C2);
	}
}

void TransTitleToMenu::Initialize() {
	FrameCnt = 0;
	
}

void TransTitleToMenu::End() {
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
}

void TransTitleToMenu::Event_Push_Button(E_Button_Type button) {	
	SceneManager::NextScene = E_Scene::Menu;
}

void TransTitleToMenu::Event_Release_Button(E_Button_Type button) {}
void TransTitleToMenu::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {}

void dummy() {}

void calc(int *x, int *y) {
	float Xe = (float)TITLE_MENU_X;
	float Ye = (float)TITLE_MENU_Y;
	float Xs = 0;
	float Ys = 0;
	float gx, gy;
	int wx, wy, dummy;
	float xd, yd;

	GetScreenState(&wx, &wy, &dummy);
	GetGraphSizeF(DataManager::GraphTable[static_cast<int>(Graph::Title)], &gx, &gy);

	Xs = (float)wx / 2 - gx / 2;
	Ys = (float)wy / 3 - gy / 2;

	xd = (FrameCnt / static_cast<float>(35)) * (Xe - Xs);
	yd = (FrameCnt / static_cast<float>(35)) * (Ye - Ys);

	*x = (int)(Xs + xd);
	*y = (int)(Ys + yd);
}