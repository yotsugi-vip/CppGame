#include "SceneSelectMode.h"
#include "SceneManager.h"
#include "Component.h"
#include <DxLib.h>


const char* BUTTON_LABEL_EASY = "easy";
const char* BUTTON_LABEL_NORMAL = "normal";
const char* BUTTON_LABEL_HARD = "hard";

const char* BUTTON_TEXT_EASY[] = { "","" };
const char* BUTTON_TEXT_NORMAL[] = { "","" };
const char* BUTTON_TEXT_HARD[] = { "","" };

Button button[] = {
	{},
	{},
	{}
};

void SceneSelectMode::Initialize() {

}

void SceneSelectMode::Draw() {
	// ”wŒi•`‰æ
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);


}

void SceneSelectMode::End() {

}

void SceneSelectMode::Event_Push_Button(E_Button_Type button) {}
void SceneSelectMode::Event_Release_Button(E_Button_Type button) {}
void SceneSelectMode::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {}