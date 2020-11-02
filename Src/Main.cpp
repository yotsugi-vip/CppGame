#include "DxLib.h"
#include "main.h"
#include "Fps.h"
#include "SceneManager.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    //Window���[�h�ɕύX
    ChangeWindowMode(TRUE);

    // �c�w���C�u��������������
    if (DxLib_Init() == -1) {
        return -1;
    }

    // �`����ʂ𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    // �V�[���Ǘ�����������
    SceneManager::Initialize();

    // ���C�����[�v
    while (!SceneManager::QuitGame) {

        // ���b�Z�[�W����
        if (ProcessMessage() == -1) {
            break;    // �G���[�����������烋�[�v�𔲂���
        }

        // �`�揉����
        ClearDrawScreen();

        // ���͏��擾
        Input::Input_Main();

        // �`�揈��
        SceneManager::Draw();

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

        // FPS�v�Z�A�ҋ@
        Fps::Wait();
    }

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;        // �\�t�g�̏I��
}


