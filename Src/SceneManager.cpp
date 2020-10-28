#include "SceneManager.h"
#include "SceneDebug.h"
#include "SceneTitle.h"
#include "SceneBase.h"

E_Scene SceneManager::PreScene = E_Scene::Scene_Initialize;
E_Scene SceneManager::NowScene = E_Scene::Scene_Title;

SceneInit sceneInit;
SceneTitle sceneTitle;
SceneMenu sceneMenu;
SceneDebugInfo sceneDebugInfo;

SceneBase* SceneTable[] = {
	&sceneInit,
	&sceneTitle,
	&sceneMenu,
	&sceneDebugInfo
};

void SceneInit::Draw(){}
void SceneInit::End(){}
void SceneInit::Initialize(){}
void SceneInit::Input(){}

void SceneMenu::Draw() {}
void SceneMenu::End() {}
void SceneMenu::Initialize() {}
void SceneMenu::Input() {}

void SceneManager::Draw() {

	// ƒV[ƒ“‚ÌØ‚è‘Ö‚¦ˆ—
	if (SceneManager::PreScene != SceneManager::NowScene) {

		SceneTable[static_cast<int>(SceneManager::PreScene)]->End();
		SceneTable[static_cast<int>(SceneManager::NowScene)]->Initialize();
		SceneManager::PreScene = SceneManager::NowScene;
	}

	SceneTable[static_cast<int>(SceneManager::NowScene)]->Input();
	SceneTable[static_cast<int>(SceneManager::NowScene)]->Draw();
}