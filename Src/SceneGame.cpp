#include "SceneGame.h"
#include "SceneManager.h"
#include "DataManager.h"
#include <DxLib.h>

static void Draw_BackGround();
static void DrawPlayer();
static void CheckPlayerCoordinate(T_Player_Info* info);

static int GraphHandle_joji = 0;

static T_Player_Info NowInfo_P = { 180,400,0 };
static T_Player_Info PreInfo_P = NowInfo_P;

void SceneGame::Initialize() {
	
	GraphHandle_joji = LoadGraph("asset\\joji_shadow.png");

	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_DOWN_SCALE, 2);
	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_HSB, 0, 0, 0, 200);

	LoadDivGraph("asset\\p.png", static_cast<int>(Caractor::MAX), 4, 4, 64, 64, DataManager::CaractorImg);
}

void SceneGame::Draw() {
	
	Draw_BackGround();

	DrawBox(GAME_RANGE_START_X, GAME_RANGE_START_Y, GAME_RANGE_WIDTH, GAME_RANGE_HEIGHT, GetColor(0, 0, 0), true);

	DrawPlayer();
}


void SceneGame::End() {

}

void Draw_BackGround() {
	DrawGraph(0, 0, SceneManager::GraphHandles[static_cast<int>(E_Common_GraphHandle::GH_Stripe)], false);
	DrawGraph(370, 140, GraphHandle_joji, true);
}

void SceneGame::Event_Push_Button(E_Button_Type button) {}
void SceneGame::Event_Release_Button(E_Button_Type button) {}
void SceneGame::Event_Keep_Button(E_Button_Type button, E_Button_State onoff) {
	switch (button)
	{
	case E_Button_Type::Left:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.x -= 3;
		}
		break;
	case E_Button_Type::Right:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.x += 3;
		}
		break;
	case E_Button_Type::Up:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.y -= 3;
		}
		break;
	case E_Button_Type::Down:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.y += 3;
		}
		break;

	default:
		break;
	}
}

void DrawPlayer() {
	int drawHandle = 0;
	int frame = NowInfo_P.Frame / 10;

	if (NowInfo_P.x == PreInfo_P.x) {

		switch (frame) {
		case 0:
			drawHandle = DataManager::CaractorImg[0];
			break;
		case 1:
			drawHandle = DataManager::CaractorImg[4];
			break;
		case 2:
			drawHandle = DataManager::CaractorImg[8];
			break;
		default:
			drawHandle = DataManager::CaractorImg[0];
			break;
		}
	}
	else {
		if (NowInfo_P.x > PreInfo_P.x) {
			// �E�����Ɉړ�
			switch (frame)
			{
			case 0:
				drawHandle = DataManager::CaractorImg[1];
				break;
			case 1:
				drawHandle = DataManager::CaractorImg[5];
				break;
			case 2:
				drawHandle = DataManager::CaractorImg[9];
				break;
			default:
				drawHandle = DataManager::CaractorImg[1];
				break;
			}
		}
		else {
			// �������Ɉړ�
			switch (frame) {
			case 0:
				drawHandle = DataManager::CaractorImg[2];
				break;
			case 1:
				drawHandle = DataManager::CaractorImg[6];
				break;
			case 2:
				drawHandle = DataManager::CaractorImg[10];
				break;
			default:
				drawHandle = DataManager::CaractorImg[2];
				break;
			}
		}
	}

	// ���͍��W�͈͊m�F
	CheckPlayerCoordinate(&NowInfo_P);

	DrawBox(NowInfo_P.x, NowInfo_P.y, NowInfo_P.x + 96, NowInfo_P.y + 96, GetColor(100, 100, 100), true);
	
	//DrawGraph(NowInfo_P.x, NowInfo_P.y, drawHandle, true);
	DrawExtendGraph(NowInfo_P.x, NowInfo_P.y, NowInfo_P.x + 96, NowInfo_P.y + 96, drawHandle, true);

	PreInfo_P = NowInfo_P;

	if (NowInfo_P.Frame > 30) {
		NowInfo_P.Frame = 0;
	}
	else {
		NowInfo_P.Frame++;
	}

	// �f�o�b�O���O��������
	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::PLAYER_COORDINATE)], "PLAYER COORDINATE X:%d Y:%d", NowInfo_P.x, NowInfo_P.y);
}

void CheckPlayerCoordinate( T_Player_Info *info) {
	//64 * 64
	if (info->x < GAME_RANGE_START_X - 16) {
		info->x = GAME_RANGE_START_X - 16;
	}

	if (info->x > GAME_RANGE_WIDTH - 48) {
		info->x = GAME_RANGE_WIDTH - 48;
	}

	if (info->y < GAME_RANGE_START_Y) {
		info->y = GAME_RANGE_START_Y;
	}

	if (info->y > GAME_RANGE_HEIGHT - 64) {
		info->y = GAME_RANGE_HEIGHT - 64;
	}
}