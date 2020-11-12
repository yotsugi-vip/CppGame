#include "SceneDebug.h"
#include "Pad.h"
#include "Fps.h"
#include "main.h"
#include <DxLib.h>

int checkTenkey(int x, int y);
void drawTenKey(int x, int y, int wh, int nowkey);
void correctionInput(int* x, int* y);

static int x = 0;
static int y = 0;
static int bit = 0;


void SceneDebugInfo::Draw(void) {

    int Cr;
    int CorrectionR_X, CorrectionR_Y;
    int CorrectionL_X, CorrectionL_Y;
    int NowBox_R, NowBox_L;

    char String[64];
    int i = 0;
    int data[10] = { 0 };

    // 白色の値を取得
    Cr = GetColor(255, 255, 255);

    CorrectionR_X = Pad::R_Stick.X;
    CorrectionR_Y = Pad::R_Stick.Y;

    CorrectionL_X = Pad::L_Stick.X;
    CorrectionL_Y = Pad::L_Stick.Y;

    correctionInput(&CorrectionR_X, &CorrectionR_Y);
    correctionInput(&CorrectionL_X, &CorrectionL_Y);

    NowBox_R = checkTenkey(CorrectionR_X, CorrectionR_Y);
    NowBox_L = checkTenkey(CorrectionL_X, CorrectionL_Y);

    // 画面に入力状態を表示する
    {
        wsprintf(String, "%d x %d", x, y);
        DrawString(400, 0, String, Cr);

        wsprintf(String, "L_X : %d => %d", Pad::L_Stick.X, CorrectionL_X);
        DrawString(0, 0, String, Cr);

        wsprintf(String, "R_X : %d => %d", Pad::R_Stick.X, CorrectionR_X);
        DrawString(200, 0, String, Cr);


        wsprintf(String, "L_Y : %d => %d", Pad::L_Stick.Y, CorrectionL_Y);
        DrawString(0, 16, String, Cr);

        wsprintf(String, "R_Y : %d => %d", Pad::R_Stick.Y, CorrectionR_Y);
        DrawString(200, 16, String, Cr);


        wsprintf(String, "TEN_KEY_L: %d", NowBox_L + 1);
        DrawString(0, 32, String, Cr);

        wsprintf(String, "TEN_KEY_R: %d", NowBox_R + 1);
        DrawString(200, 32, String, Cr);


        for (auto num : Fps::fpsAveQueue) {
            data[i] = num;
            i++;
        }
        i = 0;

        wsprintf(String, "Fps Queue: %d %d %d %d %d %d %d %d %d %d",
            data[0], data[1], data[2], data[3], data[4],
            data[5], data[6], data[7], data[8], data[9]);
        DrawString(0, 48, String, Cr);

        wsprintf(String, "Fps Ave: %d", Fps::fpsAve);
        DrawString(0, 64, String, Cr);

        wsprintf(String, "Fps Count: %d", Fps::count);
        DrawString(128, 64, String, Cr);

        wsprintf(String, "base: %d -> processing: %d", Fps::base_time, Fps::processingTime);
        DrawString(0, 80, String, Cr);

        if (NowBox_L + 1 == 9) {
            WaitTimer(20);
            wsprintf(String, "Delay 20ms");
            DrawString(0, 96, String, Cr);
        }

        if (NowBox_L + 1 == 7) {
            WaitTimer(50);
            wsprintf(String, "Delay 50ms");
            DrawString(0, 96, String, Cr);
        }


        Cr = GetColor(0, 0, 255);    // 青色の値を取得


        drawTenKey(435, 265, 50, NowBox_R);

        // 円を描画
        DrawCircle(CorrectionR_X / 10 + 510, CorrectionR_Y / 10 + 340, 25, Cr, FALSE);

        drawTenKey(185, 265, 50, NowBox_L);

        // 円を描画
        DrawCircle(CorrectionL_X / 10 + 260, CorrectionL_Y / 10 + 340, 25, Cr, FALSE);
    }
}

void SceneDebugInfo::End(){}

void SceneDebugInfo::Update() {}

void SceneDebugInfo::Initialize(){
    GetScreenState(&x, &y, &bit);
}

int checkTenkey(int x, int y) {
    for (const auto& box : TEN_KEY) {
        if (box.x_start <= x && box.x_end >= x &&
            box.y_start <= y && box.y_end >= y) {
            return box.number;
        }
    }
    return TEN_KEY_5;
}

void drawTenKey(int x, int y, int wh, int nowkey) {

    // 白色の値を取得
    int Cr = GetColor(255, 255, 255);
    BOOL isFill[9] = { FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE , FALSE };
    isFill[nowkey] = TRUE;

    DrawBox(x + wh * 0, y + wh * 0, x + wh * 1 + 1, y + wh * 1 + 1, Cr, isFill[TEN_KEY_7]);
    DrawBox(x + wh * 1, y + wh * 0, x + wh * 2 + 1, y + wh * 1 + 1, Cr, isFill[TEN_KEY_8]);
    DrawBox(x + wh * 2, y + wh * 0, x + wh * 3 + 1, y + wh * 1 + 1, Cr, isFill[TEN_KEY_9]);

    DrawBox(x + wh * 0, y + wh * 1, x + wh * 1 + 1, y + wh * 2 + 1, Cr, isFill[TEN_KEY_4]);
    DrawBox(x + wh * 1, y + wh * 1, x + wh * 2 + 1, y + wh * 2 + 1, Cr, isFill[TEN_KEY_5]);
    DrawBox(x + wh * 2, y + wh * 1, x + wh * 3 + 1, y + wh * 2 + 1, Cr, isFill[TEN_KEY_6]);

    DrawBox(x + wh * 0, y + wh * 2, x + wh * 1 + 1, y + wh * 3 + 1, Cr, isFill[TEN_KEY_1]);
    DrawBox(x + wh * 1, y + wh * 2, x + wh * 2 + 1, y + wh * 3 + 1, Cr, isFill[TEN_KEY_2]);
    DrawBox(x + wh * 2, y + wh * 2, x + wh * 3 + 1, y + wh * 3 + 1, Cr, isFill[TEN_KEY_3]);
}

void correctionInput(int* x, int* y) {
    double f_x, f_y = 0;

    f_x = (double)(*x) * sqrt(2);
    f_y = (double)(*y) * sqrt(2);

    if (f_x > 0) {
        *x = f_x > 1000 ? 1000 : (int)f_x;
    }
    else {
        *x = f_x < -1000 ? -1000 : (int)f_x;
    }

    if (f_y > 0) {
        *y = f_y > 1000 ? 1000 : (int)f_y;
    }
    else {
        *y = f_y < -1000 ? -1000 : (int)f_y;
    }
}

void SceneDebugInfo::Event_Push_Button(E_Button_Type button) {}
void SceneDebugInfo::Event_Release_Button(E_Button_Type button) {}
void SceneDebugInfo::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {}