#include "SceneGame.h"
#include "SceneManager.h"
#include "DataManager.h"
#include "Player.h"

#include <DxLib.h>

static void Draw_BackGround();
static int GraphHandle_joji = 0;
static Player player;

void SceneGame::Initialize() {
	
	GraphHandle_joji = LoadGraph("asset\\joji_shadow.png");

	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_DOWN_SCALE, 2);
	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_HSB, 0, 0, 0, 200);

	player = Player();
}

void SceneGame::Draw() {
	
	Draw_BackGround();

	DrawBox(GAME_RANGE_START_X, GAME_RANGE_START_Y, GAME_RANGE_WIDTH, GAME_RANGE_HEIGHT, GetColor(0, 0, 0), true);

	player.Draw();
}

void SceneGame::Update() {
	player.Update();
}


void SceneGame::End() {

}

void Draw_BackGround() {
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)], false);
	DrawGraph(935, 580, GraphHandle_joji, true);
}

void SceneGame::Event_Push_Button(E_Button_Type button) {}
void SceneGame::Event_Release_Button(E_Button_Type button) {}
void SceneGame::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {}
