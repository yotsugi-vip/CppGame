#include "DataManager.h"

SceneInit DataManager::sceneInit;
SceneTitle DataManager::sceneTitle;
SceneMenu DataManager::sceneMenu;
SceneDebugInfo DataManager::sceneDebugInfo;
SceneGame DataManager::sceneGame;
SceneSelectMode DataManager::sceneSelectMode;
TransTitleToMenu DataManager::transTitleToMenu;
SceneConfig DataManager::sceneConfig;

SceneBase* DataManager::SceneTable[] = {
	&sceneInit,
	&sceneTitle,
	&transTitleToMenu,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo,
	&sceneConfig
};

EventBase* DataManager::EventTable[] = {
	&sceneInit,
	&sceneTitle,
	&transTitleToMenu,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo,
	&sceneConfig
};

Task* DataManager::TaskTable[] = {
	&sceneInit,
	&sceneTitle,
	&transTitleToMenu,
	&sceneMenu,
	&sceneSelectMode,
	&sceneGame,
	&sceneDebugInfo,
	&sceneConfig
};

int DataManager::FontTable[static_cast<int>(Fonts::MAX)] = { 0 };
int DataManager::CaractorImg[static_cast<int>(Caractor::MAX)] = { 0 };
int DataManager::SoundSE[static_cast<int>(Sound_SE::MAX)] = { 0 };
int DataManager::SoundMusic[static_cast<int>(Sound_Music::MAX)] = { 0 };
int DataManager::GraphTable[static_cast<int>(Graph::MAX)] = { 0 };
int DataManager::TextBoxSprite[static_cast<int>(TextBox_Color::MAX)][static_cast<int>(TextBox_Sprite::MAX)] = { 0 };