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

static const char* Menu_1 = "Arcade";
static const char* Menu_2 = "Practice";
static const char* Menu_3 = "Config";
static const char* Menu_4 = "Exit";
static const char* Menu_5 = "Debug Mode";


enum class Fonts {
	Menu = 0,
	Menu_Selected,
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

enum class Graph {
	Title = 0,
	Mode_Easy,
	Mode_Normal,
	Mode_Hard,
	MAX
};

enum class Sound_SE {
	Select = 0,
	Confirm,
	Cancel,
	MAX
};

enum class Sound_Music {
	Title = 0,
	MAX
};

enum class TextBox_Sprite {
	UP_LEFT = 0,
	UP_CENTER,
	UP_RIGHT,
	MIDDLE_LEFT,
	MIDDLE_CENTER,
	MIDDLE_RIGHT,
	DOWN_LEFT,
	DOWN_CENTER,
	DOWN_RIGHT,
	MAX
};

enum class TextBox_Color {
	BLACK = 0,
	GRAY,
	PINK,
	MAX
};

class DataManager
{
public:
	static SceneBase* SceneTable[];
	static EventBase* EventTable[];
	static Task* TaskTable[];
	static int FontTable[static_cast<int>(Fonts::MAX)];
	static int CaractorImg[static_cast<int>(Caractor::MAX)];
	static int GraphTable[static_cast<int>(Graph::MAX)];
	static int SoundSE[static_cast<int>(Sound_SE::MAX)];
	static int SoundMusic[static_cast<int>(Sound_Music::MAX)];
	static int TextBoxSprite[static_cast<int>(TextBox_Color::MAX)][static_cast<int>(TextBox_Sprite::MAX)];

public:
	static SceneInit sceneInit;
	static SceneTitle sceneTitle;
	static SceneMenu sceneMenu;
	static SceneDebugInfo sceneDebugInfo;
	static SceneGame sceneGame;
	static SceneSelectMode sceneSelectMode;
	static TransTitleToMenu transTitleToMenu;
};