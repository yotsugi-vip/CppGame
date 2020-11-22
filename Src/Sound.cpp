#include "Sound.h"
#include "DataManager.h"
#include <DxLib.h>

int	Sound::BGM_Ratio = 100;
int Sound::SE_Ratio = 100;

void Sound::SE_SelectMenu() {
	PlaySoundMem(DataManager::SoundSE[static_cast<int>(Sound_SE::Select)], DX_PLAYTYPE_BACK);
}

void Sound::SE_ConfirmMenu() {
	PlaySoundMem(DataManager::SoundSE[static_cast<int>(Sound_SE::Confirm)], DX_PLAYTYPE_BACK);
}

void Sound::SE_Cancel() {
	PlaySoundMem(DataManager::SoundSE[static_cast<int>(Sound_SE::Cancel)], DX_PLAYTYPE_BACK);
}

void Sound::BGM_Title() {
	if (!CheckSoundMem(DataManager::SoundMusic[static_cast<int>(Sound_Music::Title)])) {
		PlaySoundMem(DataManager::SoundMusic[static_cast<int>(Sound_Music::Title)], DX_PLAYTYPE_BACK);
	}
}

void Sound::SetBgmRatio(int ratio) {
	double val;

	if (ratio >= SOUND_RATIO_MIN && ratio <= SOUND_RATIO_MAX) {
		Sound::BGM_Ratio = ratio;
		val = (double)ratio * 255 / 100;

		for (const auto& m : DataManager::SoundMusic) {
			ChangeVolumeSoundMem((int)val, m);
		}
	}
}

void Sound::SetSeRatio(int ratio) {
	double val;

	if (ratio >= SOUND_RATIO_MIN && ratio <= SOUND_RATIO_MAX) {
		Sound::SE_Ratio = ratio;
		val = (double)ratio * 255 / 100;

		for (const auto& se : DataManager::SoundSE) {
			ChangeVolumeSoundMem((int)val, se);
		}
	}
}