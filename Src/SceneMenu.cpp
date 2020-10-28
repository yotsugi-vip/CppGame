#include "SceneMenu.h"
#include "Pad.h"
#include <DxLib.h>

static const char* Menu_1 = "Menu 1";
static const char* Menu_2 = "Menu 2";
static const char* Menu_3 = "Menu 3";
static const char* Menu_4 = "Menu 4";
static const char* Menu_5 = "Debug Mode";
static int FontHandle_Menu = -1;

static int Selected = 0;


static Button button[5] = {
	{10, 200, 10, 30, Menu_1, false},
	{10, 200, 35, 55, Menu_2, false},
	{10, 200, 60, 80, Menu_3, false},
	{10, 200, 85, 105, Menu_4, false},
	{10, 200, 110, 130, Menu_5, false},
};

void SceneMenu::Initialize() {
	FontHandle_Menu = CreateFontToHandle("Menu", 15, 4);
}

void SceneMenu::Draw() {
	char String[64];

	for (auto b : button) {
		b.Draw();
	}
}

void SceneMenu::Input() {

	switch (Pad::D_Pad.Up)
	{
	case 0:
		Selected++;
		break;
	case 18000:
		Selected--;
		break;
	default:
		break;
	}

	if (Selected > 5) {
		Selected = 0;
	}

	if (Selected < 0) {
		Selected = 4;
	}
	
	for (int i = 0; i < 5; i++) {
		button[i].isSelected = (i == Selected ) ? true : false;
	}
}

void SceneMenu::End() {
	DeleteFontToHandle(FontHandle_Menu);
}

void Button::Draw() {
	unsigned int Cr = Button::isSelected ? GetColor(0, 0, 0) : GetColor(255, 255, 255);

	DrawBox(Button::X_start, Button::Y_start, Button::X_end, Button::Y_end, GetColor(255, 255, 255), Button::isSelected);
	DrawStringToHandle(Button::X_start+3, Button::Y_start+1, Button::String, Cr, FontHandle_Menu);
}