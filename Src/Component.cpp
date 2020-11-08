#include "Component.h"
#include "DataManager.h"
#include <DxLib.h>

void Button::Draw() {
	unsigned int Cr = GetColor(0, 0, 0);

	// ƒƒjƒ…[•`‰æ
	DrawBox(Button::X_start, Button::Y_start, Button::X_end, Button::Y_end, GetColor(0, 0, 0), Button::isSelected);
	DrawStringToHandle(Button::X_start + 3, Button::Y_start + 1, Button::String, Cr, DataManager::FontTable[static_cast<int>(Fonts::Menu)]);
}