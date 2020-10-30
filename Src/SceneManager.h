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

class SceneManager {
public:
	static E_Scene NowScene;
	static E_Scene PreScene;
	static bool ShowDebugInfo;

public:
	static void Draw();
	static void DebugInfoOverLay();
};

class SceneInit : public SceneBase {
	void Draw();
	void Initialize();
	void Input();
	void End();
};