#pragma once

#include <stdafx.h>
#include <irrKlang.h>

struct SoundData
{
	irrklang::ISoundSource* soundSource;
	
	QString name;
	QString type;
	QString page;
	QString button;

	bool ex_type_track;
	bool ex_global_track;
	bool ex_local_button;
	bool ex_global_button;

	float delay;
	bool loop;
	bool sync;
	float fade;

	bool marked = false;
};