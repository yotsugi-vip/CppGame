#pragma once
constexpr int WIDTH_MIN = 640;
constexpr int HEIGHT_MIN = 480;
constexpr int WIDTH_MIDDLE = 1080;
constexpr int HEIGHT_MIDDLE = 720;
constexpr int WIDTH_MAX = 1920;
constexpr int HEIGHT_MAX = 1080;

constexpr int ANALOG_MAX = 1000;
constexpr int ANALOG_MIN = -1000;
constexpr int TENKEY_WIDTH = 666;
constexpr int TENKEY_HEIGHT = 666;


typedef struct {
	int number;
	int x_start;
	int x_end;
	int y_start;
	int y_end;
}T_Tenkey;

typedef enum {
	TEN_KEY_1,
	TEN_KEY_2,
	TEN_KEY_3,
	TEN_KEY_4,
	TEN_KEY_5,
	TEN_KEY_6,
	TEN_KEY_7,
	TEN_KEY_8,
	TEN_KEY_9,
}E_TENKEY_NUM;

constexpr T_Tenkey TEN_KEY[] = {
	{TEN_KEY_1, -1000, -999 + TENKEY_WIDTH,  333,  1000},
	{TEN_KEY_2, -333,  -333 + TENKEY_WIDTH,  333,  1000},
	{TEN_KEY_3,  333,  1000,				 333,  1000},

	{TEN_KEY_4, -1000, -999 + TENKEY_WIDTH, -333,  -333 + TENKEY_HEIGHT},
	{TEN_KEY_5, -333,  -333 + TENKEY_WIDTH, -333,  -333 + TENKEY_HEIGHT},
	{TEN_KEY_6,  333,  1000,				-333,  -333 + TENKEY_HEIGHT},

	{TEN_KEY_7, -1000, -999 + TENKEY_WIDTH, -1000, -1000 + TENKEY_HEIGHT},
	{TEN_KEY_8, -333,  -333 + TENKEY_WIDTH, -1000, -1000 + TENKEY_HEIGHT},
	{TEN_KEY_9,  333,  1000,				-1000, -1000 + TENKEY_HEIGHT},
};