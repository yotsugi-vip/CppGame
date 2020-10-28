#pragma once
#include "SceneBase.h"

enum class E_Scene {
	Scene_Initialize = 0,
	Scene_Title,
	Scene_Menu,
	Scene_Debug
};

class SceneManager {
public:
	static E_Scene NowScene;
	static E_Scene PreScene;

public:
	static void Draw();
};

class SceneInit : public SceneBase {
	void Draw();
	void Initialize();
	void Input();
	void End();
};

class SceneMenu : public SceneBase {
	void Draw();
	void Initialize();
	void Input();
	void End();
};