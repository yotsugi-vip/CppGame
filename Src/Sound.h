#pragma once

constexpr int SOUND_RATIO_MAX = 255;
constexpr int SOUND_RATIO_MIN = 0;

class Sound
{
public:
	static int SE_Ratio;
	static void SE_SelectMenu();
	static void SE_ConfirmMenu();

public:
	static int BGM_Ratio;
	static void SetBgmRatio(int ratio);
	static void BGM_Title();
};

