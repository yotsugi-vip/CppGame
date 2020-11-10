#include "SceneGame.h"
#include "SceneManager.h"
#include "DataManager.h"
#include <DxLib.h>

static void Draw_BackGround();
static void DrawPlayer();
static void CheckPlayerCoordinate(T_Player_Info* info);
static void CalcPlayerHitCircle(int x, int y, int* hit_x, int* hit_y);

static int GraphHandle_joji = 0;

static T_Player_Info NowInfo_P = { 0 };
static T_Player_Info PreInfo_P = { 0 };

void SceneGame::Initialize() {
	
	GraphHandle_joji = LoadGraph("asset\\joji_shadow.png");

	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_DOWN_SCALE, 2);
	GraphFilter(GraphHandle_joji, DX_GRAPH_FILTER_HSB, 0, 0, 0, 200);

	LoadDivGraph("asset\\p.png", static_cast<int>(Caractor::MAX), 4, 4, 64, 64, DataManager::CaractorImg);

	NowInfo_P.x = GAME_RANGE_START_X + (GAME_RANGE_WIDTH / 2 - 48);
	NowInfo_P.y = GAME_RANGE_START_Y + (GAME_RANGE_HEIGHT - 96 * 2);
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
			NowInfo_P.x -= 5;
		}
		break;
	case E_Button_Type::Right:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.x += 5;
		}
		break;
	case E_Button_Type::Up:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.y -= 5;
		}
		break;
	case E_Button_Type::Down:
		if (onoff == E_Button_State::Button_On) {
			NowInfo_P.y += 5;
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
			// 右方向に移動
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
			// 左方向に移動
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

	// 入力座標範囲確認
	CheckPlayerCoordinate(&NowInfo_P);

	// 中心座標計算
	CalcPlayerHitCircle(NowInfo_P.x, NowInfo_P.y, &NowInfo_P.HitCircle_x, &NowInfo_P.HitCircle_y);


	DrawBox(NowInfo_P.x, NowInfo_P.y, NowInfo_P.x + 96, NowInfo_P.y + 96, GetColor(100, 100, 100), true);
	DrawBox(NowInfo_P.x + 16, NowInfo_P.y, NowInfo_P.x + 80, NowInfo_P.y + 96, GetColor(100, 100, 100), true);
	DrawCircle(NowInfo_P.x, NowInfo_P.y, 3, GetColor(100, 0, 0), true);
	

	SetDrawMode(DX_DRAWMODE_BILINEAR);

	// プレイヤー画像を 96 * 96 で表示
	DrawExtendGraph(NowInfo_P.x, NowInfo_P.y, NowInfo_P.x + 96, NowInfo_P.y + 96, drawHandle, true);

	SetDrawMode(DX_DRAWMODE_NEAREST);

	// ヒットサークル表示
	DrawCircleAA((float)NowInfo_P.HitCircle_x, (float)NowInfo_P.HitCircle_y, 5.0, 32, GetColor(255, 255, 255), true);
	DrawCircleAA((float)NowInfo_P.HitCircle_x, (float)NowInfo_P.HitCircle_y, 5.0, 32, GetColor(255, 0, 0), false);
	DrawCircleAA((float)NowInfo_P.HitCircle_x, (float)NowInfo_P.HitCircle_y, 1.0, 32, GetColor(255, 0, 0), true);


	PreInfo_P = NowInfo_P;

	if (NowInfo_P.Frame > 30) {
		NowInfo_P.Frame = 0;
	}
	else {
		NowInfo_P.Frame++;
	}

	// デバッグログ書き込み
	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::PLAYER_COORDINATE)], "PLAYER COORDINATE X:%d Y:%d", NowInfo_P.HitCircle_x, NowInfo_P.HitCircle_y);
}

void CheckPlayerCoordinate( T_Player_Info *info) {
	//64 * 64 -> 96 * 96
	if (info->x < GAME_RANGE_START_X - 16) {
		info->x = GAME_RANGE_START_X - 16;
	}

	if (info->x > GAME_RANGE_WIDTH - 80) {
		info->x = GAME_RANGE_WIDTH - 80;
	}

	if (info->y < GAME_RANGE_START_Y) {
		info->y = GAME_RANGE_START_Y;
	}

	if (info->y > GAME_RANGE_HEIGHT - 96) {
		info->y = GAME_RANGE_HEIGHT - 96;
	}
}

void CalcPlayerHitCircle(int x, int y, int* hit_x, int* hit_y) {
	*hit_x = x + 48;
	*hit_y = y + 48;
}