#include "Player.h"
#include "Input.h"
#include "DataManager.h"
#include "SceneGame.h"
#include <DxLib.h>

Player::Player() {
	Player::Now.x = GAME_RANGE_START_X + (GAME_RANGE_WIDTH / 2 - 48);
	Player::Now.y = GAME_RANGE_START_Y + (GAME_RANGE_HEIGHT - 96 * 2);
	Player::Pre.x = 0;
	Player::Pre.y = 0;
	Player::HitBox.x = 0;
	Player::HitBox.y = 0;
	Player::Frame = 0;

	LoadDivGraph("asset\\p.png", static_cast<int>(Caractor::MAX), 4, 4, 64, 64, DataManager::CaractorImg);
}

Player::~Player() {

}

void Player::update() {

	// 前回情報保管
	Player::Pre = Player::Now;

	if (Input::now.Up == static_cast<int>(E_Button_State::Button_On)) {
		Player::Now.y -= 5;
	}

	if (Input::now.Down == static_cast<int>(E_Button_State::Button_On)) {
		Player::Now.y += 5;
	}

	if (Input::now.Left == static_cast<int>(E_Button_State::Button_On)) {
		Player::Now.x -= 5;
	}

	if (Input::now.Right == static_cast<int>(E_Button_State::Button_On)) {
		Player::Now.x += 5;
	}

	// ゲーム範囲外か確認
	Player::CheckPlayerCoordinate(&(Player::Now));

	// 当たり判定座標更新
	Player::HitBox.x = Player::Now.x + 48;
	Player::HitBox.y = Player::Pre.y + 48;
}

void Player::draw() {

	int drawHandle = 0;
	int frame = 0;

	frame = Player::Frame / 10;

	// 表示する画像ハンドルを取得
	if (Player::Now.x == Player::Pre.x) {
		switch (frame)
		{
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
	else if (Player::Now.y > Player::Pre.y) {
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
		switch (frame)
		{
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

	// アニメーションフレーム更新
	Player::Frame = Player::Frame > 30
		? 0
		: Player::Frame + 1;

	SetDrawMode(DX_DRAWMODE_BILINEAR);

	// プレイヤー画像を 96 * 96 で表示
	DrawExtendGraph((int)Player::Now.x, (int)Player::Pre.y, (int)Player::Now.x + 96, (int)Player::Now.y + 96, drawHandle, true);

	SetDrawMode(DX_DRAWMODE_NEAREST);

	// 当たり判定表示
	DrawCircleAA(Player::HitBox.x, Player::HitBox.y, 5.0, 32, GetColor(255, 255, 255), true);
	DrawCircleAA(Player::HitBox.x, Player::HitBox.y, 5.0, 32, GetColor(255, 0, 0), false);
	DrawCircleAA(Player::HitBox.x, Player::HitBox.y, 1.0, 32, GetColor(255, 0, 0), true);

	// デバッグログ書き込み
	wsprintf(SceneManager::DebugLog[static_cast<int>(E_Debug_Log_OverLay::PLAYER_COORDINATE)], "PLAYER COORDINATE X:%f Y:%f", Player::HitBox.x, Player::HitBox.y);
}

void Player::CheckPlayerCoordinate(T_Coordinate* info) {
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