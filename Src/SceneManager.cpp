#include "SceneManager.h"
#include "SceneDebug.h"
#include "SceneTitle.h"
#include "SceneBase.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "SceneSelectMode.h"
#include "Fps.h";

#include<DxLib.h>

E_Scene SceneManager::PreScene = E_Scene::Scene_Initialize;
E_Scene SceneManager::NowScene = E_Scene::Scene_Title;
bool SceneManager::ShowDebugInfo = true;

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

void SceneInit::Draw(){}
void SceneInit::End(){}
void SceneInit::Initialize(){}
void SceneInit::Input(){}

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
}