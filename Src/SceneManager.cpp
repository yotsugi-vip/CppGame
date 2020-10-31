#include "SceneManager.h"
#include "SceneDebug.h"
#include "SceneTitle.h"
#include "SceneBase.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "SceneSelectMode.h"
#include "SceneInit.h"
#include "Fps.h"
#include <DxLib.h>
#include <numeric>

static int MakePolkaDotsGraph(void);
static int MakeStripeGraph(void);

E_Scene SceneManager::PreScene = E_Scene::Scene_Initialize;
E_Scene SceneManager::NowScene = E_Scene::Scene_Title;
int SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_MAX)] = { 0 };
bool SceneManager::ShowDebugInfo = true;
bool SceneManager::QuitGame = false;

SceneInit sceneInit;
SceneTitle sceneTitle;
SceneMenu sceneMenu;
SceneDebugInfo sceneDebugInfo;
SceneGame sceneGame;
SceneSelectMode sceneSelectMode;

SceneBase* SceneTable[] = {
	&sceneInit,
	&sceneTitle,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo
};

void SceneManager::Initialize() {
	// 初期化処理を行う
	SceneTable[static_cast<int>(E_Scene::Scene_Initialize)]->Initialize();

	// 共通で使用するグラフィックデータの作成
	SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)] = MakeStripeGraph();
	SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Polka_Dots)] = MakePolkaDotsGraph();
}


void SceneManager::Draw() {

	// シーンの切り替え処理
	if (SceneManager::PreScene != SceneManager::NowScene) {

		SceneTable[static_cast<int>(SceneManager::PreScene)]->End();
		SceneTable[static_cast<int>(SceneManager::NowScene)]->Initialize();
		SceneManager::PreScene = SceneManager::NowScene;
	}

	SceneTable[static_cast<int>(SceneManager::NowScene)]->Input();
	SceneTable[static_cast<int>(SceneManager::NowScene)]->Draw();

	// デバッグ情報を画面に上書き
	if (SceneManager::ShowDebugInfo) {
		SceneManager::DebugInfoOverLay();
	}
}

void SceneManager::DebugInfoOverLay() {
	
	int Cr;
	int x, y, bit;
	int gcd;
	char String[64];
	char FpsStr[64];

	Cr = GetColor(0, 255, 0);

	wsprintf(String, "FPS:%d",Fps::fpsAve);
	DrawString(0, 0, String, Cr);

	wsprintf(FpsStr, "");
	for (auto f : Fps::fpsAveQueue) {
		wsprintf(FpsStr, "%s %d", FpsStr, f);
	}
	wsprintf(String, "10SEC FPS BUFF:%s", FpsStr);
	DrawString(0, 16, String, Cr);

	wsprintf(String, "FrameCount:%d", Fps::count);
	DrawString(0, 32, String, Cr);

	GetScreenState(&x, &y, &bit);
	gcd = std::gcd(x, y);
	wsprintf(String, "Window Size:%d x %d (%d:%d)", x, y, x / gcd, y / gcd);
	DrawString(0, 48, String, Cr);
}

static int MakeStripeGraph(void) {
	int gh;
	int x, y, bit;
	int cr_pink = GetColor(255, 200, 255);
	int cr_cream = GetColor(255, 255, 200);

	GetScreenState(&x, &y, &bit);
	
	gh = MakeScreen(x, y);

	// 描画先変更
	SetDrawScreen(gh);

	// ストライプ20本
	for (int i = 0; i <= 20; i++) {
		if (i % 2 == 0) {
			DrawBox(x / 20 * (i - 1), 0, x / 20 * i, y, cr_pink, true);
		}
		else {
			DrawBox(x / 20 * (i - 1), 0, x / 20 * i, y, cr_cream, true);
		}
	}

	// 描画先を裏画面に戻す
	SetDrawScreen(DX_SCREEN_BACK);

	return gh;
}

static int MakePolkaDotsGraph(void) {
	int gh;
	int x, y, bit;
	int cr_pink = GetColor(255, 200, 255);
	int cr_cream = GetColor(255, 255, 200);

	GetScreenState(&x, &y, &bit);

	gh = MakeScreen(x, y);

	// 描画先変更
	SetDrawScreen(gh);

	// 円模様
	for (int i = 0; i <= 20; i++) {

	}

	// 描画先を裏画面に戻す
	SetDrawScreen(DX_SCREEN_BACK);

	return gh;
}