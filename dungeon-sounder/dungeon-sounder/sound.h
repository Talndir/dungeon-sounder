#pragma once

#include <stdafx.h>
#include <vector>

class Sound
{
public:
	Sound(QJsonObject& soundObject);

private:
	QString name;
	QString path;
	float volume;
	QString type;
	bool exclusive_single;
	bool exclusive_type;
	bool exclusive_global;
};