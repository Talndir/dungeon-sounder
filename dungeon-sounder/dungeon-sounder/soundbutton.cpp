#include <stdafx.h>
#include <SoundButton.h>
#include "soundinfo.h"

SoundButton::SoundButton(QWidget* parent)
	: QPushButton(parent)
{

}

void SoundButton::setup(QJsonObject & buttonObject)
{
	this->setText(buttonObject["name"].toString());

	QString colour = buttonObject["colour"].toString();
	int r = colour.left(2).toUInt(nullptr, 16);
	int g = colour.mid(2, 2).toUInt(nullptr, 16);
	int b = colour.right(2).toUInt(nullptr, 16);
	QPalette pal = palette();
	pal.setColor(QPalette::Background, QColor(r, g, b));
	this->setAutoFillBackground(true);
	this->setPalette(pal);

	this->exclusive_local = buttonObject["exclusive_local"].toBool();
	this->exclusive_global = buttonObject["exclusive_global"].toBool();

	QJsonArray soundArray = buttonObject["sounds"].toArray();

	for (unsigned int i = 0; i < soundArray.size(); ++i)
		this->sounds.push_back(SoundInfo(soundArray[i].toObject()));
}
