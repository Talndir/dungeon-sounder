#pragma once

#include <QtWidgets/qpushbutton.h>
#include <vector>
#include "soundinfo.h"


class SoundButton : public QPushButton
{
	Q_OBJECT

public:
	SoundButton(QWidget *parent = Q_NULLPTR);
	void setup(QJsonObject& buttonObject, QString _pageName);

	bool exclusive_local;
	bool exclusive_global;
	QString pageName;
	std::vector<SoundInfo> sounds;
};
