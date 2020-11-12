#include "DxLib.h"
#include "main.h"
#include "Fps.h"
#include "SceneManager.h"
#include "Input.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    //Window���[�h�ɕύX
    ChangeWindowMode(TRUE);

    // ��ʃT�C�Y�� 1280 * 960 �ŌŒ�
    if (SetGraphMode(1280, 960, 32) == -1) {
        return -1;
    }

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

        // �S�̏���
        SceneManager::GameProcess();

        // ����ʂ̓��e��\��ʂɔ��f������
        ScreenFlip();

        // FPS�v�Z�A�ҋ@
        Fps::Wait();
    }

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;        // �\�t�g�̏I��
}


