#pragma once
#include "SceneManager.h"
#include "SceneDebug.h"
#include "SceneTitle.h"
#include "SceneBase.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "SceneSelectMode.h"
#include "SceneInit.h"
#include "Fps.h"

class DataManager
{
public:
	static SceneBase* SceneTable[];
	static EventBase* EventTable[];

public:
	static SceneInit sceneInit;
	static SceneTitle sceneTitle;
	static SceneMenu sceneMenu;
	static SceneDebugInfo sceneDebugInfo;
	static SceneGame sceneGame;
	static SceneSelectMode sceneSelectMode;
};