#pragma once

#include "sound.h"

struct SoundInfo
{
	Sound& sound;
	float volume;
	float delay;
	bool loop;
	bool sync;
	float fade;
};