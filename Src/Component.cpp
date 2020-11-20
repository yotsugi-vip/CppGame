#include "Component.h"
#include "DataManager.h"
#include <DxLib.h>

void Button::Draw() {
	unsigned int Cr = GetColor(0, 0, 0);

	// ÉÅÉjÉÖÅ[ï`âÊ
	DrawBox(Button::X_start, Button::Y_start, Button::X_end, Button::Y_end, GetColor(0, 0, 0), Button::isSelected);
	DrawStringToHandle(Button::X_start + 3, Button::Y_start + 1, Button::String, Cr, DataManager::FontTable[static_cast<int>(Fonts::Menu)]);
}

void Component::DrawTextBox(int x, int y, int x2, int y2,TextBox_Color color) { 
	
	// UP LEFT
	DrawGraph(x, y, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::UP_LEFT)], true);

	// UP CENTER
	DrawExtendGraph(x + 16, y, x2 - 16, y + 16, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::UP_CENTER)], true);

	// UP RIGHT
	DrawGraph(x2 - 16, y, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::UP_RIGHT)], true);

	// MIDDLE LEFT
	DrawExtendGraph(x, y + 16, x + 16, y2 - 16, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::MIDDLE_LEFT)], true);

	// MIDDLE CENTER
	DrawExtendGraph(x + 16, y + 16, x2 - 16, y2 -16, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::MIDDLE_CENTER)], true);

	// MIDDLE RIGHT
	DrawExtendGraph(x2 - 16, y + 16, x2, y2 - 16, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::MIDDLE_RIGHT)], true);

	// DOWN LEFT
	DrawGraph(x, y2 - 16, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::DOWN_LEFT)], true);

	// DOWN CENTER
	DrawExtendGraph(x + 16, y2 - 16, x2 - 16, y2, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::DOWN_CENTER)], true);

	// DOWN RIGHT
	DrawGraph(x2 - 16, y2 - 16, DataManager::TextBoxSprite[static_cast<int>(color)][static_cast<int>(TextBox_Sprite::DOWN_RIGHT)], true);
}