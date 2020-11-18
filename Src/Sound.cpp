#include "Sound.h"
#include "DataManager.h"
#include <DxLib.h>

int	Sound::BGM_Ratio = 255;
int Sound::SE_Ratio = 255;

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
	if (SOUND_RATIO_MIN >= 0 && ratio < SOUND_RATIO_MAX) {
		for (const auto& m : DataManager::SoundMusic) {
			ChangeVolumeSoundMem(ratio, m);
		}
	}
}

void Sound::SetSeRatio(int ratio) {
	if (SOUND_RATIO_MIN >= 0 && ratio < SOUND_RATIO_MAX) {
		for (const auto& se : DataManager::SoundSE) {
			ChangeVolumeSoundMem(ratio, se);
		}
	}
}