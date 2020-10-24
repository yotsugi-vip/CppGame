#include "DxLib.h"
#include "main.h"
#include <math.h>

int checkTenkey(int x, int y);
void drawTenKey(int x, int y, int wh, int nowkey);
void correctionInput(int* x, int* y);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int Cr;
    int InputX, InputY;
    int CorrectionX, CorrectionY;
    int NowBox;

    char String[64];

    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }

    // 描画先画面を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    // 白色の値を取得
    Cr = GetColor(255, 255, 255);

    // ＥＳＣキーが押されるまでループ
    while ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_9) == 0)
    {
        // メッセージ処理
        if (ProcessMessage() == -1)
        {
            break;    // エラーが発生したらループを抜ける
        }

        // パッド１の入力を取得
        GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
        CorrectionX = InputX;
        CorrectionY = InputY;
        correctionInput(&CorrectionX, &CorrectionY);

        NowBox = checkTenkey(CorrectionX, CorrectionY);

        // 画面に入力状態を表示する
        {
            ClearDrawScreen();

            wsprintf(String, "X = %d => %d", InputX, CorrectionX);
            DrawString(0, 0, String, Cr);

            wsprintf(String, "Y = %d => %d", InputY, CorrectionY);
            DrawString(0, 16, String, Cr);

            wsprintf(String, "TEN_KEY: %d", NowBox+1);
            DrawString(0, 32, String, Cr);


            Cr = GetColor(0, 0, 255);    // 青色の値を取得


            drawTenKey(60, 80, 50, NowBox);

            // 円を描画
            DrawCircle(CorrectionX/10+360, CorrectionY/10+240, 50, Cr, FALSE);
        }

        // 裏画面の内容を表画面に反映させる
        ScreenFlip();
    }

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
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