#include "sound.h"

Sound::Sound(QJsonObject& soundObject)
{
	this->name = soundObject["name"].toString();
	this->volume = soundObject["volume"].toDouble();
	this->type = soundObject["type"].toString();
	this->exclusive_single = soundObject["exclusive_single"].toBool();
	this->exclusive_type = soundObject["exclusive_type"].toBool();
	this->exclusive_global = soundObject["exclusive_global"].toBool();

	QString p = soundObject["path"].toString();
	
	if (p[0] == '$')
		p = QString("/sounds").append(p.right(1));

	this->path = p;
}