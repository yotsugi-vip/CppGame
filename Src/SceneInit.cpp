#include "SceneInit.h"
#include "DataManager.h"
#include <DxLib.h>

void SceneInit::Initialize() {
	DataManager::FontTable[static_cast<int>(Fonts::Menu)] = CreateFontToHandle("Menu", 15, 4);
}


void SceneInit::Draw() {}
void SceneInit::Update(){}

void SceneInit::End() {}

void SceneInit::Event_Push_Button(E_Button_Type button){}
void SceneInit::Event_Release_Button(E_Button_Type button){}
void SceneInit::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}