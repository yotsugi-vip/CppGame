#pragma once
#include "SceneManager.h"
#include "SceneDebug.h"
#include "SceneTitle.h"
#include "SceneBase.h"
#include "SceneMenu.h"
#include "SceneGame.h"
#include "TransTitleToMenu.h"
#include "SceneSelectMode.h"
#include "SceneInit.h"
#include "Fps.h"
#include "Task.h"

enum class Fonts {
	Menu = 0,
	MAX
};

enum class Caractor {
	Img_1 = 0,
	Img_2,
	Img_3,
	Img_4,
	Img_5,
	Img_6,
	Img_7,
	Img_8,
	Img_9,
	Img_10,
	Img_11,
	Img_12,
	Img_13,
	Img_14,
	Img_15,
	Img_16,
	MAX
};

class DataManager
{
public:
	static SceneBase* SceneTable[];
	static EventBase* EventTable[];
	static Task* TaskTable[];
	static int FontTable[];
	static int CaractorImg[static_cast<int>(Caractor::MAX)];

public:
	static SceneInit sceneInit;
	static SceneTitle sceneTitle;
	static SceneMenu sceneMenu;
	static SceneDebugInfo sceneDebugInfo;
	static SceneGame sceneGame;
	static SceneSelectMode sceneSelectMode;
	static TransTitleToMenu transTitleToMenu;
};