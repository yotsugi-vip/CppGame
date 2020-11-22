#include "SceneTitle.h"
#include "SceneManager.h"
#include "Pad.h"
#include "Sound.h"
#include "DataManager.h"
#include <DxLib.h>

#include "Component.h"

static const char* PushToStartWord = "push to start";

static int FontHandle_PushToStart = -1;
static int Width_PTS = -1;

void SceneTitle::Initialize(void) {
        FontHandle_PushToStart = CreateFontToHandle("PUSH_TO_START", 20, 6);

        Width_PTS = GetDrawStringWidthToHandle(PushToStartWord, strlen(PushToStartWord), FontHandle_PushToStart);

        Sound::SetBgmRatio(50);
        Sound::SetSeRatio(50);
        Sound::BGM_Title();
}

void SceneTitle::Draw(void) {
    int Cr;
    int X, Y, Bit;
    int Gx, Gy;

    // 現在の画面サイズ取得
    GetScreenState(&X, &Y, &Bit);
    DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

    Cr = GetColor(0, 0, 0);

    GetGraphSize(DataManager::GraphTable[static_cast<int>(Graph::Title)], &Gx, &Gy);
    DrawGraph(X / 2 - Gx / 2, Y / 3 - Gy / 2, DataManager::GraphTable[static_cast<int>(Graph::Title)], true);
    DrawStringToHandle((X - Width_PTS) / 2, Y / 2 + 20, "push to start", Cr, FontHandle_PushToStart);
}

void SceneTitle::Update(void) {

}


void SceneTitle::End(void) {

    // フォントデータを破棄
    DeleteFontToHandle(FontHandle_PushToStart);
}

void SceneTitle::Event_Push_Button(E_Button_Type button) {
    SceneManager::NextScene = E_Scene::Trans_Titile_To_Menu;
}

void SceneTitle::Event_Release_Button(E_Button_Type button){}

void SceneTitle::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}