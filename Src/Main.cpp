#include "DxLib.h"
#include "main.h"
#include "Fps.h"
#include "Pad.h"
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //Windowモードに変更
    ChangeWindowMode(TRUE);

    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1)
    {
        return -1;
    }

    // 描画先画面を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    
    // ＥＳＣキーが押されるまでループ
    while ((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_9) == 0)
    {
        // メッセージ処理
        if (ProcessMessage() == -1)
        {
            break;    // エラーが発生したらループを抜ける
        }

        // 描画初期化
        ClearDrawScreen();

        // パッド１の入力を取得
        Pad::GetPadInput();

        // 描画処理
        SceneManager::Draw();

        // 裏画面の内容を表画面に反映させる
        ScreenFlip();

        // FPS計算、待機
        Fps::Wait();
    }

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}


