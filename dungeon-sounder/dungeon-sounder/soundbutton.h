#pragma once

#include <QtWidgets/qpushbutton.h>
#include <vector>
#include "soundinfo.h"

class SoundButton : public QPushButton
{
	Q_OBJECT

public:
	SoundButton(QWidget *parent = Q_NULLPTR);
	void setup(QJsonObject& buttonObject);

private:
	bool exclusive_local;
	bool exclusive_global;
	std::vector<SoundInfo> sounds;
};
