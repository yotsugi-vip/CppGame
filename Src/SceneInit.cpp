#include "SceneInit.h"
#include "DataManager.h"
#include <DxLib.h>

void SceneInit::Initialize() {
	DataManager::FontTable[static_cast<int>(Fonts::Menu)] = CreateFontToHandle("Menu", 64, 4);
	DataManager::FontTable[static_cast<int>(Fonts::Menu_Selected)] = CreateFontToHandle("Menu_Selected", 72, 4, DX_FONTTYPE_EDGE, -1, 2);

	DataManager::SoundMusic[static_cast<int>(Sound_Music::Title)] = LoadSoundMem("asset\\bgm_maoudamashii_8bit24.ogg");

	DataManager::SoundSE[static_cast<int>(Sound_SE::Select)] = LoadSoundMem("asset\\se_maoudamashii_system21.ogg");
	DataManager::SoundSE[static_cast<int>(Sound_SE::Confirm)] = LoadSoundMem("asset\\se_maoudamashii_system48.ogg");
	DataManager::SoundSE[static_cast<int>(Sound_SE::Cancel)] = LoadSoundMem("asset\\se_maoudamashii_system45.ogg");

	DataManager::GraphTable[static_cast<int>(Graph::Title)] = LoadGraph("asset\\Title.png");

	LoadDivGraph("asset\\MENU.png", 3, 1, 3, 240, 48, &DataManager::GraphTable[static_cast<int>(Graph::Mode_Easy)]);

	LoadDivGraph("asset\\9Splite_pink.png", 9, 3, 3, 16, 16, DataManager::TextBoxSprite[static_cast<int>(TextBox_Color::PINK)]);
	LoadDivGraph("asset\\9Splite_gray.png", 9, 3, 3, 16, 16, DataManager::TextBoxSprite[static_cast<int>(TextBox_Color::GRAY)]);
	LoadDivGraph("asset\\9Splite_black.png", 9, 3, 3, 16, 16, DataManager::TextBoxSprite[static_cast<int>(TextBox_Color::BLACK)]);

	LoadDivGraph("asset\\Config.png", 4, 1, 4, 462, 64, &DataManager::GraphTable[static_cast<int>(Graph::Cnfig_SE)]);
	LoadDivGraph("asset\\Number.png", 13, 13, 1, 64, 64, &DataManager::GraphTable[static_cast<int>(Graph::Num_0)]);
}


void SceneInit::Draw() {}
void SceneInit::Update(){}

void SceneInit::End() {}

void SceneInit::Event_Push_Button(E_Button_Type button){}
void SceneInit::Event_Release_Button(E_Button_Type button){}
void SceneInit::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}