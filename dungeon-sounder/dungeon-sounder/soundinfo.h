#pragma once

#include "sound.h"

extern std::vector<Sound> sounds;

class SoundInfo
{
public:
	SoundInfo(QJsonObject& soundObject);

	Sound* sound;
	float volume;
	float delay;
	bool loop;
	bool sync;
	float fade;
};