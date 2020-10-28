#pragma once

enum class E_Scene {
	Scene_Title = 0,
	Scene_Menu,
	Scene_Debug = 0xFF
};

class SceneManager
{
public:
	static E_Scene NowScene;

public:
	static void Draw();
};

