#include "SceneTitle.h"
#include "SceneManager.h"
#include "Pad.h"
#include <DxLib.h>

static const char* TitleWord = "T H I S   I S   T I T L E";
static const char* PushToStartWord = "push to start";

static int FontHandle_Title = -1;
static int FontHandle_PushToStart = -1;
static int Width_TITLE = -1;
static int Width_PTS = -1;


void SceneTitle::Initialize(void) {
        FontHandle_Title = CreateFontToHandle("TITLE", 40, 9);
        FontHandle_PushToStart = CreateFontToHandle("PUSH_TO_START", 20, 6);

        Width_TITLE = GetDrawStringWidthToHandle(TitleWord, strlen(TitleWord), FontHandle_Title);
        Width_PTS = GetDrawStringWidthToHandle(PushToStartWord, strlen(PushToStartWord), FontHandle_PushToStart);
}

void SceneTitle::Draw(void) {
    int Cr;
    int X, Y, Bit;

    // 現在の画面サイズ取得
    GetScreenState(&X, &Y, &Bit);
    DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)], true);

    Cr = GetColor(0, 0, 0);

    DrawStringToHandle((X - Width_TITLE) / 2, Y / 2 -50, "T H I S   I S   T I T L E", Cr, FontHandle_Title);
    DrawStringToHandle((X - Width_PTS) / 2, Y / 2 + 20, "push to start", Cr, FontHandle_PushToStart);
}

void SceneTitle::Update(void) {

}


void SceneTitle::End(void) {

    // フォントデータを破棄
    DeleteFontToHandle(FontHandle_Title);
    DeleteFontToHandle(FontHandle_PushToStart);
}

void SceneTitle::Event_Push_Button(E_Button_Type button) {
    SceneManager::NextScene = E_Scene::Scene_Menu;
}

void SceneTitle::Event_Release_Button(E_Button_Type button){}
void SceneTitle::Event_Keep_Button(E_Button_Type button, E_Button_State onoff){}