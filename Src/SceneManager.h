#pragma once
#include "SceneBase.h"
// ‰æ–ÊƒTƒCƒY‚ð 1280 * 960 ‚ÅŒÅ’è
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 960;

constexpr int GAME_RANGE_WIDTH = WINDOW_WIDTH * 2 / 3;	// 853.3...
constexpr int GAME_RANGE_HEIGHT = WINDOW_HEIGHT - 20;	// 940
constexpr int GAME_RANGE_START_X = 10;
constexpr int GAME_RANGE_START_Y = 10;

enum class E_Debug_Log_OverLay {
	FPS = 0,
	FPS_BUFF,
	FRAME_COUNT,
	WINDOW_SIZE,
	PLAYER_COORDINATE,
	MAX = 60,
};

enum class E_Scene {
	Scene_Initialize = 0,
	Scene_Title,
	Scene_Menu,
	Scene_Select_Mode,
	Scene_Game,
	Scene_Debug
};

enum class E_Common_GraphHandle {
	GH_Stripe,
	GH_Cream,
	GH_MAX,
};

class SceneManager {
public:
	static bool ShowDebugInfo;
	static char DebugLog[static_cast<int>(E_Debug_Log_OverLay::MAX)][64];

public:
	static E_Scene NextScene;
	static E_Scene NowScene;
	static E_Scene PreScene;
	static bool QuitGame;
	static int GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_MAX)];

public:
	static void Initialize();
	static void GameProcess();
	static void DebugInfoOverLay();
};