#include "DxLib.h"
#include "main.h"
#include "Fps.h"
#include "SceneManager.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    //Windowモードに変更
    ChangeWindowMode(TRUE);

    // 画面サイズを 1280 * 960 で固定
    if (SetGraphMode(1280, 960, 32) == -1) {
        return -1;
    }

    // ＤＸライブラリ初期化処理
    if (DxLib_Init() == -1) {
        return -1;
    } 

    // 描画先画面を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    // シーン管理初期化処理
    SceneManager::Initialize();

    // メインループ
    while (!SceneManager::QuitGame) {

        // メッセージ処理
        if (ProcessMessage() == -1) {
            break;    // エラーが発生したらループを抜ける
        }

        // 描画初期化
        ClearDrawScreen();

        // 入力情報取得
        Input::Input_Main();

        // 全体処理
        SceneManager::GameProcess();

        // 裏画面の内容を表画面に反映させる
        ScreenFlip();

        // FPS計算、待機
        Fps::Wait();
    }

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}


