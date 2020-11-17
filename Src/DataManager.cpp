#include "DataManager.h"

SceneInit DataManager::sceneInit;
SceneTitle DataManager::sceneTitle;
SceneMenu DataManager::sceneMenu;
SceneDebugInfo DataManager::sceneDebugInfo;
SceneGame DataManager::sceneGame;
SceneSelectMode DataManager::sceneSelectMode;
TransTitleToMenu DataManager::transTitleToMenu;

SceneBase* DataManager::SceneTable[] = {
	&sceneInit,
	&sceneTitle,
	&transTitleToMenu,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo
};

EventBase* DataManager::EventTable[] = {
	&sceneInit,
	&sceneTitle,
	&transTitleToMenu,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo
};

Task* DataManager::TaskTable[] = {
	&sceneInit,
	&sceneTitle,
	&transTitleToMenu,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo
};

int DataManager::FontTable[static_cast<int>(Fonts::MAX)] = { 0 };
int DataManager::CaractorImg[static_cast<int>(Caractor::MAX)] = { 0 };
int DataManager::SoundSE[static_cast<int>(Sound_SE::MAX)] = { 0 };
int DataManager::SoundMusic[static_cast<int>(Sound_Music::MAX)] = { 0 };