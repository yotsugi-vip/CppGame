#include "SceneManager.h"
#include "SceneDebug.h"
#include "SceneTitle.h"

E_Scene SceneManager::NowScene = E_Scene::Scene_Title;

void SceneManager::Draw() {
	switch (SceneManager::NowScene)
	{
	case E_Scene::Scene_Title:
		DrawTitle();
		break;

	case E_Scene::Scene_Menu:
		break;

	case E_Scene::Scene_Debug:
		DrawDebugInfo();
	default:
		break;
	}
}