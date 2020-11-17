#include "SceneInit.h"
#include "DataManager.h"
#include <DxLib.h>

void SceneInit::Initialize() {
	DataManager::FontTable[static_cast<int>(Fonts::Menu)] = CreateFontToHandle("0", 64, 4);
	DataManager::FontTable[static_cast<int>(Fonts::Menu_Selected)] = CreateFontToHandle("1", 72, 4, DX_FONTTYPE_EDGE, -1, 2);
	DataManager::SoundMusic[static_cast<int>(Sound_Music::Title)] = LoadSoundMem("asset\\bgm_maoudamashii_8bit24.ogg");
	DataManager::SoundSE[static_cast<int>(Sound_SE::Select)] = LoadSoundMem("asset\\se_maoudamashii_system21.ogg");
	DataManager::SoundSE[static_cast<int>(Sound_SE::Confirm)] = LoadSoundMem("asset\\se_maoudamashii_system48.ogg");
}


void SceneInit::Draw() {}
void SceneInit::Update(){}

void SceneInit::End() {}

void SceneInit::Event_Push_Button(E_Button_Type button){}
void SceneInit::Event_Release_Button(E_Button_Type button){}
void SceneInit::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}