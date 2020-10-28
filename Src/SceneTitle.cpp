#include "SceneTitle.h"
#include <DxLib.h>

static const char* TitleWord = "T H I S   I S   T I T L E";
static const char* PushToStartWord = "push to start";

static int FontHandle_Title = -1;
static int FontHandle_PushToStart = -1;

static int Width_TITLE = -1;
static int Width_PTS = -1;

static int initFlag = -1;
static void TitleInit(void);
void TitleInit(void) {
    if (initFlag < 0) {
        initFlag = 0;

        FontHandle_Title = CreateFontToHandle("TITLE", 40, 9);
        FontHandle_PushToStart = CreateFontToHandle("PUSH_TO_START", 20, 6);

        Width_TITLE = GetDrawStringWidthToHandle(TitleWord, strlen(TitleWord), FontHandle_Title);
        Width_PTS = GetDrawStringWidthToHandle(PushToStartWord, strlen(PushToStartWord), FontHandle_PushToStart);
    }
}

void DrawTitle(void) {
    int Cr;
    int X, Y, Bit;

    TitleInit();

    // 現在の画面サイズ取得
    GetScreenState(&X, &Y, &Bit);

    // 白色の値を取得
    Cr = GetColor(255, 255, 255);

    DrawStringToHandle((X - Width_TITLE) / 2, Y / 2 -50, "T H I S   I S   T I T L E", Cr, FontHandle_Title);
    DrawStringToHandle((X - Width_PTS) / 2, Y / 2 + 20, "push to start", Cr, FontHandle_PushToStart);
}

void InputTitle(void) {

}