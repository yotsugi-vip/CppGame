#pragma once
#include "SceneBase.h"

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
	GH_Polka_Dots,
	GH_MAX,
};

class SceneManager {
public:
	static E_Scene NowScene;
	static E_Scene PreScene;
	static bool ShowDebugInfo;
	static bool QuitGame;
	static int GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_MAX)];

public:
	static void Initialize();
	static void Draw();
	static void DebugInfoOverLay();
};