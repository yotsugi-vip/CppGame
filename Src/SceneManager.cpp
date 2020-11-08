#include "SceneManager.h"
#include "DataManager.h"
#include "Fps.h"
#include <DxLib.h>
#include <numeric>

static int MakeBackScreenCream(void);
static int MakeStripeGraph(void);

E_Scene SceneManager::NowScene = E_Scene::Scene_Initialize;
E_Scene SceneManager::NextScene = E_Scene::Scene_Title;
E_Scene SceneManager::PreScene = E_Scene::Scene_Initialize;

int SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_MAX)] = { 0 };
bool SceneManager::ShowDebugInfo = true;
bool SceneManager::QuitGame = false;


void SceneManager::Initialize() {
	// �������������s��
	DataManager::SceneTable[static_cast<int>(E_Scene::Scene_Initialize)]->Initialize();
	
	// ���ʂŎg�p����O���t�B�b�N�f�[�^�̍쐬
	SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)] = MakeStripeGraph();
	SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Cream)] = MakeBackScreenCream();
}


void SceneManager::Draw() {

	// �V�[���̐؂�ւ�����
	if (SceneManager::NowScene != SceneManager::NextScene) {

		DataManager::SceneTable[static_cast<int>(SceneManager::NowScene)]->End();
		DataManager::SceneTable[static_cast<int>(SceneManager::NextScene)]->Initialize();

		SceneManager::PreScene = SceneManager::NowScene;
		SceneManager::NowScene = SceneManager::NextScene;
	}

	DataManager::SceneTable[static_cast<int>(SceneManager::NextScene)]->Draw();

	// �f�o�b�O������ʂɏ㏑��
	if (SceneManager::ShowDebugInfo) {
		SceneManager::DebugInfoOverLay();
	}
}

void SceneManager::DebugInfoOverLay() {
	
	int Cr;
	int x, y, bit;
	int gcd;
	char String[64];
	char FpsStr[64];

	Cr = GetColor(0, 255, 0);

	wsprintf(String, "FPS:%d",Fps::fpsAve);
	DrawString(0, 0, String, Cr);

	wsprintf(FpsStr, "");
	for (auto f : Fps::fpsAveQueue) {
		wsprintf(FpsStr, "%s %d", FpsStr, f);
	}
	wsprintf(String, "10SEC FPS BUFF:%s", FpsStr);
	DrawString(0, 16, String, Cr);

	wsprintf(String, "FrameCount:%d", Fps::count);
	DrawString(0, 32, String, Cr);

	GetScreenState(&x, &y, &bit);
	gcd = std::gcd(x, y);
	wsprintf(String, "Window Size:%d x %d (%d:%d)", x, y, x / gcd, y / gcd);
	DrawString(0, 48, String, Cr);
}

static int MakeStripeGraph(void) {
	int gh;
	int x, y, bit;
	int cr_pink = GetColor(255, 200, 255);
	int cr_cream = GetColor(255, 255, 200);

	GetScreenState(&x, &y, &bit);
	
	gh = MakeScreen(x, y);

	// �`���ύX
	SetDrawScreen(gh);

	// �X�g���C�v20�{
	for (int i = 0; i <= 20; i++) {
		if (i % 2 == 0) {
			DrawBox(x / 20 * (i - 1), 0, x / 20 * i, y, cr_pink, true);
		}
		else {
			DrawBox(x / 20 * (i - 1), 0, x / 20 * i, y, cr_cream, true);
		}
	}

	// �`���𗠉�ʂɖ߂�
	SetDrawScreen(DX_SCREEN_BACK);

	return gh;
}

static int MakeBackScreenCream(void) {
	int gh;
	int x, y, bit;
	int cr_pink = GetColor(255, 200, 255);
	int cr_cream = GetColor(255, 255, 200);

	GetScreenState(&x, &y, &bit);

	gh = MakeScreen(x, y);

	// �`���ύX
	SetDrawScreen(gh);

	DrawBox(0, 0, x, y, cr_cream,true);

	// �`���𗠉�ʂɖ߂�
	SetDrawScreen(DX_SCREEN_BACK);

	return gh;
}