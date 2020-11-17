#include "TransTitleToMenu.h"
#include <DxLib.h>
#include "SceneManager.h"

static const char* Menu_1 = "Arcade";
static const char* Menu_2 = "Practice";
static const char* Menu_3 = "Config";
static const char* Menu_4 = "Exit";
static const char* Menu_5 = "Debug Mode";

typedef struct {
	int x;
	int y;
	const char* string;
}T_MENU_BUTTON;

T_MENU_BUTTON MenuButton[5] = {
	{980,	400,	Menu_1},
	{950,	500,	Menu_2},
	{920,	600,	Menu_3},
	{890,	700,	Menu_4},
	{860,	800,	Menu_5},
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
	int f = CreateFontToHandle("00", 64, 4);
	int cr_cream = GetColor(255, 255, 200);

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

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

	for (const auto &b : MenuButton) {
		DrawStringToHandle(b.x - ((35 - FrameCnt) * 3), b.y, b.string, C1, f, C2);
	}
}

void TransTitleToMenu::Initialize() {}

void TransTitleToMenu::End() {
	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 0);
	DeleteFontToHandle(f);
}

void TransTitleToMenu::Event_Push_Button(E_Button_Type button) {	
	SceneManager::NextScene = E_Scene::Menu;
}

void TransTitleToMenu::Event_Release_Button(E_Button_Type button) {}
void TransTitleToMenu::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {}
