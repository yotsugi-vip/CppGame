#include "DataManager.h"

SceneInit DataManager::sceneInit;
SceneTitle DataManager::sceneTitle;
SceneMenu DataManager::sceneMenu;
SceneDebugInfo DataManager::sceneDebugInfo;
SceneGame DataManager::sceneGame;
SceneSelectMode DataManager::sceneSelectMode;

SceneBase* DataManager::SceneTable[] = {
	&sceneInit,
	&sceneTitle,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo
};

EventBase* DataManager::EventTable[] = {
	&sceneInit,
	&sceneTitle,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo
};

int DataManager::FontTable[static_cast<int>(Fonts::MAX)] = { 0 };
int DataManager::CaractorImg[static_cast<int>(Caractor::MAX)] = { 0 };