#pragma once

#include <stdafx.h>
#include <irrKlang.h>

struct SoundData
{
	irrklang::ISoundSource* soundSource;
	
	QString type = "";
	QString page = "";
	QString button = "";
	bool ex_global_track;

	float delay;
	bool loop;
	bool sync;
	float fade;

	QString name;
};