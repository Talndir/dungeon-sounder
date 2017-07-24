#include "stdafx.h"
#include "soundinfo.h"

extern std::vector<Sound> sounds;

SoundInfo::SoundInfo(QJsonObject & soundObject)
{
	this->sound = nullptr;
	this->volume = soundObject["volume"].toDouble();
	this->delay = soundObject["delay"].toDouble();
	this->loop = soundObject["loop"].toBool();
	this->sync = soundObject["sync"].toBool();
	this->fade = soundObject["fade"].toDouble();

	for (unsigned int i = 0; (i < sounds.size()) && (this->sound == nullptr); ++i)
	{
		if (sounds.at(i).name == soundObject["sound"].toString())
			this->sound = &sounds.at(i);
	}
}
