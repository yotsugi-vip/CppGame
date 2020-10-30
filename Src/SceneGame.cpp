#include "SceneGame.h"
#include "SceneManager.h"
#include <DxLib.h>

static void Draw_BackGround();
static int GraphHandle_joji = 0;

void SceneGame::Initialize() {
	
	GraphHandle_joji = LoadGraph("asset\\joji_shadow.png");

	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_DOWN_SCALE, 2);
	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_HSB, 0, 0, 0, 200);
}

void SceneGame::Draw() {
	Draw_BackGround();
}

void SceneGame::Input() {

}

void SceneGame::End() {

}

void Draw_BackGround() {
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)], false);
	DrawGraph(370, 140, GraphHandle_joji, true);
}