#include "SceneManager.h"
#include "DataManager.h"
#include "Fps.h"
#include <DxLib.h>
#include <numeric>

static int MakeBackScreenCream(void);
static int MakeStripeGraph(void);

E_Scene SceneManager::NowScene = E_Scene::Scene_Initialize;
E_Scene SceneManager::NextScene = E_Scene::Scene_Title;
E_Scene SceneManager::PreScene = E_Scene::Scene_Initialize;

int SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_MAX)] = { 0 };
char SceneManager::DebugLog[][64] = { 0 };
bool SceneManager::ShowDebugInfo = true;
bool SceneManager::QuitGame = false;


void SceneManager::Initialize() {
	// 初期化処理を行う
	DataManager::SceneTable[static_cast<int>(E_Scene::Scene_Initialize)]->Initialize();
	
	// 共通で使用するグラフィックデータの作成
	SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)] = MakeStripeGraph();
	SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)] = MakeBackScreenCream();
}


void SceneManager::Draw() {

	// シーンの切り替え処理
	if (SceneManager::NowScene != SceneManager::NextScene) {

		DataManager::SceneTable[static_cast<int>(SceneManager::NowScene)]->End();
		DataManager::SceneTable[static_cast<int>(SceneManager::NextScene)]->Initialize();

		SceneManager::PreScene = SceneManager::NowScene;
		SceneManager::NowScene = SceneManager::NextScene;
	}

	DataManager::SceneTable[static_cast<int>(SceneManager::NextScene)]->Draw();

	// デバッグ情報を画面に上書き
	if (SceneManager::ShowDebugInfo) {
		SceneManager::DebugInfoOverLay();
	}
}

void SceneManager::DebugInfoOverLay() {
	
	int Cr;
	int _x, _y, bit;
	int log_y;
	int gcd;
	char FpsStr[64];

	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::FPS)], "FPS:%d",Fps::fpsAve);

	wsprintf(FpsStr, "");
	for (auto f : Fps::fpsAveQueue) {
		wsprintf(FpsStr, "%s %d", FpsStr, f);
	}
	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::FPS_BUFF)], "10SEC FPS BUFF:%s", FpsStr);

	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::FRAME_COUNT)], "FrameCount:%d", Fps::count);

	GetScreenState(&_x, &_y, &bit);
	gcd = std::gcd(_x, _y);
	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::WINDOW_SIZE)], "Window Size:%d x %d (%d:%d)", _x, _y, _x / gcd, _y / gcd);

	log_y = 0;
	Cr = GetColor(0, 255, 0);
	for (auto c : SceneManager::DebugLog) {
		DrawString(5, log_y, c, Cr);
		log_y += 16;
	}

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

static int MakeBackScreenCream(void) {
	int gh;
	int x, y, bit;
	int cr_pink = GetColor(255, 200, 255);
	int cr_cream = GetColor(255, 255, 200);

	GetScreenState(&x, &y, &bit);

	gh = MakeScreen(x, y);

	// 描画先変更
	SetDrawScreen(gh);

	DrawBox(0, 0, x, y, cr_cream,true);

	// 描画先を裏画面に戻す
	SetDrawScreen(DX_SCREEN_BACK);

	return gh;
}