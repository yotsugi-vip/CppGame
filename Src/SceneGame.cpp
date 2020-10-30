#include "SceneGame.h"
#include <DxLib.h>

static void Draw_BackGround();
static int GraphHandle_joji = 0;
static int GraphHandle_back = 0;
static int GraphHandle_back_test = 0;

void SceneGame::Initialize() {
	
	int x, y, bit;
	int cr_pink = GetColor(255, 200, 255);
	int cr_cream = GetColor(255, 255, 200);

	GraphHandle_joji = LoadGraph("asset\\joji_shadow.png");
	GraphHandle_back = LoadGraph("asset\\back_pink.png");

	GetScreenState(&x, &y, &bit);
	DrawExtendGraph(0, 0, x, y, GraphHandle_back, false);

	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_DOWN_SCALE, 2);
	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_HSB, 0, 0, 0, 200);

	GraphHandle_back_test = MakeScreen(x, y);
	SetDrawScreen(GraphHandle_back_test);

	// ストライプ20本
	for (int i = 0; i <= 20; i++) {
		if (i % 2 == 0) {
			DrawBox(x / 20 * (i - 1), 0, x / 20 * i, y, cr_pink, true);
		}
		else {
			DrawBox(x / 20 * (i - 1), 0, x / 20 * i, y, cr_cream, true);
		}
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void SceneGame::Draw() {
	Draw_BackGround();
}

void SceneGame::Input() {

}

void SceneGame::End() {

}

void Draw_BackGround() {
	DrawGraph(0, 0, GraphHandle_back_test, false);
	DrawGraph(370, 140, GraphHandle_joji, true);
}